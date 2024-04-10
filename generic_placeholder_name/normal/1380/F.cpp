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

constexpr int N=5e5+1;
constexpr ll MOD=998244353; //REMINDER: CHECK THE FUCKING MODULO YOU IDIOT

struct matrix {
    ll a[2][2];
    matrix() {memset(a, 0, sizeof(a));}
    ll* operator [] (int x) {return a[x];}
    const ll* operator [] (int x) const {return a[x];}
    friend matrix operator * (const matrix& a, const matrix& b) {
        matrix c;
        rep(i, 2) rep(j, 2) c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j];
        return c;
    }
    friend matrix operator % (const matrix& a, const ll x) {
        matrix c;
        rep(i, 2) rep(j, 2) c[i][j]=a[i][j]%x;
        return c;
    }
};

matrix t[4*N];
string s;

unordered_map<string, int> mem;
matrix src;
void init() {
    src[0][0]=src[0][1]=1;
    mem["0"]=1; mem["1"]=2; mem["2"]=3; mem["3"]=4; mem["4"]=5;
    mem["5"]=6; mem["6"]=7; mem["7"]=8; mem["8"]=9; mem["9"]=10;
    mem["10"]=9; mem["11"]=8; mem["12"]=7; mem["13"]=6; mem["14"]=5;
    mem["15"]=4; mem["16"]=3; mem["17"]=2; mem["18"]=1;
}

inline matrix get(int idx) {
    matrix res;
    res[1][0]=1; res[0][0]=0;
    if(idx==0) res[0][1]=0;
    else if(mem.find(s.substr(idx-1, 2))!=mem.end()) res[0][1]=mem[s.substr(idx-1, 2)];
    else res[1][1]=0;
    if(mem.find(s.substr(idx, 1))!=mem.end()) res[1][1]=mem[s.substr(idx, 1)];
    else res[1][1]=0;
    return res;
}

int n, m;

void build(int v=1, int l=0, int r=n-1) {
    if(l==r) t[v]=get(l);
    else {
        int m=(l+r)/2;
        build(v*2, l, m);
        build(v*2+1, m+1, r);
        t[v]=(t[v*2]*t[v*2+1])%MOD;
    }
}

void upd(int pos, int v=1, int tl=0, int tr=n-1) {
    if(tl==tr) t[v]=get(tl);
    else {
        int tm=(tl+tr)/2;
        if(pos<=tm) upd(pos, v*2, tl, tm);
        else upd(pos, v*2+1, tm+1, tr);
        t[v]=(t[v*2]*t[v*2+1])%MOD;
    }
}

void upd(int pos, char c) {
    s[pos]=c;
    upd(pos); if(pos!=n-1) upd(pos+1);
}

int32_t main() {
    fastio;
    init();
    cin>>n>>m>>s;
    build();
    rep(i, m) {
        int pos; char c; cin>>pos>>c; --pos;
        upd(pos, c);
        matrix cur=(src*t[1])%MOD;
        cout<<cur[0][1]<<endl;
    }
}