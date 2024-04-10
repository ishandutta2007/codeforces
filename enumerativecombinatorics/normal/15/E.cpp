#include<stdio.h>
#include<algorithm>
using namespace std;
int mod=1000000009;
long long dp[1200000];
int main(){
    int a;
    scanf("%d",&a);
    dp[0]=4;
    for(int i=1;i<1000000;i++){
        dp[i]=(dp[i-1]+2)*2%mod;
    }
    long long ret=1;
    if(a%2){
        ret=(a-2)*2+1;
        a--;
    }
    while(a>2){
        ret=((ret+3)*(a>4?dp[(a-6)/2]+1:1)+1)%mod;
        a-=2;
    }
    printf("%d\n",(int)((((ret+1)*(ret+1)+1)*2)%mod));
}