#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
int n,d[105][105],vis[105],dis[105];
vi G[105];
char s[105];
bool f[105][105][105],g[105][105][105];
void add_edge(int u,int v){
    G[u].pb(v); G[v].pb(u);
}
void print(){
    cout << "Yes" << endl;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (d[i][j]==1) cout << i << ' ' << j << endl;
}
void dfs(int u,int fa){
    for (int v=1;v<=n;v++)
        if (!vis[v]&&v!=fa&&f[fa][v][u])
            add_edge(u,v),vis[v]=1,dfs(v,u);
}
void dfs2(int u,int fa){
    for (auto v:G[u]){
        if (v==fa) continue;
        dis[v]=dis[u]+1;
        dfs2(v,u);
    }
}
int pre[105];
int ffind(int x){
    if (pre[x]==x) return x;
    return pre[x]=ffind(pre[x]);
}
bool is_tree(){
    for (int i=1;i<=n;i++) pre[i]=i;
    int cnt=0;
    for (int i=1;i<=n;i++){
        int u=i;
        for (auto v:G[u]){
            if (u>v) continue;
            if (ffind(u)!=ffind(v)) cnt++,pre[ffind(v)]=ffind(u);
            else return 0;
        }
    }
    return cnt==n-1;
}
bool check(){
    for (int i=1;i<=n;i++) if (!vis[i]) return 0;
    assert(is_tree());
    for (int i=1;i<=n;i++){
        dis[i]=0; dfs2(i,0);
        for (int j=1;j<=n;j++) d[i][j]=dis[j];
    }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=1;k<=n;k++)
                if (f[i][j][k]!=(d[i][k]==d[j][k])) return 0;
    return 1;
}
void solve(){
    cin >> n;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++){
            cin >> s+1;
            for (int k=1;k<=n;k++) f[j][i][k]=f[i][j][k]=(s[k]=='1');
        }
    for (int x=2;x<=n;x++){
        for (int i=1;i<=n;i++) G[i].clear(),vis[i]=0;
        add_edge(1,x); vis[1]=vis[x]=1; 
        dfs(1,x); dfs(x,1);
        if (check()) {print();return;}
    }
    cout << "No" << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}