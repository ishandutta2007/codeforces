#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 1100000;
int mind[maxn];
i64 x[maxn], fx[maxn];
vi ps;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    mt19937_64 rng;
    int n;
    cin >> n;
    forn(i, n + 1) mind[i] = i;
    fore(i, 2, n) {
        if (mind[i] == i) {
            ps.pb(i);
            x[i] = rng();
        }
        for (int p: ps) {
            if (p > mind[i] || p * i > n) break;
            mind[i * p] = p;
            x[i * p] = x[i] ^ x[p];
        }
    }

    i64 X = 0;
    for1(i, n) X ^= (fx[i] = fx[i - 1] ^ x[i]);

    bool done = false;
    vi exc;
    if (!X) done = true;
    if (!done) {
        for1(i, n) if (fx[i] == X) {
            exc = {i};
            done = true;
        }
    }
    if (!done) {
        map<i64, int> m;
        for1(i, n) {
            if (m.count(fx[i])) {
                done = true;
                exc = {i, m[fx[i]]};
                break;
            }
            m[X ^ fx[i]] = i;
        }
    }

    if (!done) {
        assert(n & 1);
        exc = {n, n / 2, 2};
    }

    cout << n - exc.size() << '\n';
    for1(i, n) if (!count(all(exc), i)) cout << i << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}