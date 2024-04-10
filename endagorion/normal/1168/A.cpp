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

    int n, m;
    cin >> n >> m;
    vi a(n);
    forn(i, n) cin >> a[i];
    int L = -1, R = m;
    while (R - L > 1) {
        int k = (L + R) / 2;
        int z = 0;
//        cerr << k << ": ";
        forn(i, n) {
            int y = m;
            int L = a[i], R = min(m - 1, a[i] + k);
            if (L <= z && z <= R) uin(y, z);
            if (z <= L) uin(y, L);
            L = 0, R = a[i] + k - m;
            if (L <= z && z <= R) uin(y, z);
            if (L <= R && z <= L) uin(y, L);
            z = y;
//            cerr << z << ' ';
        }
//        cerr << '\n';
        (z < m ? R : L) = k;
    }
    cout << R << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}