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
        vi b(n);
        vvi byB(n + 2);
        forn(i, n) {
            cin >> b[i];
            byB[b[i]].pb(i + 1);
        }

        vi a;
        int val = byB[0].empty() ? n + 1 : 0;

        int lk = 0, rk = n + 1;
        int z = val == 0 ? 0 : 1;

        while (a.size() < n) {
            vvi vs(2);
            for (int x: byB[val]) {
                vs[!byB[x].empty()].pb(x);
                if (!z) uin(rk, x);
                else uax(lk, x);
            }
//            cerr << val << ' ' << vs[0].size() << ' ' << vs[1].size() << '\n';
            assert(vs[1].size() <= 1);
            forn(z, 2) for (int x: vs[z]) a.pb(x);
            if (vs[1].empty()) assert(a.size() == n);
            else {
                int nval = vs[1][0];
                val = nval;
                z ^= 1;
            }
        }

        assert(lk < rk);
        cout << lk << '\n';
        for (int x: a) cout << x << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}