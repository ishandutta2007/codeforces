#include<stdio.h>
#include<algorithm>
using namespace std;
long long inv[1000000];
long long mod=1000000007;
int main(){
    inv[1]=1;
    for(int i=2;i<1000000;i++){
        inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
    }
    int a;
    scanf("%d",&a);
    long long now=1;
    for(int i=0;i<a;i++){
        now=now*(2*a-1-i)%mod;
        now=now*inv[i+1]%mod;
    }
    printf("%I64d\n",(mod+now*2-a)%mod);
}