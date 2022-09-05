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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001;

ll modPow(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modPow(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll dpSame[200010][2];
ll dpDif[200010][2];
ll k;

ll solve(vl data) {
    vi types;
    vi lengths;
    int start = 0;
    int count = 0;
    ll ans = 1;
    F0R(i, sz(data)) {
        if (data[i] == -1) {
            count++;
        } else {
            if (start == 0) {
               ans = ans * modPow(k-1, count);
               count = 0;
               start = data[i];
            } else if (count == 0) {
                if (start == data[i]) {
                    return 0;
                } else {
                    start = data[i];
                    count = 0;
                }
            } else {
                if (start == data[i]) {
                    ans = ans * dpSame[count][1]; ans = ans % MOD;
                    count = 0;
                } else {
                    ans = ans * dpDif[count][1]; ans = ans % MOD;
                    start = data[i];
                    count = 0;
                }
            }
        }
    }

    if (start == 0) {
        ans = ans * modPow(k-1, count-1) * k;
    } else {
        ans = ans * modPow(k-1, count);
    }
    ans = ans % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n >> k;

    int a[n]; F0R(i, n) cin >> a[i];

    dpDif[0][1] = 1;
    dpDif[0][0] = 0;
    dpSame[0][1] = 0;
    dpSame[0][0] = 1;

    FOR(i, 1, n+1) {
        dpDif[i][0] = dpDif[i-1][1];
        dpDif[i][1] = dpDif[i-1][1] * (k-2) + dpDif[i-1][0] * (k-1);
        dpDif[i][1] = dpDif[i][1] % MOD;
        dpSame[i][0] = dpSame[i-1][1];
        dpSame[i][1] = dpSame[i-1][1] * (k-2) + dpSame[i-1][0] * (k-1);
        dpSame[i][1] = dpSame[i][1] % MOD;

    }


    /*int count = 0;
    int start = -1;
    ll ans = 1;
    for (int i = 1; i < n-1; i += 2) {
        int x = a[i-1];
        int y = a[i+1];
        if (x == -1 && y == -1) {
            if (start != -1) {
                count++;
            } else {
                ans = ans * (k - 1); ans = ans % MOD;
            }
        }
        else if (x == -1) {
            if (start == -1) {
                ans = ans * (k - 1); ans = ans % MOD;
            } else {

                if (y == start) {
                    ans = ans * dpSame[count][1];
                    ans = ans % MOD;
                } else {
                    ans = ans * dpDif[count][1];
                    ans = ans % MOD;
                }
                count = 0;
                start = -1;
            }

        }
        else if (y == -1) {
            count++;
            start = x;
        }
        else {
            if (x == y) {
                cout << 0 << endl;
                return 0;
            }
        }

    }

    if (a[n-2 + n % 2] == -1) {
        if (start != -1) {
            ans = ans * modPow(k - 1, count + 1);
        } else {
            ans = ans * k;
            ans = ans % MOD;
        }

    }
    count = 0;

    start = -1;
    for (int i = 2; i < n-1; i += 2) {
        int x = a[i-1];
        int y = a[i+1];
        if (x == -1 && y == -1) {
            if (start != -1) {
                count++;
            } else {
                ans = ans * (k - 1); ans = ans % MOD;
            }
        }
        else if (x == -1) {
            if (start == -1) {
                ans = ans * (k - 1); ans = ans % MOD;
            } else {
                count++;
                if (y == start) {
                    ans = ans * dpSame[count][1];
                    ans = ans % MOD;
                } else {
                    ans = ans * dpDif[count][1];
                    ans = ans % MOD;
                }
                count = 0;
                start = -1;
            }

        }
        else if (y == -1) {
            count++;
            start = x;
        }
        else {
            if (x == y) {
                cout << 0 << endl;
                return 0;
            }
        }

    }

    if (a[n-1 - n % 2] == -1) {
        if (start != -1) {
            ans = ans * modPow(k - 1, count + 1);
        } else {
            ans = ans * k;
            ans = ans % MOD;
        }

    }*/

    vl dataOdd, dataEven;
    F0R(i, n) {
        if (i % 2 == 0) {
            dataEven.pb(a[i]);
        } else {
            dataOdd.pb(a[i]);
        }
    }

    ll ans = solve(dataOdd) * solve(dataEven);
    ans = ans % MOD;


    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343