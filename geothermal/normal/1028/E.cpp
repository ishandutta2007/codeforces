#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	int N; cin >> N;
	ll data[N];
	ll maxVal = 0;
	F0R(i, N) cin >> data[i];
	vpi nonZeroes;
	F0R(i, N) {
		if (data[i] != 0) {
			nonZeroes.pb(mp(data[i], i));
		}
	}
	
	F0R(i, N) maxVal = max(maxVal, data[i]);
	
	if (maxVal == 0) {
		cout << "YES" << endl;
		F0R(i, N) cout << 1 << " ";
		cout << endl; return 0;
	}
	
	/*if (sz(nonZeroes) == 1) {
		cout << "YES" << endl;
		
		F0R(i, N) {
			if (i == nonZeroes[0].s) {
				cout << nonZeroes[0].f << " ";
			} else cout << nonZeroes[0].f * 2 << " ";
			
		}
		cout << endl;
		
		return 0;
	}*/
	
	int pos = -1;
	
	/*F0R(i, sz(nonZeroes)) {

		if ((nonZeroes[i].f == maxVal && nonZeroes[(i+sz(nonZeroes)-1)%sz(nonZeroes)].f != maxVal) || 
		(nonZeroes[i].f == maxVal && nonZeroes[(i+sz(nonZeroes)-1)%sz(nonZeroes)].s != nonZeroes[i].s-1)) {
			pos = nonZeroes[i].s;
		}
		
	}*/
	F0R(i, N) {
		if (data[i] == maxVal && data[(i+N-1)%N] != maxVal) {
			pos = i;
		}
	}
	
	if (pos == -1) {
		cout << "NO" << endl; return 0;
	} 
	
	ll sum = 0;
	
	ll ans[N];
	
	//int lastNon = -1;
	F0R(i, N) {
		sum += data[(pos+N-i)%N];
		//if (data[(pos+N-i)%N] != 0) lastNon = data[(pos+N-i)%N];
		if (data[(pos+N-i)%N] == 0 && i == 1) sum += maxVal;
		ans[(pos+N-i)%N] = sum;
	}
	
	cout << "YES" << endl;
	F0R(i, N) {
		cout << ans[i] << " "; 
	}
	cout << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343