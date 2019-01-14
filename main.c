#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5

typedef struct tJeton{// positionnement du compteur dans le tableau
    int nX;
    int nY;
    int cpt;
}tJeton;


void initialiser(int MonTableau[TAILLE][TAILLE], tJeton *m_jeton);
void avancer(int MonTableau[TAILLE][TAILLE],tJeton *m_jeton);
void corriger(tJeton *m_jeton);
int recherche_vide(int MonTableau[TAILLE][TAILLE],tJeton m_jeton);
void placer(tJeton *m_jeton,int MonTableau[TAILLE][TAILLE]);
void afficher(int MonTableau[TAILLE][TAILLE], tJeton *m_jeton);



int main()
{
     int MonTableau [TAILLE][TAILLE];//creation du tableau
     tJeton m_jeton;

     initialiser(MonTableau,&m_jeton);// appel de la procedure initilisation du compteur et du placement du compteur

     avancer(MonTableau,&m_jeton);// avancement du compteur

     afficher(MonTableau,&m_jeton);

    return 0;
}


/*-----------------------------------
 Descriptions :Procedure d'initialisation du compteur
 Entrées :
 Sorties :
-----------------------------------*/
void initialiser(int MonTableau[TAILLE][TAILLE], tJeton *m_jeton){


    for(m_jeton->nX=0;m_jeton->nX<TAILLE;m_jeton->nX++){
        for(m_jeton->nY=0;m_jeton->nY<TAILLE;m_jeton->nY++){
                MonTableau[m_jeton->nX][m_jeton->nY]=0;
        }
    }

    m_jeton->nX = (TAILLE/2)-1;
    m_jeton->nY =(TAILLE/2);
    m_jeton->cpt = 1;

    MonTableau[m_jeton->nX][m_jeton->nY] = m_jeton->cpt;

}


/*-----------------------------------
 Descriptions :Procedure d'avancement du compteur (en haut a droite ou en haut a gauche)
 Entrées :
 Sorties :
-----------------------------------*/
avancer(int MonTableau[TAILLE][TAILLE],tJeton *m_jeton){


int total=1;

for (total=1;total<=24;total++){

    m_jeton->nX = (m_jeton->nX)-1;
    m_jeton->nY = (m_jeton->nY)+1;

                corriger(m_jeton);

                recherche_vide(MonTableau,*m_jeton);


                if (recherche_vide(MonTableau, *m_jeton) != 1){
                    m_jeton->nX= m_jeton->nX - 1;
                    m_jeton->nY= m_jeton->nY - 1;
                    corriger(m_jeton);
                }

                m_jeton->cpt = (m_jeton->cpt) + 1;
                placer(m_jeton,MonTableau);
         }

    }

/*-----------------------------------
 Descriptions :Procedure de test de sortie du tableau
 Entrées :
 Sorties :
-----------------------------------*/
void corriger(tJeton *m_jeton){


    if(m_jeton->nX>=5){
        m_jeton->nX=0;
    }
    else if(m_jeton->nX<0){
        m_jeton->nX=4;
    }

    if(m_jeton->nY>=5){
        m_jeton->nY=0;
    }

    else if(m_jeton->nY<0){
        m_jeton->nY=4;
    }
}

/*-----------------------------------
 Descriptions :Procedure de test est ce que la case est vide ou non
 Entrées :
 Sorties :
-----------------------------------*/
int recherche_vide(int MonTableau[TAILLE][TAILLE],tJeton m_jeton){

    if (MonTableau[m_jeton.nX][m_jeton.nY] == 0){
        return 1;
    }
    return 0;
}
/*-----------------------------------
 Descriptions :Procedure de placement du numero dans le tableau
 Entrées :
 Sorties :
-----------------------------------*/
void placer(tJeton *m_jeton,int MonTableau[TAILLE][TAILLE]){

    MonTableau[m_jeton->nX][m_jeton->nY]=m_jeton->cpt;

}

/*-----------------------------------
 Descriptions :Procedure d'affichage du tableau
 Entrées :
 Sorties :
-----------------------------------*/

void afficher(int MonTableau[TAILLE][TAILLE], tJeton *m_jeton){
int nCpt=0;
int nCpt2=0;

    for(nCpt=0;nCpt<TAILLE;nCpt++){
        for(nCpt2=0;nCpt2<TAILLE;nCpt2++){
            printf("%d ",MonTableau[nCpt][nCpt2]);
        }
        printf("\n");
    }
}

