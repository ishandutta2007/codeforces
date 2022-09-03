#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
int mod=998244353;
LL dp[5005][5005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    dp[0][0]=1;
    for(int i = 1;i<=k;i++){
        for(int j = 1;j<=i;j++){
            dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1]*(n-j+1))%mod;
        }
    }
    LL ans=0;
    for(int i = 1;i<=k;i++){
        ans+=dp[k][i]*f_pow(f_pow(m,i),mod-2)%mod;
    }
    printf("%lld\n",ans%mod);
}