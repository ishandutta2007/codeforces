#include<stdio.h>
using namespace std;
int a[9][9],b[9][9],vc[9],nr,min=1000,vl[9];
void fill(){
    int i,j;
    for(i=1;i<=8;i++){
        if(vc[i]==1){
            for(j=1;j<=8;j++)
                b[j][i]=1;
            nr++;
        }
        if(vl[i]==1){
            for(j=1;j<=8;j++)
                b[i][j]=1;
            nr++;
        }
    }
}
void empty(){
    int i,j;
    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++)
            b[i][j]=0;
}
int verif(){
    int i,j;
    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++)
            if(a[i][j]!=b[i][j])
                return 0;
    return 1;
}
void back2(int k){
    if(k==9){
        nr=0;
        fill();
        if(verif()==1&&nr<min)
            min=nr;
        empty();
    }
    else{
        back2(k+1);
        vl[k]=1;
        back2(k+1);
        vl[k]=0;
    }
}
void back1(int k){
    if(k!=9){
        back2(1);
        back1(k+1);
        vc[k]=1;
        back2(1);
        back1(k+1);
        vc[k]=0;
    }
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int i,j;
    char c;
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            scanf("%c",&c);
            if(c=='B')
                a[i][j]=1;
        }
        scanf("\n");
    }
    back1(1);
    printf("%d",min);
    return 0;
}