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

vector< vector<pii> > e;

void addEdge(int v, int u, int c) {
    e[v].pb({u, c});
    e[u].pb({v, c});
}

const int maxn = 3000;
const i64 P = 998244353;
int c[maxn];

bool dfs(int v, int col) {
    if (c[v] != -1) return c[v] == col;
    c[v] = col;
    for (auto w: e[v]) if (!dfs(w.fi, col ^ w.se)) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s;
    cin >> s;
    int n = s.size();

    i64 ans = 0;
    for1(l, n - 1) {
        int off0 = 1, off1 = off0 + (n + 1) / 2, off2 = off1 + (l + 1) / 2;
        e.assign(off2, vector<pii>());
        addEdge(off1, 0, 1);
        forn(i, n) {
            if (s[i] == '?') continue;
            if (i >= l) {
                int p = min(i, n - i - 1);
                addEdge(off0 + p, 0, s[i] - '0');
            } else {
                int p = min(i, n - i - 1);
                int q = min(i, l - i - 1);
                addEdge(off0 + p, off1 + q, s[i] - '0');
            }
        }

        forn(i, off2) c[i] = -1;
        i64 z = (P + 1) / 2;
        forn(i, off2) {
            if (c[i] != -1) continue;
            if (!dfs(i, 0)) {
                z = 0;
                break;
            }
            (z *= 2) %= P;
        }
        (ans += z) %= P;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}