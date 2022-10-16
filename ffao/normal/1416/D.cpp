#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define td(v) v.begin(),v.end()
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define re(v) {for(auto &_re : v) cin >> _re;}
#define rre(v){for(auto &_re : v) for(auto &_rre : _re) cin >> _rre;}
#define pr(v) {for(auto _pr : v) cout << _pr << " "; cout << endl;}
#define prr(v) {for(auto _prr : v) cout << _prr.ff << " " << _prr.ss << endl;}
#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
using namespace std;
const ll M = 1e9 + 7;
const ll mod = 998244353;
    
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    
ll binpow(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
    if(b&1) res = res * a % m;
    a = a * a % m;
    b>>=1;
    }
    return res;
}
ll gcd(ll a, ll b){
    return (b==0 ? a : gcd(b,a%b));
}
struct dsu{ // dsu with rollback
    struct op{
        int u, l, t;
        op(){}
        op(int u,int l,int t) : u(u), l(l), t(t){}
    };
    vector<int> pai, tam;
    stack<op> old_pai;
    stack<op> old_tam;
    vector<int> g[200200];
    dsu(){}
    dsu(int n){
        pai.resize(n);
        tam = pai;
        for(int i=0;i<n;i++){
            pai[i] = i;
            tam[i] = 1;
        }
    }
    vector<int> at, deleted;
    void init(vector<int> &v){
        at.resize(v.size() + 1);
        deleted.resize(v.size() + 1);
        for(int i=0;i<v.size();i++){
            g[i].eb(v[i]);
            at[v[i]] = i;
        }
    }
    int find(int u){
        if(pai[u] == u) return u;
        return find(pai[u]);
    }
    void merge(int u, int v, int t){ // merges u and v at time T;
        int a = find(u);
        int b = find(v);
        if(a==b) return;
        if(tam[a] > tam[b]) swap(a, b);
        old_pai.emplace(a, pai[a], t);
        old_tam.emplace(b, tam[b], t);
        pai[a] = b;
        tam[b] += tam[a];
        for(int &x : g[a]){
            g[b].push_back(x);
            at[x] = b;
        }
    }
    void query(int v){
        v = find(v);
        int go = 0;
        while(!g[v].empty()){
            int u = g[v].back();
            g[v].pop_back();
            if(u == 0 or at[u] != v or deleted[u]) continue;
            else{
                go = u;
                deleted[u] = 1;
                break;
            }
        }
        cout << go << endl;
    }
    void rollback(int t){
        while(!old_pai.empty() && old_pai.top().t >= t){ // rolls back until time = t-1			
            pai[old_pai.top().u] = old_pai.top().l;
            tam[old_tam.top().u] = old_tam.top().l;
            for(int &x : g[old_pai.top().l]){
                at[x] = old_pai.top().l;
            }
            old_pai.pop();
            old_tam.pop();
        }
    }
};
void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> p(n), er(m), ql(n+1), cnt(n+1);
    re(p);
    for (int i=0;i<n;i++) ql[p[i]]=i;
    vector<pii> e(m);
    for(int i=0;i<m;i++){
    cin >> e[i].ff >> e[i].ss;
    e[i].ff--; e[i].ss--;
    }
    vector<pii> qs(q);
    for(int i=0;i<q;i++){
    cin >> qs[i].ff >> qs[i].ss;
    qs[i].ss--;
    if(qs[i].ff == 2) er[qs[i].ss] = 1;
    }
    dsu D(n);
    D.init(p);
    for(int i=0;i<m;i++){
    if(er[i]) continue;
    D.merge(e[i].ff, e[i].ss, 0);
    }
    int t = 1;
    for(int i=q-1;i>=0;i--){
    if(qs[i].ff == 2){
        D.merge(e[qs[i].ss].ff, e[qs[i].ss].ss, t++);
    }
    }
    for (int i=1;i<=n;i++) {
        int loc=ql[i];
        for (; loc!=D.pai[loc]; loc=D.pai[loc]) D.g[loc][cnt[loc]++]=i;
        D.g[loc][cnt[loc]++]=i;
    }
    for(int i=0;i<q;i++){
    if(qs[i].ff == 1){
        D.query(qs[i].ss);
    }
    else{
        D.rollback(--t);
    }
    }
} 
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
    solve();
    }
}