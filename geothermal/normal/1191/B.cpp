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
#define FILLV(vec,a) for (int i = 0; i < sz((vec)); i++) { (vec)[i] = (a); }
#define FILLA(arr,a) for (int i = 0; i < sizeof((arr)); i++) { (arr)[i] = (a); }

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	string data[3]; F0R(i, 3) cin >> data[i];
	
	int ans = 2;
	if (data[0] == data[1]) ans = 1;
	if (data[0] == data[2]) ans = min(ans, 1);
	if (data[1] == data[2]) {
		ans--;
	}
	
	if (data[0][1] == data[1][1] && data[0][1] == data[2][1]) {
		vi vals; F0R(i, 3) vals.pb(data[i][0] - '0');
		sort(all(vals));
		if (vals[0] + 1 == vals[1] && vals[1] + 1 == vals[2]) {
			ans = 0;
		}
	}
	
	if (data[0][1] == data[1][1]) {
		vi vals; vals.pb(data[0][0] - '0'); vals.pb(data[1][0] - '0');
		sort(all(vals));
		if (vals[0] + 1 == vals[1] || vals[0] + 2 == vals[1]) ans = min(ans, 1);
	}
	
	if (data[0][1] == data[2][1]) {
		vi vals; vals.pb(data[0][0] - '0'); vals.pb(data[2][0] - '0');
		sort(all(vals));
		if (vals[0] + 1 == vals[1] || vals[0] + 2 == vals[1]) ans = min(ans, 1);
	}
	
	
	if (data[2][1] == data[1][1]) {
		vi vals; vals.pb(data[2][0] - '0'); vals.pb(data[1][0] - '0');
		sort(all(vals));
		if (vals[0] + 1 == vals[1] || vals[0] + 2 == vals[1]) ans = min(ans, 1);
	}
	
	
	cout << ans << endl;
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343