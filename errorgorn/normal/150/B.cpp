#include <cstdio>
using namespace std;
int a,b,c;
const int MOD=1000000007;
int main(){
    scanf("%d%d%d",&a,&b,&c);
    
    if (c==1 || a<c){
        long long ans=1;
        for (int x=0;x<a;x++) ans=(ans*b)%MOD;
        printf("%lld\n",ans);
    }
    else if (a==c){
        long long ans=1;
        for (int x=0;x<((a+1)>>1);x++) ans=(ans*b)%MOD;
        printf("%lld\n",ans);
    }
    else if (c%2==0){
        printf("%d\n",b);
    }
    else{
        printf("%lld\n",(b*(long long)b)%MOD);
    }
}