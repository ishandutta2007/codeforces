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
	vl data;
	int cnts[61]; F0R(i, 61) cnts[i] = 0;
	F0R(i, N) {
		ll X; cin >> X;
		if (X != 0) {
			data.pb(X);
			F0R(j, 61) {
				if (X & (1ll << j)) cnts[j]++;
			}
		}
	}
	
	F0R(i, 61) {
		if (cnts[i] > 2) {
			cout << 3 << endl; return 0;
		}
		
	}
	N = sz(data);
	
	int ans = 100000;
	
	F0R(start, N) {
		FOR(end, start+1, N) {
			if ((data[start] & data[end]) == 0) continue;
			int dist[N]; F0R(i, N) dist[i] = -1;
			dist[start] = 0;
			queue<int> q; q.push(start);
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				F0R(i, N) {
					if ((data[i] & data[cur]) == 0) continue;
					if (i == cur) continue;
					if (cur == start && i == end) continue;
					if (cur == end && i == start) continue;
					if (dist[i] != -1) continue;
					dist[i] = dist[cur]+1;
					q.push(i);
					
				}
			}
			
			if (dist[end] != -1) ans = min(ans, dist[end]);
			
			F0R(i, N) {
				//cout << start << " " << end << " " << i << " " << dist[i] << endl;
			}
			
		}
	}
	
	if (ans == 100000) {
		cout << -1 << endl;
	} else {
		cout << ans+1 << endl;
	}
	
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343