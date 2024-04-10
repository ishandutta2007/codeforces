#include<stdio.h>
#include<algorithm>
using namespace std;
int c[100010];
int mod=1000000007;
long long dp[2501][2501];
int S[2500];
long long inv[300000];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%d",c+i);
    }
    inv[1]=1;
    for(int i=2;i<300000;i++){
        inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
    }
    std::sort(c,c+a);
    int ind=0;
    int d=0;
    for(int i=0;i<a;i++){
        bool ok=true;
        int p=c[i];
        while(p){
            if(p%10!=4&&p%10!=7)ok=false;
            p/=10;
        }
        if(ok){
            if(i==0||c[i]!=c[i-1]){
                ind++;
                S[ind-1]++;
            }else{
                S[ind-1]++;
            }
        }else d++;
    }
    dp[0][0]=1;
    for(int i=0;i<ind;i++){
        for(int j=0;j<ind;j++){
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
            dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*S[i])%mod;
        }
    }
    long long ret=0;
    long long now=1;
    for(int i=0;i<=b;i++){
        ret=(ret+now*dp[ind][b-i]%mod)%mod;
        if(d==i)break;
        now=now*(d-i)%mod*inv[i+1]%mod;
    }
    printf("%I64d\n",ret);
}