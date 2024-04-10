#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

ll n;
ll getcnt(ll m) {
    if (m == 0) {
        return 0;
    } else if (m == 1) {
        return 1;
    } else {
        return 1 + 3 * m * (m - 1);
    }
}

pair<ll, ll> mv[6] = {{-1, 2}, {-2, 0}, {-1, -2}, {1, -2}, {2, 0}, {1, 2}};

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    cin >> n;
    if (n == 0) {
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    ll l = 0, r = 1e9;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (getcnt(mid) <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    n -= getcnt(l);
    n += 1;
    n %= max(1ll, 6 * l);
    pair<ll, ll> cur(2 * l, 0);
    for (int r = 0; n > 0; n -= min(n, l), r++) {
        assert(r < 6);
        cur.fs += min(n, l) * mv[r].fs;
        cur.sc += min(n, l) * mv[r].sc;
    }
    cout << cur.fs << ' ' << cur.sc << endl;
    return 0;
}