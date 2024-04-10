#include<stdio.h>
using namespace std;
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,d,i,min=0,x;
    long long nr=0;
    scanf("%d%d",&n,&d);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        if(x>min)
            min=x;
        else{
            nr=nr+(min-x)/d+1;
            min=x+((min-x)/d+1)*d;
        }
    }
    printf("%I64d",nr);
    return 0;
}