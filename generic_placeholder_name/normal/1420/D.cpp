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

//cm b m bt a e i hc

constexpr int MOD=998244353;
constexpr int N=300005;

int exp(int a, int b) {
    if(!b) return 1;
    else {
        int x=exp(a, b/2);
        x=(x*1LL*x)%MOD;
        if(b&1) return (x*1LL*a)%MOD;
        else return x;
    }
}

int fact[N];
int inv[N];
void init_fact() {
    fact[0]=1; rep1(i, N-1) fact[i]=(i*1LL*fact[i-1])%MOD;
    inv[0]=1; rep1(i, N-1) inv[i]=exp(fact[i], MOD-2);
}
inline int nCr(int n, int r) {return n<r?0:(((fact[n]*1LL*inv[n-r])%MOD)*1LL*inv[r])%MOD;}

int32_t main() {
    fastio;
    init_fact();
    map<int, vi> m;
    int n, k; cin>>n>>k;
    rep(i, n) {
        int l, r; cin>>l>>r;
        m[l].eb(0);
        m[r].eb(1);
    }
    int ans=0, cur=0;
    for(auto& it: m) {
        #define x it.fi
        #define v it.se
        sort(all(v));
        for(auto q: v) {
            if(!q) (ans+=nCr(cur++, k-1))%=MOD;
            else cur--;
        }
        #undef x
        #undef v
    }
    cout<<ans<<endl;
}