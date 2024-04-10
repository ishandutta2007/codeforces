#include<stdio.h>
using namespace std;
int a[101][101],vc[30];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,p,i,j,nr=0;
    char c;
    scanf("%d%d\n",&n,&m);
    scanf("%c\n",&c);
    p=c-'A'+1;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%c",&c);
            if(c!='.')
                a[i][j]=c-'A'+1;
        }
        scanf("\n");
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i][j]!=0&&a[i][j]!=p&&vc[a[i][j]]==0)
                if(a[i-1][j]==p||a[i+1][j]==p||a[i][j+1]==p||a[i][j-1]==p){
                    nr++;
                    vc[a[i][j]]=1;
                }
    printf("%d",nr);
    return 0;
}