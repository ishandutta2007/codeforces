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

i64 n;

void make_move(i64 &x, i64 &d) {
    x += d;
    if (x == 0) d = 1;
    if (x == n - 1) d = -1;
}

i64 last_to_delete(i64 x, i64 d) {
    if (x == 0) return n - 1;
    if (x == n - 1) return 0;
    return d == 1 ? 0 : n - 1;
}

i64 coord(i64 x, i64 d) {
    if (d == 1) return x;
    return 2 * n - 2 - x;
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
        i64 a, b;
        string sda, sdb;
        i64 da, db;
        cin >> n >> a >> b;
        cin >> sda >> sdb;
        da = (sda == "left" ? -1 : 1);
        db = (sdb == "left" ? -1 : 1);
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        int att = ((a & 1) == (b & 1) ? 1 : 0);
        i64 ca = coord(a, da), cb = coord(b, db);
        i64 per = 2 * n - 2;
        i64 lab = (cb - ca + per) % per, lba = (ca - cb + per) % per;
        i64 ans;
        if (lab == 0) {
            ans = last_to_delete(a, da);
        } else if (lab == 1) {
            ans = last_to_delete(b, db);
        } else {
            i64 sda = da;
            if (da == -1 && b > a) sda = -sda;
            if (da == 1 && b < a) sda = -sda;

            i64 z = min(lab, lba) - 1;
            lab -= z;
            lba -= z;
            if (z & 1) {
                sda *= -1;
                att ^= 1;
            }
            if (lab == 1) {
                ans = (sda == 1 ? 0 : n - 1);
            } else {
                ans = (sda == 1 ? 0 : n - 1);
            }
        }

        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}