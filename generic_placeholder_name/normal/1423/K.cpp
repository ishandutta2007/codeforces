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

//rules: all composites are ok b/c p(q-1) and pq is a valid pair
//also p and p^2 is a valid pair
//therefore ans = cnt of primes from sqrt(n) to n
//additionally, 1 is always fucked

constexpr int N=1e6+1;
bool isprime[N];
int pf[N], sq[N];

inline void init() {
    memset(isprime, true, sizeof(isprime));
    isprime[0]=isprime[1]=0;
    for(int i=2; i*i<N; i++) if(isprime[i]) {
        for(int j=i*i; j<N; j+=i) isprime[j]=0;
    }
    rep1(i, N-1) {
        pf[i]=pf[i-1]+isprime[i];
        sq[i]=sq[i-1]+((sq[i-1]+1)*(sq[i-1]+1)<=i);
    }
}

inline int query(int n) {
    return pf[n]-pf[sq[n]]+1;
}

int32_t main() {
    fastio;
    init();
    int t; cin>>t;
    while(t--) {int x; cin>>x; cout<<query(x)<<'\n';}
}