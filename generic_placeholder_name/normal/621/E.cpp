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

constexpr ll MOD=1e9+7;
const int K=101;

struct matrix {
    ll a[K][K];
    matrix() {memset(a, 0, sizeof(a));}
    ll* operator [] (int x) {return a[x];}
    const ll* operator [] (int x) const {return a[x];}
    friend matrix operator * (const matrix& a, const matrix& b) {
        matrix c;
        rep(i, K) rep(j, K) rep(k, K) (c[i][j]+=a[i][k]*b[k][j])%=MOD;
        return c;
    }
};

matrix ident() {
    matrix ret; rep(i, K) ret[i][i]=1; return ret;
}
matrix exp(matrix a, int b){
    if(!b) return ident();
    matrix x=exp(a, b/2);
    x=x*x;
    if (b&1) return x*a;
    else return x;
}

int32_t main() {
    fastio;
    int n, b, k, x; cin>>n>>b>>x>>k;
    int a[k]; memset(a, 0, sizeof(a));
    rep(i, n) {int t; cin>>t; a[t%k]++;}
    matrix mul;
    //setup
    rep(i, k) rep(j, k) mul[i][(i*10+j)%k]=a[j];
    //end
    mul=exp(mul, b);
    cout<<mul[0][x]<<endl;
}