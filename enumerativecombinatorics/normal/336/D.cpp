#include<stdio.h>
#include<algorithm>
using namespace std;
long long mod=1000000007;
long long inv[1000000];
long long fact[1000000];
long long factinv[1000000];
long long C(int a,int b){
//  printf("%d C ",a,b,fact[a]*factinv[b]%mod*factinv[a-b]%mod);
    return fact[a]*factinv[b]%mod*factinv[a-b]%mod;
}
int main(){
    int a,b,c;
    inv[1]=fact[0]=fact[1]=factinv[0]=factinv[1]=1;
    for(int i=2;i<1000000;i++){
        inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
        fact[i]=fact[i-1]*i%mod;
        factinv[i]=factinv[i-1]*inv[i]%mod;
    }
    scanf("%d%d%d",&a,&b,&c);
    if(b==0){
        printf("%d\n",c!=a%2);
        return 0;
    }
    long long ret=0;
    for(int i=0;i<=a;i++){
        if(b==1&&i==a){
            ret=(ret+(c!=a%2))%mod;
            continue;
        }
        if(i%2!=c)continue;
        ret=(ret+C(a+b-i-1,b-1))%mod;
    }
    printf("%d\n",(int)ret);
}