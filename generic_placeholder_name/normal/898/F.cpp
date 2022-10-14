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
 
constexpr ll MOD[]={998244353, 1000000007, 1000000123};
//this *should* be enough
string s;
constexpr int N=1e6+1;
int n;
ll h[3][N+1], pw[3][N+1];
 
bool check(int x, int y) {
    if(x>=y||y>=n) return 0;
    if(s[0]=='0'&&x>1) return 0;
	if(s[x]=='0'&&y>x+1) return 0;
	if(s[y]=='0'&&n>y+1) return 0;
	//HUMONGOUS LINE OF DEGENERACY
	rep(t, 3) if((h[t][x]+h[t][y]-1LL*h[t][x]*pw[t][y-x]-h[t][n]+1LL*h[t][y]*pw[t][n-y])%MOD[t]!=0) return 0;
	rep(i, n) {
	    cout<<s[i];
	    if(i==x-1) cout<<'+';
	    if(i==y-1) cout<<'=';
	}
	cout<<endl;
	return 1;
}
 
int32_t main() {
    fastio;
    cin>>s; n=s.length();
    rep(i, 3) pw[i][0]=1;
    rep(t, 3) rep1(i, n) h[t][i]=(h[t][i-1]*10+s[i-1]-'0')%MOD[t], pw[t][i]=(pw[t][i-1]*10)%MOD[t];
    rep1(i, (n-1)/2) {
        if(check(i, n-i)) return 0;
		if(check(i, n-i-1)) return 0;
		if(check(i, n-(n-i)/2)) return 0;
		if(check(i, n-(n-i)/2-1)) return 0;
    }
    assert(0);
}