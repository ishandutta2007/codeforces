#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define forn(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
typedef vector<int> vi;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 100179;

int n, m, p;
vi a, b;

bool read() {
    if (scanf("%d%d%d\n", &n, &m, &p) < 3) {
        return 0;
    }
    a.resize(n);
    b.resize(m);
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    forn(i, m) {
        scanf("%d", &b[i]);
    }
    return 1;
}

ll solve() {
    sort(all(a));
    sort(all(b));
    ll ans = 1e18, cur;
    for (int i = 0; i + n - 1 < m; i++) {
        cur = 0;
        forn(j, n) {
            cur = max(cur, 0ll + abs(a[j] - b[i + j]) + abs(b[i + j] - p));
        }
        ans = min(ans, cur);
    }
    return ans;
}
int main() {
#ifdef LOCAL
    assert(freopen("A.in", "r", stdin));
#endif
    ios::sync_with_stdio(false);

    while (read()) {
        cout << solve() << '\n';
    }

    return 0;
}