#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const ll inf=1e15+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
int n,m,p,q;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
ll dis[maxn];
bool vis[maxn];
char s[maxn];
vector<char> a[maxn];
vector<pi> G[maxn];
void add_edge(int u,int v,int w){
    if (u==v) return;
    G[u].pb((pi){v,w});
}
int id(int x,int y){
    return x*m+y+1;
}
void init(){
    for (int i=1;i<=n*m+2;i++) G[i].clear();
}
bool valid(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='#';
}
void dij(int N,int s){
    for (int i=1;i<=N;i++) vis[n]=0;
    dis[s]=0;
    priority_queue<pi,vector<pi>,greater<pi> > pq;
    pq.push((pi){0,s});
    while (!pq.empty()){
        pi tmp=pq.top(); pq.pop();
        int u=tmp.S;
        if (vis[u]) continue; vis[u]=1;
        for (auto e:G[u]){
            int v=e.F;
            if (dis[v]>dis[u]+e.S){
                dis[v]=dis[u]+e.S;
                pq.push((pi){dis[v],v});
            }
        }
    }
}
void work(){
    init();
    int s=n*m+1;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            if (a[i][j]=='#') continue;
            int u=id(i,j);
            if (a[i][j]=='.') add_edge(s,u,0);
            for (int o=0;o<4;o++){
                int x=i+dx[o];
                int y=j+dy[o];
                if (!valid(x,y)) continue;
                if (o%2==0){
                    if (a[x][y]=='L') add_edge(u,id(x,y+1),q);
                    if (a[x][y]=='R') add_edge(u,id(x,y-1),q);
                    if (a[x][y]=='U') add_edge(u,id(x+1,y),p);
                    if (a[x][y]=='D') add_edge(u,id(x-1,y),p);
                } else {
                    if (a[x][y]=='L') add_edge(u,id(x,y+1),p);
                    if (a[x][y]=='R') add_edge(u,id(x,y-1),p);
                    if (a[x][y]=='U') add_edge(u,id(x+1,y),q);
                    if (a[x][y]=='D') add_edge(u,id(x-1,y),q);
                }
            }
        }
    dij(n*m+1,s);
}
void solve(){
    cin >> n >> m >> p >> q;
    for (int i=0;i<n;i++){
        cin >> s;
        for (int j=0;j<m;j++) a[i].pb(s[j]);
    }
    for (int i=1;i<=n*m;i++) dis[i]=inf;
    work();
    ll ans=inf;
    for (int i=0;i<n;i++)
        for (int j=0;j<m-1;j++)
            ans=min(ans,dis[id(i,j)]+dis[id(i,j+1)]);
    for (int i=0;i<n-1;i++)
        for (int j=0;j<m;j++)
            ans=min(ans,dis[id(i,j)]+dis[id(i+1,j)]);
    if (ans==inf) puts("-1"); else printf("%lld\n",ans);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _=1;
    while (_--) solve();
}