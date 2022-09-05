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
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	int N; cin >> N;
	
	map<pi, set<pair<int, int> > > data;
	
	int X[N], Y[N], Z[N];
	
	F0R(i, N) {
		int A, B, C; cin >> A >> B >> C;
		X[i] = A, Y[i] = B, Z[i] = C;
		data[mp(A, B)].insert(mp(C, i));
	}
	
	vi endData;
	
	map<int, set<pair<pi, int> > > data2;
	
	for (auto it = data.begin(); it != data.end(); it++) {
		set<pair<int, int> > cur;
		vi inputs;
		cur = it->s;
		for (auto it2 = cur.begin(); it2 != cur.end(); it2++) {
			inputs.pb(it2->s);
		}
		
		
		for (int i = 1; i < sz(inputs); i+=2) {
			cout << inputs[i] + 1 << " " << inputs[i-1] + 1 << endl;
		}
		if (sz(inputs) % 2 == 1) {
			int val = inputs[sz(inputs) - 1];
			data2[X[val]].insert(mp(mp(Y[val], Z[val]), val));

		}
	}
	
	for (auto it = data2.begin(); it != data2.end(); it++) {
		set<pair<pi, int> > cur;
		vi inputs;
		cur = it->s;
		for (auto it2 = cur.begin(); it2 != cur.end(); it2++) {
			inputs.pb(it2->s);
		}
		
		
		for (int i = 1; i < sz(inputs); i+=2) {
			cout << inputs[i] + 1 << " " << inputs[i-1] + 1 << endl;
		}
		if (sz(inputs) % 2 == 1) endData.pb(inputs[sz(inputs) - 1]);
	}
	
	for (int i = 1; i < sz(endData); i += 2) {
		cout << endData[i] + 1 << " " << endData[i-1] + 1 << endl;
	}

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE