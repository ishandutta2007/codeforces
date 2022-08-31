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

int h[22][360], v[22][360];
int vis[22][360];

void dfs(int r, int phi) {
    phi = (phi + 360) % 360;
    if (vis[r][phi]) return;
    vis[r][phi] = 1;
    if (r && !h[r][phi]) dfs(r - 1, phi);
    if (r + 1 < 22 && !h[r + 1][phi]) dfs(r + 1, phi);
    if (!v[r][phi]) dfs(r, phi - 1);
    if (!v[r][(phi + 1) % 360]) dfs(r, phi + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        forn(r, 22) forn(phi, 360) h[r][phi] = v[r][phi] = vis[r][phi] = 0;
        int n;
        cin >> n;
        while (n--) {
            char c;
            cin >> c;
            if (c == 'C') {
                int r, phi1, phi2;
                cin >> r >> phi1 >> phi2;
                while (phi1 != phi2) {
                    h[r][phi1] = 1;
                    ++phi1; phi1 %= 360;
                }
            } else {
                int r1, r2, phi;
                cin >> r1 >> r2 >> phi;
                while (r1 < r2) v[r1++][phi] = 1;
            }
        }

        dfs(0, 0);
        cout << (vis[21][0] ? "YES" : "NO") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}