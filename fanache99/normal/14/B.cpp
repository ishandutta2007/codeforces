#include <stdio.h>
using namespace std;
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,p,i,a,b,x=-1,y=100000,aux;
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        if(a>b){
            aux=a;
            a=b;
            b=aux;
        }
        if(a>x)
            x=a;
        if(b<y)
            y=b;
    }
    if(x>y)
        printf("-1");
    else
        if(p>=x&&p<=y)
            printf("0");
        else
            if(p<x)
                printf("%d",x-p);
            else
                printf("%d",p-y);
    return 0;
}