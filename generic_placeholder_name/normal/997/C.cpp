#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
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

constexpr int MOD=998244353;
int exp(int a, ll b) {
    if(b==0) return 1;
    else {
        int x=exp(a, b/2);
        if(b&1) return 1LL*x*x%MOD*1LL*a%MOD;
        else return 1LL*x*x%MOD;
    }
}

int add(int a, int b) {a=a+b; if(a<0) a+=MOD; if(a>MOD) a-=MOD; return a;}
int sub(int a, int b) {a=a-b; if(a<0) a+=MOD; if(a>MOD) a-=MOD; return a;}
int mul(int a, int b) {return (1LL*a*b)%MOD;}

constexpr int N=1000001;
int fact[N];
int inv[N];

int nCr(int n, int r) {
    return 1LL*fact[n]*inv[r]%MOD*1LL*inv[n-r]%MOD;
}

int32_t main() {
	fastio;
	int n; cin>>n;
	fact[0]=1; rep1(i, n) fact[i]=mul(fact[i-1], i);
	inv[0]=1; rep1(i, n) inv[i]=exp(fact[i], MOD-2);
	int ans=sub(exp(3, 1LL*n*n), exp(sub(exp(3, n), 3), n));
	rep1(i, n) {
        int val=mul(nCr(n, i), add(mul(3, exp(sub(exp(3, n-i), 1), n)), mul(sub(exp(3, i), 3), exp(3, 1LL*(n-i)*n))));
        if(i%2) ans=add(ans, val);
        else ans=sub(ans, val);
	}
	cout<<ans<<endl;
}