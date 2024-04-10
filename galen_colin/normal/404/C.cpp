/* testing for Kaunta */

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 
 
typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 
 
const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100005;
 
int N, K, a_i, curr[MX];
vi nodes[MX];
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	F0R(i, MX)  curr[i] = 0;
	
	F0R(i, N) 
	{
		cin >> a_i;
		nodes[a_i].pb(i + 1);
	}
	
	// Check to makes ure its legal
	if (sz(nodes[0]) != 1 || sz(nodes[1]) > K) {
		cout << -1;
		return 0; 
	}
	
	FOR(i, 2, N) {
		if (sz(nodes[i]) > (ll)sz(nodes[i - 1]) * (K - 1)) {
			cout << -1;
			return 0;
		}
	}
		
	cout << N - 1 << "\n";
	F0R(i, sz(nodes[1])) cout << nodes[0][0] << " " << nodes[1][i] << "\n";
	
	FOR(i, 1, N - 1)
	{
		if (!sz(nodes[i + 1]) || !sz(nodes[i])) break;
		curr[i] = 0;
		while(curr[i + 1] < sz(nodes[i + 1]))
		{
		    int stop = min(K - 1, sz(nodes[i + 1]) - curr[i + 1]);
			F0R(j, stop)
			{
				cout << nodes[i][curr[i]] << " ";
				cout << nodes[i + 1][curr[i + 1]++] << "\n";
			}
			curr[i]++;
		}
	}
    return 0;
}