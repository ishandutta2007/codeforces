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
        int n, x, y;
        cin >> n >> x >> y;
        vi a(n);
        vi cnt(n + 1);
        vvi pos(n + 1);
        forn(i, n) {
            cin >> a[i], --a[i];
            ++cnt[a[i]];
            pos[a[i]].pb(i);
        }
        int unused = 0;
        while (cnt[unused]) ++unused;
        vi ans(n, -1);
        set<pii> byCnt;
        forn(i, n + 1) byCnt.insert(mp(cnt[i], i));
        forn(i, x) {
            int c = byCnt.rbegin()->se;
            ans[pos[c].back()] = c;
            pos[c].pop_back();
            byCnt.erase(mp(cnt[c], c));
            --cnt[c];
            byCnt.insert(mp(cnt[c], c));
        }
        auto it = byCnt.rbegin();
        int cUnused = n - y;
        vi ord;
        for (auto [x, y]: byCnt) ord.pb(y);
        vi pord1, pord2;
        for (int c: ord) for (int p: pos[c]) pord1.pb(p);
        rotate(all(ord) - 1, ord.end());
        for (int c: ord) for (int p: pos[c]) pord2.pb(p);
        bool ok = true;
        forn(i, pord1.size()) {
            int p1 = pord1[i], p2 = pord2[i];
            if (a[p1] == a[p2]) {
                if (!cUnused) ok = false;
                else --cUnused, ans[p1] = unused;
            } else {
                ans[p1] = a[p2];
            }
        }
        for (int x: pord1) if (cUnused && ans[x] != unused) ans[x] = unused, --cUnused;
        ok &= cUnused == 0;

        if (!ok) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int x: ans) cout << x + 1 << ' ';
            cout << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}