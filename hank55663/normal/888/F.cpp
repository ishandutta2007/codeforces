#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
LL g[505][505];
int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL dp[505][505][2];
LL DP(int l,int r,int op,int n){
    if(dp[l][r][op]!=-1)return dp[l][r][op];
    if((l+1)%n==r)return dp[l][r][op]=1;
    dp[l][r][op]=0;
    for(int i  =l+1;i!=r;i=(i+1)%n){
        if(g[l][i]){
            dp[l][r][op]+=DP(l,i,0,n)*DP(i,r,1,n)%mod;
        }
        if(g[r][i]&&!op){
            dp[l][r][op]+=DP(l,i,0,n)*DP(i,r,0,n)%mod;
        }
        dp[l][r][op]%=mod;
    }
  //  printf("%d %d %d %lld\n",l,r,op,dp[l][r][op]);
    return dp[l][r][op];
}
int main(){
    MEMS(dp);
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%lld",&g[i][j]);
        }
    }
    LL ans=0;
    for(int i = 1;i<n;i++){
        if(g[0][i]){
            if(i==n-1)
            ans+=DP(0,i,0,n);
            else
            ans+=DP(0,i,0,n)*DP(i,0,1,n)%mod;
            ans%=mod;
        }
    }
    printf("%lld\n",ans);
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/