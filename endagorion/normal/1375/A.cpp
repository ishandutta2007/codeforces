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
        int n;
        cin >> n;
        int x;
        cin >> x;
        cout << x << ' ';
        --n;
        while (n) {
            int y, z;
            cin >> y >> z;
            int ry, rz;
            bool done = false;
            forn(my, 2) forn(mz, 2) {
                if (done) break;
                int sy = y * (my ? 1 : -1), sz = z * (mz ? 1 : -1);
                int d1 = x - sy, d2 = sy - sz;
                int pos = 0, neg = 0;
                if (d1 >= 0) ++pos;
                if (d1 <= 0) ++neg;
                if (d2 >= 0) ++pos;
                if (d2 <= 0) ++neg;
                if (pos > 0 && neg > 0) {
                    ry = sy, rz = sz;
                    done = true;
                }
            }
            assert(done);
            cout << ry << ' ' << rz << ' ';
            x = rz;
            n -= 2;
        }
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}