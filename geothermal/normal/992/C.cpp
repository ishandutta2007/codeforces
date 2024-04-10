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

const ll MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

ll modPow(ll n) {
    if (n >= 2) {
        ll start = modPow(n / 2);
        start = start * start;
        start = start % MOD;
        if (n % 2 == 1) start = start * 2;
        start = start % MOD;
        return start;
    } else if (n == 1) {
        return 2;
    } else {
        return 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll x, k; cin >> x >> k;
    if (x == 0) {
        cout << 0;
        return 0;
    }
    x = x % MOD;
    ll ans = modPow(k + 1);
    ans = ans * x;
    ans = ans % MOD;
    ans = ans + 100 * MOD;
    ans = ans - modPow(k) + 1;
    ans = ans % MOD;
    cout << ans;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343