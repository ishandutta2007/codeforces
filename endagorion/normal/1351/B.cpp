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

const int maxn = 100;

int S(int lx, int ly, int rx, int ry) {
    return (rx - lx) * (ry - ly);
}

bool square(int lx1, int ly1, int rx1, int ry1, int lx2, int ly2, int rx2, int ry2) {
    if (max(lx1, lx2) < min(rx1, rx2) && max(ly1, ly2) < min(ry1, ry2)) return false;
    int lx = min(lx1, lx2), rx = max(rx1, rx2), ly = min(ly1, ly2), ry = max(ry1, ry2);
    return rx - lx == ry - ly && S(lx, ly, rx, ry) == S(lx1, ly1, rx1, ry1) + S(lx2, ly2, rx2, ry2);
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
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        bool ok = false;
        forn(z2, 2) {
            forn(z3, 2) {
                if (ok) break;
                forn(dx, min(a1, maxn - a2) + 1) forn(dy, min(b1, maxn - b2) + 1) ok |= square(0, 0, a1, b1, dx, dy, dx + a2, dy + b2);
                swap(a1, b1);
            }
            swap(a2, b2);
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}