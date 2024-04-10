#include<stdio.h>
#include<algorithm>
using namespace std;
long long mod=1000000007;
long long dp[52][1100];
long long C[2100][2100];
long long fact[2100];
int main(){
    C[0][0]=1;
    for(int i=0;i<2050;i++){
        for(int j=0;j<=i;j++){
            C[i+1][j]=(C[i+1][j]+C[i][j])%mod;
            C[i+1][j+1]=(C[i+1][j+1]+C[i][j])%mod;
        }
    }
    fact[0]=1;
    for(int i=1;i<2100;i++)fact[i]=fact[i-1]*i%mod;
    dp[0][0]=1;
    for(int i=0;i<=1000;i++){
        for(int j=49;j>=0;j--){
            for(int k=1000-i;k>=0;k--){
                dp[j+1][i+k]=(dp[j+1][i+k]+dp[j][k])%mod;
            }
        }
    }
    int a;scanf("%d",&a);
    while(a--){
        int p,q;scanf("%d%d",&p,&q);
        p-=q-1;
        if(q>50){
            printf("0\n");continue;
        }
        long long ret=0;
        for(int i=0;i<p;i++)ret=(ret+dp[q][i]*C[p-i-1+q][q])%mod;
        ret=ret*fact[q]%mod;
        printf("%d\n",(int)ret);
    }
}