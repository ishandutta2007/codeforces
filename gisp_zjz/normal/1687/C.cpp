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
vi G[maxn];
int _,n,m,d[maxn],u[maxn],v[maxn];
queue<int> Q;
ll a[maxn],b[maxn],s[maxn];
void del(int x){
    for (auto y:G[x]){
        d[y]--;
        if (!d[y]) Q.push(y);
    }
}
void build(int x,int l,int r){
    if (l==r) {s[x]=1;return;}
    int mid=(l+r)>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    s[x]=s[x*2]+s[x*2+1];
}
void modify(int x,int l,int r,int L,int R){
    if (!s[x]) return;
    if (l==r){
        s[x]=0; del(l);
        return;
    }
    int mid=(l+r)>>1;
    if (L<=mid) modify(x*2,l,mid,L,R);
    if (R>mid) modify(x*2+1,mid+1,r,L,R);
    s[x]=s[x*2]+s[x*2+1];
}
void solve(){
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=0;i<=n;i++) G[i].clear();
    for (int i=1;i<=m;i++){
        cin >> u[i] >> v[i];
        u[i]--; d[i]=2;
        G[u[i]].pb(i); G[v[i]].pb(i);
    }
    for (int i=1;i<=n;i++) a[i]+=a[i-1],b[i]+=b[i-1];
    if (a[n]!=b[n]){puts("NO");return;}
    build(1,1,n); del(0);
    for (int i=1;i<=n;i++) if (a[i]==b[i]) modify(1,1,n,i,i);
    while (!Q.empty()){
        int x=Q.front(); Q.pop();
        modify(1,1,n,u[x]+1,v[x]);
    }
    if (s[1]) puts("NO"); else puts("YES");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--) solve();
}