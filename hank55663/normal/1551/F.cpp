#include<bits/stdc++.h>
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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[185];
vector<int> d[185];
int vis[185];
void dfs(int x,int f,int dep=0){
    vis[dep]++;
    for(auto it:v[x]){
        if(it!=f)
        dfs(it,x,dep+1);
    }
}
int C[105][105];
int mod=1e9+7;
void build(){
    for(int i = 0;i<105;i++){
        C[i][0]=C[i][i]=1;
        for(int j = 1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x=1,y=i+1;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    if(k==2){
        printf("%d\n",n*(n-1)/2);
    }
    else{
        LL ans=0;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=n;j++)d[j].clear();
            for(auto it:v[i]){
                MEM(vis);
                dfs(it,i);
                for(int j = 0;j<=n;j++){
                    if(vis[j])d[j].pb(vis[j]);
                }
            }
            for(int j = 0;j<=n;j++){
                LL dp[105];
                MEM(dp);
                dp[0]=1;
                for(auto it:d[j]){
                    for(int k = n;k>0;k--){
                        dp[k]+=dp[k-1]*it%mod;
                        dp[k]%=mod;
                    }
                }
                ans+=dp[k];
                ans%=mod;
            }
        }
        printf("%lld\n",ans);
    }
}
int main(){
    build();
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
*/