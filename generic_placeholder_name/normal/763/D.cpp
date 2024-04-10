#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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

struct custom_hashes {
    inline static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template<typename T> //should take care of all types that can turn into integers
    size_t operator()(T x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64((uint64_t)x + FIXED_RANDOM);
    }

    template<typename T1, typename T2>
    size_t operator()(pair<T1, T2> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(hash<T1>()(x.fi) + FIXED_RANDOM) ^ splitmix64(hash<T2>()(x.se) + FIXED_RANDOM);
    }
};

template<typename _F, typename _T> using safe_map=gp_hash_table<_F, _T, custom_hashes>;

vvi adj;
int n;
int root=0;

safe_map<int, int> hashes;
safe_map<pii, int> label;
safe_map<int, int> rmap;
vi pw{1};

constexpr int p=31, MOD=1e9+123;

inline int get_hash(const vi& a) {
    int ans=0;
    for(int it: a) (ans+=pw[it])%=MOD;
    return ans;
}

struct tracker {
    safe_map<int, int> m;
    void add(int x) {m[x]++;}
    void sub(int x) {if(m.find(x)==m.end()) return; if(m[x]>1) m[x]--; else m.erase(x);}
    const size_t size() {return m.size();}
} labels;

int t=0;
int get_label(int u, int par, bool ins=0) {
    if(label.find({u, par})!=label.end()) return label[{u, par}];
    vi sons;
    for(int v: adj[u]) if(v!=par) sons.pb(get_label(v, u, ins));
    int val=get_hash(sons);
    if(hashes.find(val)!=hashes.end()) label[{u, par}]=hashes[val];
    else {
        pw.pb(1LL*pw.back()*p%MOD);
        hashes[val]=t;
        rmap[t++]=val;
        label[{u, par}]=hashes[val];
    }
    if(ins) {
        labels.add(label[{u, par}]);
    }
    return label[{u, par}];
}

void fill_labels(int u, int par) {
    for(int v: adj[u]) if(v!=par){
        if(u==root) {
            int val=rmap[label[{u, -1}]]-pw[label[{v, u}]]%MOD+MOD%MOD;
            if(hashes.find(val)!=hashes.end()) label[{u, v}]=hashes[val];
            else {
                pw.pb(1LL*pw.back()*p%MOD);
                hashes[val]=t;
                rmap[t++]=val;
                label[{u, v}]=hashes[val];
            }
        }
        else {
            int val=rmap[label[{u, par}]]-pw[label[{v, u}]]+0LL+pw[label[{par, u}]]%MOD+MOD%MOD;
            if(hashes.find(val)!=hashes.end()) label[{u, v}]=hashes[val];
            else {
                pw.pb(1LL*pw.back()*p%MOD);
                hashes[val]=t;
                rmap[t++]=val;
                label[{u, v}]=hashes[val];
            }
        }
    }
    for(int v: adj[u]) if(v!=par) fill_labels(v, u);
}

int mx, id;

void dfs(int u, int par=-1) {
    if(u!=root) {
        labels.sub(get_label(u, par));
        labels.add(get_label(par, u));
        if(mx<labels.size()) mx=labels.size(), id=u;
    }
    for(int v: adj[u]) if(v!=par) dfs(v, u);
    if(u!=root) {
        labels.add(get_label(u, par));
        labels.sub(get_label(par, u));
    }
}

int get_max() {
    rep(i, n) if(adj[i].size()>adj[root].size()) root=i;
    get_label(root, -1, 1);
    fill_labels(root, -1);
    labels.sub(get_label(root, -1));
    mx=labels.size(); id=root;
    dfs(root);
    return id;
}

int32_t main() {
    ///uhh so the last AC was just dumb luck
    ///that I didn't run into the bug
    ///so this is actually fixed
    ///actually correct now
    fastio;
    cin>>n; adj.resize(n);
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[--u].pb(--v); adj[v].pb(u);
    }
    cout<<get_max()+1<<endl;
}