#include <stdio.h>
using namespace std;
int a[51][51];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,i,j,lmin=100,cmin=100,lmax=-1,cmax=-1;
    char c;
    scanf("%d%d\n",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%c",&c);
            if(c=='*'){
                a[i][j]=1;
                if(i<lmin)
                    lmin=i;
                if(i>lmax)
                    lmax=i;
                if(j<cmin)
                    cmin=j;
                if(j>cmax)
                    cmax=j;
            }
        }
        scanf("\n");
    }
    for(i=lmin;i<=lmax;i++){
        for(j=cmin;j<=cmax;j++)
            if(a[i][j]==0)
                printf(".");
            else
                printf("*");
        printf("\n");
    }
    return 0;
}