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
const int MX = 100001;

ll gcd(ll A, ll B) {
    if (A == 0) return B;
    if (A > B) {
        ll C = A;
        A = B;
        B = C;
    }
    return gcd(B % A, A);
}

ll lcm(ll A, ll B) {
    return (A * B) / gcd(A, B);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int T;
    cin >> T;
    vi primes;
    FOR(i, 2, 1001) {
        F0R(j, sz(primes)) {
            if (i % primes[j] == 0) goto bad;
        }
        primes.pb(i);
        bad:;
    }
    vi largePrimes;
    FOR(i, 1001, 1000000) {
        F0R(j, sz(primes)) {
            if (i % primes[j] == 0) goto badB;
        }
        largePrimes.pb(i);
        badB:;
    }
    F0R(i, sz(largePrimes)) primes.pb(largePrimes[i]);
    F0R(testNum, T) {
        int N; cin >> N;
        ll mn = 1e10;
        ll mx = 0;
        vl data;
        F0R(i, N) {
            ll cur; cin >> cur;
            data.pb(cur);
            mn = min(mn, cur);
            mx = max(mx, cur);
        }
        ll oldAns = mn * mx;
        ll ans = mn * mx;
        ll totalFacs = 1;
        F0R(i, N) {
            if (ans % data[i] != 0) {
                cout << -1 << endl; goto doneQ;
            }
        }

        F0R(i, sz(primes)) {
                ll count = 1;
                while (ans % primes[i] == 0) {
                    count++; ans = ans / primes[i];
                }
                totalFacs *= count;
        }

        if (totalFacs - 2 != N) {
            cout << -1 << endl; goto doneQ;
        }
        cout << oldAns << endl;

        doneQ:;

    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343