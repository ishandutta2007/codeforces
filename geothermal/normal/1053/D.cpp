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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
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
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    compPrimes(2000000);
    int P = sz(primes);
    int cnt[P]; F0R(i, P) cnt[i] = 0;
    int num[P][25]; F0R(i, P) F0R(j, 25) num[i][j] = 0;
    map<int, int> pos; F0R(i, P) pos.insert({primes[i], i});
    int N; cin >> N;
    vi data(N); F0R(i, N) cin >> data[i];

	sort(all(data)); reverse(all(data));
    int add = 0;
    F0R(i, N) {
        int cur = data[i];
        int p = pos[cur];
        if (cnt[p] > 0) {
            cur--;
            F0R(j, 300) {
                int X = 0;
                while (cur % primes[j] == 0) {
                    X++; cur /= primes[j];
                }
                cnt[j] = max(cnt[j], X);
                num[j][X]++;
            }
            if (cur > 1) {
                int val = pos[cur];
                num[val][1]++;
                cnt[val] = max(cnt[val], 1);
            }
        } else {
            num[p][1]++;
            cnt[p] = 1;
        }
    }
    ll ans = 1;
    F0R(i, P) {
        F0R(j, cnt[i]) {
            ans *= primes[i]; ans %= MOD;
        }

    }
    F0R(i, N) {
        bool found = false;
        if (num[pos[data[i]]][1] == 1 && cnt[pos[data[i]]] == 1) found = true;
        if ((i > 0 && data[i-1] == data[i]) || (i < N-1 && data[i+1] == data[i])) found = false;
        int cur = data[i]-1;
        F0R(j, 300) {
            int X = 0;
            while (cur % primes[j] == 0) {
                X++; cur /= primes[j];
            }
            if (primes[j] < data[i] && cnt[j] == X && num[j][X] == 1) found = true;
        }
        if (cur > 1) {
            int val = pos[cur];
            if (val < data[i] && cnt[val] == 1 && num[val][1] == 1) found = true;
        }
        if (!found) {
            add = 1;
//            cout << data[i] << endl;
        }

    }
    ans += add; ans %= MOD;
    cout << ans << endl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343