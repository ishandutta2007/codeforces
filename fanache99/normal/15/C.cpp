#include <stdio.h>
using namespace std;
long long op(long long n){
    if(n%4==0)
        return 0;
    if(n%4==1)
        return n-1;
    if(n%4==2)
        return 1;
    return n;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    long long n,i,s=0,x,m;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++){
        scanf("%I64d%I64d",&x,&m);
        s=s^op(x)^op(x+m);
    }
    if(s==0)
        printf("bolik");
    else
        printf("tolik");
    return 0;
}