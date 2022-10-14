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

char a[105][1005];
void solve(){
	int n, m, x, y; cin>>n>>m>>x>>y;
	ll ans=0;
	rep(i, n){
		string s; cin>>s;
		rep(j, m) a[i][j]=s[j];
		int itr; vll comp;
		for (itr=0; itr<m; ){
			if (a[i][itr]=='*'){
				while ((itr<m)&&(a[i][itr]=='*')) itr++;
			}
			else {
				int cnt=0;
				while ((itr<m)&&(a[i][itr]=='.')) itr++, cnt++;
				comp.pb(cnt);
			}
		}
		rep(i, comp.size()){
			ans+=(comp[i]/2)*min(y, x*2);
			ans+=(comp[i]%2)*x;
		}
	}
	cout<<ans<<endl;
}

int32_t main(){
	fastio;
	int q; cin>>q; while(q--) solve();
}