#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=1e6+10;
vector<int> G[maxn];
int _,n,dp[maxn],d[maxn],ans,tt;

int main(){
    cin >> _;
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) dp[i]=0,G[i].clear();
        for (int i=1;i<=n;i++){
            scanf("%d",&d[i]);
            for (int j=0;j<d[i];j++){
                int x; scanf("%d",&x);
                G[x].pb(i);
            }
        }
        queue <int> q; tt=0; ans=0;
        for (int i=1;i<=n;i++) if (!d[i]) q.push(i);
        while (!q.empty()){
            int u=q.front(); q.pop();
            tt++; ans=max(ans,dp[u]);
            for (auto v:G[u]){
                dp[v]=max(dp[v],dp[u]+(v<u));
                d[v]--;
                if (!d[v]) q.push(v);
            }
        }
        if (tt<n) puts("-1"); else printf("%d\n",ans+1);
    }
}