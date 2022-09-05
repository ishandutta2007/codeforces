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
    
    compPrimes(10000010);

    int N; cin >> N;
    //N = 1000000;
    vl data(N); F0R(i, N) cin >> data[i];
    //F0R(i, N) data[i] = 10000000 - i % 10;
    
    ll* best = new ll[10000010]; ll* index = new ll[10000010];
    int bestA, bestB;
    F0R(i, 10000010) {
        best[i] = 10000010;
        index[i] = -1;
    }
    ll ans = 1e16;
    bool* found = new bool[10000010]; F0R(i, 10000010) found[i] = false;
    F0R(i, N) {
        if (found[data[i]]) {
            if (data[i] < ans) {
                ans = data[i];
                bestA = index[data[i]];
                bestB = i;
            }
        } else {
            vpi factors;
            int cur = data[i];
            int last = leastFac[cur];
            cur /= last;
            int count = 1;
            while (cur > 1) {
                int nxt = leastFac[cur]; cur /= nxt;
                if (nxt == last) {
                    count++;
                } else {
                    factors.pb(mp(last, count));
                    //cout << last << " " << count << endl;
                    count = 1;
                    last = nxt;
                }
            }

            factors.pb(mp(last, count));
            //cout << last << " " << count << endl;

            vi divisors; divisors.pb(1);
            F0R(j, sz(factors)) {
                cur = sz(divisors);
                int A = factors[j].f, B = factors[j].s;
                F0R(X, B) {
                    F0R(Y, cur) {
                        divisors.pb(A*divisors[sz(divisors)-cur]);
                    }
                }
            }
            found[data[i]] = true;

        F0R(j, sz(divisors)) {
            if (divisors[j] >= 10000010) {
                //cout << "Broken " << i << " " << data[i] << " " << divisors[j] << endl; return 0;
            }
            ll val = data[i]; val = val * best[divisors[j]];
            ans = min(ans, val);
            if (ans == val) {
                bestA = index[divisors[j]];
                bestB = i;
            }
        }
        F0R(j, sz(divisors)) {
            best[divisors[j]] = min(best[divisors[j]], data[i] / divisors[j]);
            if (best[divisors[j]] == data[i] / divisors[j]) {
                index[divisors[j]] = i;
            }
        }
    }
    }

    cout << bestA + 1 << " " << bestB + 1 << endl;


    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343