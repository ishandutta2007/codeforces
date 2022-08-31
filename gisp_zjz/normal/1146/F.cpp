#include<bits/stdc++.h>
#define maxn 300050
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const double PI=acos(-1.0);
const int M=998244353;
vector <int> G[maxn];
ll g[maxn],h[maxn];
int n;
void add(ll &x,ll y){
    x+=y; if (x>=M) x-=M;
}
void sub(ll &x,ll y){
    x-=y; if (x<0) x+=M;
}
void dfs(int u){
    if (!G[u].size()){
        h[u]=1; g[u]=1;
        return;
    }
    ll f=1; g[u]=0; h[u]=1;
    vector <ll> s,t,p,q;
    int m=G[u].size();
    s.resize(m+2);
    t.resize(m+2);
    p.resize(m+2);
    q.resize(m+2);
    for (int i=1;i<=m;i++){
        int v=G[u][i-1];
        dfs(v); p[i]=g[v]; q[i]=h[v];
        f=f*(g[v]+h[v])%M;
        h[u]=h[u]*h[v]%M;
    }
    s[0]=1; for (int i=1;i<=m;i++) s[i]=s[i-1]*q[i]%M;
    t[m+1]=1; for (int i=m;i;i--) t[i]=t[i+1]*q[i]%M;
    for (int i=1;i<=m;i++) (g[u]+=s[i-1]*t[i+1]%M*p[i])%=M;
    ll r=((f-g[u]-h[u])%M+M)%M;
    add(h[u],r); add(g[u],r);
}
int main(){
    cin >> n;
    for (int i=2;i<=n;i++){
        int fa; scanf("%d",&fa);
        G[fa].pb(i);
    }
    dfs(1);
    ll ans=0;
    cout << h[1] << endl;
    return 0;
}