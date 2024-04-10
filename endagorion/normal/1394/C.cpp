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

struct THex {
    int lx, ux, ly, uy, ld, ud;

    bool empty() const {
        return lx > ux || ly > uy || ld > ud;
    }

    void norm() {
        while (!empty()) {
            bool any = false;
            any |= uin(ud, uy - lx);
            any |= uax(ld, ly - ux);
            any |= uin(ux, uy - ld);
            any |= uax(lx, ly - ud);
            any |= uin(uy, ud + ux);
            any |= uax(ly, ld + lx);
            if (!any) break;
        }
    }

    THex operator+(THex &h) const {
        THex res = {max(lx, h.lx), min(ux, h.ux), max(ly, h.ly), min(uy, h.uy), max(ld, h.ld), min(ud, h.ud)};
        res.norm();
        return res;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    vector<pii> a(n);
    forn(i, n) {
        string s;
        cin >> s;
        for (char c: s) ++(c == 'B' ? a[i].fi : a[i].se);
    }

    int L = -1, R = 1e6;
    pii ans;
    while (R - L > 1) {
        THex inter = {-(int)1e8, (int)1e8, -(int)1e8, (int)1e8, -(int)1e8, (int)1e8};
        int M = (L + R) / 2;
        forn(i, n) {
            THex hex = {a[i].fi - M, a[i].fi + M, a[i].se - M, a[i].se + M, a[i].se - a[i].fi - M, a[i].se - a[i].fi + M};
            inter = inter + hex;
            if (inter.empty()) break;
        }
        bool ok = !inter.empty() && (inter.ux > 0 || inter.uy > 0);
        if (ok) R = M, ans = {inter.ux, inter.uy};
        else L = M;
    }
    cout << R << '\n';
    cout << string(ans.fi, 'B') << string(ans.se, 'N') << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}