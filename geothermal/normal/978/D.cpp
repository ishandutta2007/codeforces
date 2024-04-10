#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

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

const int MOD = 1000000007;
const ll INF = (ll) 1e18;
const int MX = 100001;

ll arr[MX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	if (N <= 2) {
		cout << 0;
		return 0;
	}
	F0R(i, N) cin >> arr[i];

	int best = MX;

	FOR(difA, -1, 2) {
		FOR(difB, -1, 2) {
			ll a = arr[0] + difA;
			ll b = arr[1] + difB;
			int count = 0; if (difA != 0) count++; if (difB != 0) count++;
			ll cur = 2 * b - a;
			FOR(i, 2, N) {
				if (abs(cur - arr[i]) == 1) {
					count++;
				}
				else if (cur != arr[i]) {
					goto outer;
				}
				cur += b - a;
			}
			if (count < best) best = count;
		outer: int tmp;
		}
	
	}

	if (best == MX) {
		cout << -1;
	}
	else cout << best;

	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)