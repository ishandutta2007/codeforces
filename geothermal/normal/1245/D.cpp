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
	vpl pts(N);
	F0R(i, N) {
		int X, Y; cin >> X >> Y;
		pts[i] = {X, Y};
	}
	
	ll C[N], K[N]; F0R(i, N) cin >> C[i]; 
	F0R(i, N) cin >> K[i];
	
	ll minCost = 10000000000, root = -1;

	
	priority_queue<pair<ll, pi> > q;
	int parent[N];
	vector<bool> station(N);
	int staCount = 0, roadCount = 0;
	F0R(i, N) {
		parent[i] = -2;
		station[i] = false;
	}
	
	F0R(i, N) {
		if (parent[i] == -2) {
			//q.push(mp((-1*abs(pts[i].f - pts[root].f) - abs(pts[i].s - pts[root].s)) * (K[i] + K[root]), mp(i, root)));
			q.push(mp(C[i]*-1, mp(i, -1)));
		}
	}
	ll ans = 0;
	while (!q.empty()) {
		pair<ll, pi> p = q.top(); q.pop();
		int cur = p.s.f;
		int lst = p.s.s;
		if (parent[cur] != -2) continue;
		parent[cur] = lst;
		p.f *= -1; ans += p.f;
		if (lst == -1) {
			station[cur] = true; staCount++;
		} else {
			roadCount++;
		}
		
		F0R(i, N) {
			if (parent[i] == -2) {
				q.push(mp((-1*abs(pts[i].f - pts[cur].f) - abs(pts[i].s - pts[cur].s)) * (K[i] + K[cur]), mp(i, cur)));
			}
		}
	}
	
	cout << ans << endl;
	cout << staCount << endl;
	F0R(i, N) {
		if (station[i]) {
			cout << i+1 << " ";
		}
	}
	cout << endl;
	cout << roadCount << endl;
	F0R(i, N) {
		if (parent[i] != -1 && parent[i] != -2) {
			cout << parent[i]+1 << " " << i+1 << endl;
		}
	}
	
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343