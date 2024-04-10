#include<bits/stdc++.h>
#pragma optimize(Ofast)
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 500005
LL dp[105][105][105];
LL C[105][105];
LL fra[105];
int mod;
void build(){
    for(int i =0;i<=100;i++){
        C[i][0]=C[i][i]=1;
        for(int j = 1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    fra[0]=1;
    for(int i = 1;i<=100;i++){
        fra[i]=fra[i-1]*i%mod;
    }  
}
LL DP(int x,int y,int k){
    if(dp[x][y][k]!=-1)return dp[x][y][k];
    if(x==0&&k==0)return 1;
    if(k*2-1>x)return 0;
    if(y<20&&k>(1ll<<(y-1)))return 0;
    if(x==0)return 0;
    if(y==1){
        if(k==1){
            return fra[x];
        }
        else{
        return 0;
        }
    }
    dp[x][y][k]=0;
    for(int i = 0;i<x;i++){
        int l=i,r=x-i-1;
        if(l<=r)
        for(int j =0;j<=k;j++){
            if(l==r)
            dp[x][y][k]+=DP(l,y-1,j)*DP(r,y-1,k-j)%mod*C[x-1][l]%mod;
            else{
                 dp[x][y][k]+=DP(l,y-1,j)*DP(r,y-1,k-j)%mod*C[x-1][l]*2%mod; 
            }
            dp[x][y][k]%=mod;
        }
        else{
            break;
        }
    }
   // printf("%d %d %d %d\n",x,y,k,dp[x][y][k]);
    return dp[x][y][k];
}
void solve(){
    int n,m,k;
    mod=1e9+7;
    scanf("%d %d %d %lld",&n,&m,&k,&mod);
    MEMS(dp);
    build();
    printf("%lld\n",DP(n,m,k));
}
int main(){

    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
7
34 38 10
8 32 9
3 7 10
5 13 9
23 40 5
28 34 1
24 26 10
*/