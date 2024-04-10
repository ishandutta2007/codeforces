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
 
constexpr int N=200001;
constexpr ll MOD=998244353;
ll a[N], b[N];
 
int32_t main() {
    fastio;
    int n, m; cin>>n>>m; rep(i, n) cin>>a[i]; rep(i, m) cin>>b[i];
	vi l; l.reserve(n);
	for(int i=n-1; i>=0; i--) if(l.empty()||a[i]<a[l.back()]) l.pb(i);
	reverse(all(l));
	int idx=m-1; ll ans=1;
	for(int i=l.size()-1; i>=0; i--) {
		if(idx<0) break;
		if(b[idx]==a[l[i]]) {
            idx--;
            if(i) (ans*=l[i]-l[i-1])%=MOD;
        }
	}
	if((idx>=0)||a[l[0]]!=b[0]) return cout<<"0\n", 0;
	cout<<ans<<endl;
}