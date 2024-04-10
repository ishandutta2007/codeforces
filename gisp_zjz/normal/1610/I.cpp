#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
const int maxn=1e6+10;
const int M=998244353;
vector<int> G[maxn];
int n,dp[maxn],f[maxn],pre[maxn];
bool ban[maxn];
void dfs(int u,int fa){
    pre[u]=fa;
    for (auto v:G[u]){
        if (v==fa) continue;
        dfs(v,u);
        dp[u]^=dp[v]+1;
    }
}
int main(){
    cin >> n;
    for (int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].pb(v); G[v].pb(u);
    }
    dfs(1,0);
    int cur=dp[1]; f[1]=cur; ban[1]=1;
    for (int i=2;i<=n;i++){
        if (ban[i]) {f[i]=cur;continue;}
        int tmp=i;
        while (1){
            cur^=1; ban[tmp]=1;
            for (auto x:G[tmp]){
                if (x==pre[tmp]) continue;
                if (!ban[x]) cur^=dp[x]+1;
            }
            if (ban[pre[tmp]]) break;
            tmp=pre[tmp];
        }
        cur^=dp[tmp]+1;
        f[i]=cur;
        //cout<<f[i]<<endl;
    }
    for (int i=1;i<=n;i++) if (f[i]) printf("1"); else printf("2"); puts("");
    return 0;
}