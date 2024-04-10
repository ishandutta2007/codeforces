#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int MOD=1e9+7;
inline int add(int a, int b) {a+=b; if(a>=MOD) a-=MOD; return a;}
inline int sub(int a, int b) {return add(a, MOD-b);}
inline int mul(int a, int b) {return (a*1LL*b)%MOD;}

int exp(int a, int b) {
    int res=1;
    while(b) {
        if(b&1) res=mul(res, a);
        a=mul(a, a);
        b>>=1;
    }
    return res;
}

constexpr int N=1e6+5;
int fact[N];
void init_fact() {
    fact[0]=1; rep1(i, N-1) fact[i]=mul(i, fact[i-1]);
}

struct dsu {
    int d[N];
    int t[N];
    dsu() {
        memset(d, -1, sizeof(d));
        rep(i, N) t[i]=i;
    }

    int find(int x) {return d[x]<0?x:d[x]=find(d[x]);}
    void join(int x, int y) {
        x=find(x), y=find(y);
        if(x==y) return;
        if(d[x]>d[y]) swap(x, y);
        d[x]+=d[y]; d[y]=x;
        t[x]=t[x]>t[y]?t[y]:t[x];
    }
    inline int get(int x) {return t[find(x)];}
    inline bool is_connected(int a, int b) {return find(a)==find(b);}
};

bool isprime[N];
vi p[N];
array<int, N> f;
void init_prime() {
    memset(isprime, true, sizeof(isprime));
    isprime[0]=isprime[1]=0;
    f.fill(1);
    p[1].pb(1);
    for(int i=2; i<N; i++) if(isprime[i]) {
        for(int j=2*i; j<N; j+=i) isprime[j]=0;
        for(int j=i; j<N; j+=i) p[j].eb(i), f[j]*=i;
    }
}

inline void NO() {
    cout<<"0\n";
    exit(0);
}

int a[N];
int lst[N];
int sz[N], cnt[N];
int pos[N];
dsu d;
vi occ[N];
int prv[N], nxt[N];

int32_t main() {
    fastio;
    init_fact();
    init_prime();
    int n; cin>>n;
    rep1(i, n) cin>>a[i];
    occ[1].pb(1); sz[1]=pos[1]=1;
    for(int i=2; i<=n; i++) if(isprime[i]) {
        sz[n/i]++;
        pos[i]=n/i;
        occ[n/i].pb(i);
        lst[i]=i;
    }
    rep1(i, n) cnt[f[i]]++;
    rep1(i, n) rep1(j, ((int)occ[i].size())-1) d.join(occ[i][j-1], occ[i][j]);
    for(int i=2; i<=n; i++) if(!isprime[i]) {
        int gr=1;
        for(int x: p[i]) gr*=d.get(x);
        if(lst[gr]) d.join(i, lst[gr]);
        lst[gr]=i;
    }
    rep1(i, n) {
        if(a[i]) {
            cnt[f[i]]--;
            if(!d.is_connected(i, a[i])) NO();
            else {
                const int x=p[i].back(), y=p[a[i]].back();
                if(nxt[x]&&nxt[x]!=y) NO();
                if(prv[y]&&prv[y]!=x) NO();
                if(!nxt[x]&&!prv[y]) sz[pos[x]]--;
                nxt[x]=y; prv[y]=x;
            }
        }
    }
    int ans=1;
    rep1(i, n) ans=mul(ans, mul(fact[sz[i]], fact[cnt[i]]));
    cout<<ans<<endl;
}