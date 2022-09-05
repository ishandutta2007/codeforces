#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 1001; //check the limits, dummy

int N, M; 

bool check(int val, int cap, int oth, bool ord) {
    if ((cap/val) % 2) {
        if (ord) {
            cout << "? " << (cap-val)/2 << " " << M << " " << 1 << " " << 1 << " "<< 1+(cap-val)/2 << " " << 1 << endl;
            int X; cin >> X;
            cout << "? " << val << " " << M << " " << 1 << " " << 1 << " " << cap-val+1 << " " << 1 << endl;
            int Y; cin >> Y;
            return X && Y;
        } else {
            cout << "? " << N << " " << (cap-val)/2 << " " << 1 << " " << 1 << " " << 1 << " " << 1+(cap-val)/2 << endl;
            int X; cin >> X;
            cout << "? " << N << " " << val << " " << 1 << " " << 1 << " " << 1 << " " << cap-val+1 << endl;
            int Y; cin >> Y;
            return X && Y;
        }
    } else {
        if (ord) {
            cout << "? " << cap/2 << " " << M << " " << 1 << " " << 1 << " "<< 1+cap/2 << " " << 1 << endl;
            int X; cin >> X;
            return X;
        } else {
            cout << "? " << N << " " << cap/2 << " " << 1 << " " << 1 << " " << 1 << " " << 1+cap/2 << endl;
            int X; cin >> X;
            return X;
        }
    }
}


vi primes, leastFac;
void compPrimes(int N) {
	F0R(i, N) {
		leastFac.pb(0);
	}
	leastFac[0] = 1; leastFac[1] = 1;
	FOR(i, 2, N) {
		if (leastFac[i] == 0) {
			primes.pb(i);
			leastFac[i] = i;
		}
		for (int j = 0; j < sz(primes) && i*primes[j] < N && primes[j] <= leastFac[i]; j++) {
			leastFac[i*primes[j]] = primes[j];
		}
	}
}

void solve() {

    compPrimes(MX);
    cin >> N >> M;
    int cn = N, cm = M;
    map<int, int> val[2];
    int ncap = N, mcap = M;
    while (cn > 1) {
        int X = leastFac[cn];
        cn /= X;
        if (check(ncap / X, ncap, M, true)) {
            ncap /= X;
            val[0][X]++;
        }
    }
    while (cm > 1) {
        int X = leastFac[cm];
        cm /= X;
        if (check(mcap / X, mcap, N, false)) {
            mcap /= X;
            val[1][X]++;
        }
    }
    int ans = 1;
    F0R(i, 2) trav(a, val[i]) ans *= a.s+1;
    cout << "! " << ans << endl;


}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343