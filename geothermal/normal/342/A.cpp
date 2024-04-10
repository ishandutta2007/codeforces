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
	int count[8]; F0R(i, 8) count[i] = 0;
	F0R(i, N) {
		int cur; cin >> cur;
		count[cur]++;
	}
	if (count[5] > 0 || count[7] > 0) {
		cout << -1 << endl; return 0;
	}
	int countFours = count[4];
	count[4] -= countFours; count[2] -= countFours; count[1] -= countFours;
	if (count[2] + count[3] != count[6]) {
		cout << -1 << endl; return 0;
	}
	F0R(i, 8) {
		if (count[i] < 0) {
			cout << -1 << endl; return 0;
		}
	}
	int countSix = count[6]; int countTwo = count[2], countThree = count[3]; count[6] = 0; count[2] = 0; count[3] = 0; count[1] -= countSix;
	F0R(i, 8) {
		if (count[i] != 0) {
			cout << -1 << endl; return 0;
		}
	}
	F0R(i, countFours) {
		cout << "1 2 4" << endl;
	}
	F0R(i, countTwo) {
		cout << "1 2 6" << endl;
	}
	F0R(i, countThree) {
		cout << "1 3 6" << endl;
	}
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343