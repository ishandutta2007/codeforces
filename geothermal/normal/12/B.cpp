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
	
	int N; string dM; cin >> N >> dM;
	if (dM[0] == '0') {
		if (N == 0 && sz(dM) == 1) {
			cout << "OK" << endl; return 0;
		}
		cout << "WRONG_ANSWER" << endl;
		return 0;
	}
	int M = 0;
	F0R(i, sz(dM)) {
		M *= 10;
		M += dM[i] - '0';
	}
	int ans = 0;
	int counts[10]; F0R(i, 10) counts[i] = 0;
	int C = 0;
	while (N > 0) {
		counts[N%10]++;
		N /= 10;
		C++;
	}
	
	bool found = false;
	F0R(i, C) {
		F0R(j, 10) {
			if (!found && j == 0) continue;
			if (counts[j] == 0) continue;
			ans *= 10;
			ans += j;
			counts[j]--;
			found = true;
			break;
		}
	}
	//cout << ans << endl;
	
	string res = ans == M ? "OK" : "WRONG_ANSWER";
	cout << res << endl;
	
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343