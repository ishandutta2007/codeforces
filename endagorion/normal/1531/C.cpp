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

const int maxn = 101;
int can[maxn][maxn];

int get_can(int n, int s) {
    if (n == 0) return 1;
    if (s == 0) return 0;
    auto &res = can[n][s];
    if (res != -1) return res;
    if (get_can(n, s - 1)) return res = 1;
    if (n >= 2 * s - 1 && get_can(n - 2 * s + 1, s - 1)) return res = 1;
    return res = 0;
}

void restore(int n, int s, vector<string> &f, int i) {
    if (n == 0) return;
    while (s > 0 && get_can(n, s - 1)) --s;
    assert(get_can(n - 2 * s + 1, s - 1));
    forn(j, s) {
        f[i + j][i] = f[i][i + j] = 'o';
    }
    restore(n - 2 * s + 1, s - 1, f, i + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, maxn) forn(j, maxn) can[i][j] = -1;
    can[0][0] = 1;
    int n;
    cin >> n;
    int s = 0;
    while (s < maxn && !get_can(n, s)) ++s;
    if (s >= maxn) {
        cout << -1 << '\n';
        return 0;
    }
    vector<string> f(s, string(s, '.'));
    restore(n, s, f, 0);
    reverse(all(f));
    cout << s << '\n';
    for (auto w: f) cout << w << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}