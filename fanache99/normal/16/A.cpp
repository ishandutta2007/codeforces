#include <stdio.h>
using namespace std;
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,pp=0,aux=-1,i,j;
    char e,c;
    scanf("%d%d\n",&n,&m);
    for(i=1;i<=n&&pp==0;i++){
        scanf("%c",&e);
        for(j=2;j<=m&&pp==0;j++){
            scanf("%c",&c);
            if(c!=e)
                pp=1;
        }
        if(e==aux)
            pp=1;
        else
            aux=e;
        scanf("\n");
    }
    if(pp==0)
        printf("YES");
    else
        printf("NO");
    return 0;
}