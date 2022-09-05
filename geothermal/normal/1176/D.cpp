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
const int MX = 200100; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vi primes;
    bool isPrime[MX]; isPrime[1] = true;
    FOR(i, 2, 500) {
        bool good = true;
        F0R(j, sz(primes)) {
            if (i % primes[j] == 0) {
                good = false;

            }
        }
        isPrime[i] = good;
        if (good) primes.pb(i);

    }

    vi largePrimes;
    F0R(i, sz(primes)) largePrimes.pb(primes[i]);
    FOR(i, 500, MX) {
        bool good = true;
        F0R(j, sz(primes)) {
            if (i % primes[j] == 0) {
                good = false;

            }
        }
        isPrime[i] = good;
        if (good) largePrimes.pb(i);
    }

    vi data;
    int N; cin >> N;
    F0R(i, 2*N) {
        int cur; cin >> cur;
        data.pb(cur);
    }
    vi ans;

    int countRem[MX]; F0R(i, MX) countRem[i] = 0;
    sort(all(data));
    vi unmatched;
    F0Rd(i, sz(data)) {
        int cur = data[i];
        if (cur >= MX) {
            unmatched.pb(cur);
        } else {
            if (countRem[cur] > 0) {
                countRem[cur]--;
            } else if (isPrime[cur]) {
                unmatched.pb(cur);
            } else {
                int res;
                F0R(j, sz(primes)) {
                    if (cur % primes[j] == 0) {
                        res = cur / primes[j];
                        goto found;
                    }
                }
                found:;
                ans.pb(cur);
                countRem[res]++;
            }
        }
    }

    reverse(all(unmatched));
    F0R(i, sz(unmatched)) {
        int cur = unmatched[i];
        if (cur < MX && countRem[cur] > 0) {
            countRem[cur]--;
        } else if (cur < MX) {
            ans.pb(cur);
            if (cur - 1 < sz(largePrimes)) {
                countRem[largePrimes[cur-1]]++;
            }
        }
    }


    F0R(i, sz(ans)) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343