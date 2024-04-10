#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=2e5+13;
const int inf=1e9;
vector <int> h[maxn];
int dis[maxn],d1[maxn],d2[maxn],n,m,k,ans,a[maxn],id[maxn],suf[maxn];
bool vis[maxn];
void Max(int &x,int y){
    if (y>x) x=y;
}
void bfs(int x){
    queue <int> q;
    q.push(x);dis[x]=0;
    while (!q.empty()){
        int u=q.front(); q.pop();
        for (auto v:h[u]){
            if (dis[v]!=-1) continue;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
}
bool cmp(int u,int v){
    if (d1[u]!=d1[v]) return d1[u]<d1[v];
    return d2[u]>d2[v];
}
int main(){
    cin >> n >> m >> k;
    for (int i=1;i<=k;i++) cin >> a[i];
    for (int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        h[u].pb(v); h[v].pb(u);
    }
    memset(dis,-1,sizeof(dis));
    dis[1]=0; bfs(1);
    for (int i=1;i<=n;i++) d1[i]=dis[i];
    memset(dis,-1,sizeof(dis));
    dis[n]=0; bfs(n);
    for (int i=1;i<=n;i++) d2[i]=dis[i];
    int ans=0;
    sort(a+1,a+k+1,cmp);
    int mx1=0,mx2=-inf;
    for (int i=1;i<=k;i++){
        int x=a[i];
        Max(mx1,mx2+d2[x]+1);
        Max(mx2,d1[x]);
    }
    cout << min(mx1,d1[n]) << endl;
    return 0;
}