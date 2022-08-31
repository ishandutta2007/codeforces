#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
bool vis[maxn];
int deg[maxn],mx[maxn],dis[maxn],d[maxn],n,m;
vi G[maxn];
priority_queue<pi,vector<pi>,greater<pi> > Q;
void solve(){
    cin >> n >> m;   
    for (int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        G[v].pb(u); deg[u]++;
    }
    for (int i=1;i<n;i++) d[i]=deg[i],dis[i]=inf; dis[n]=0;
    Q.push((pi){dis[n],n});
    while (!Q.empty()){
        pi tmp=Q.top(); Q.pop();
        int u=tmp.S;
        if (vis[u]) continue; 
        vis[u]=1;
        for (auto v:G[u]){
            dis[v]=min(dis[v],dis[u]+d[v]); d[v]--;
            //mx[v]=max(mx[v],dis[u]);
            //d[v]--; if (!d[v]) dis[v]=min(dis[v],mx[v]+1);
            Q.push((pi){dis[v],v});
        }
    }
    cout << dis[1] << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _=1;
    while (_--) solve();
}