/**
 *    author:  gary
 *    created: 02.08.2022 08:58:39
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=3e3+20;
const int MOD=1e9+7;
int n,d,dp[MAXN][MAXN],comb[MAXN][MAXN],ans[MAXN];
vector<int> g[MAXN];
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
}
int inv(int A){return quick(A,MOD-2);}
int prod[MAXN];
void dfs(int now){
    for(auto it:g[now]) dfs(it);
    if(g[now].empty()){
        rb(i,1,n) dp[now][i]=1;
        return;
    }
    rb(i,1,n) prod[i]=1;
    for(auto it:g[now]){
        int sum=0;
        rb(j,1,n) sum+=dp[it][j],sum%=MOD,prod[j]=1ll*sum*prod[j]%MOD;
    }
    rb(i,1,n) dp[now][i]=prod[i];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>d;
    rb(i,2,n){
        int f;
        cin>>f;
        g[f].push_back(i);
    }
    dfs(1);
    rb(i,0,n) comb[i][0]=1;
    rb(i,1,n) rb(j,1,n) comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
    int sum=0;
    int com=1;
    int answer=0;
    rb(i,1,n){
        (sum+=dp[1][i])%=MOD;
        ans[i]=sum;
        rb(j,1,i-1){
            ans[i]-=1ll*ans[j]*comb[i][j]%MOD;
            if(ans[i]<0) ans[i]+=MOD;
        }
        com=1ll*com*(d-i+1)%MOD;
        com=1ll*com*inv(i)%MOD;
        // cout<<i<<" "<<ans[i]<<" "<<sum<<endl;
        answer+=1ll*ans[i]*com%MOD;
        answer%=MOD;
    }
    cout<<answer<<endl;
    return 0;
}