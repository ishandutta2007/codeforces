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
	
	int Q; cin >> Q;
	F0R(testCase, Q) {
		int N; cin >> N;
		
		bool data[N][2];
		F0R(j, 2) { F0R(i, N) {
			char C; cin >> C;
			data[i][j] = true;
			if (C == '1' || C == '2') data[i][j] = false;
		}
		}
		
		int X = 0;
		int Y = 0;
		bool moved = false;
		while (X != N) {
			/*if (moved && !data[X][Y]) {
				cout << "NO" << endl;
				goto done;
			}
			if (data[X][Y] && !moved) {
				moved = true; Y = 1-Y;
			} else {
				moved = false; X++;
			}*/
			if (data[X][Y] && data[X][1-Y]) {
				X++; 
				Y = 1-Y;
			} else if (!data[X][Y]) {
				X++;
			} else {
				cout << "NO" << endl; goto done;
			}
		}
		
		cout << (Y == 1 ? "YES" : "NO") << endl;
		
		done:;
			
	}
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343