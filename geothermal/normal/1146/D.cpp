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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll m; int a, b; cin >> m >> a >> b;
    int mods[a];
    F0R(i, a) mods[i] = -1;
    mods[0] = 0;
    int cur = 0;
    int mx = 0;
    while (true) {
        if (cur < b) {
            cur += (b/a) * a;
            if (cur < b) cur += a;
            if (cur > m) break;
            mx = max(mx, cur);
        }
        cur -= b;
        if (mods[cur] != -1) {
            break;
        }
        mods[cur] = mx;
    }
    ll ans = 0;
    F0R(i, a) {
        if (mods[i] != -1) {

            ll countUnder = (mods[i] - i) / a + 1;
            ans += (ll) (m - mods[i] + 1) * countUnder;

            ll maxMult = (m - i) / a;
            ans -= (maxMult - countUnder + 1) * i;
            ll cur = maxMult * maxMult + maxMult;
            cur = cur / 2;
            countUnder--;
            cur -= (countUnder * countUnder + countUnder) / 2;
            ans -= cur * a;
            ans += (maxMult - countUnder) * (m+1);
        }

    }
    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343