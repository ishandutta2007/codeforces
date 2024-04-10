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
        int n, m;
        cin >> n >> m;
        vi64 a(n);
        forn(i, n) cin >> a[i];
        sort(rall(a));
        a.resize(m);
        reverse(all(a));
        vvi64 g(m);
        vi64 sg(m);
        forn(i, m) {
            int k;
            cin >> k;
            g[i].resize(k);
            for (auto &x: g[i]) {
                cin >> x;
                sg[i] += x;
            }
        }

        auto gcomp = [&](int i, int j) {
            return sg[i] * g[j].size() < sg[j] * g[i].size();
        };
        vi gord(m), gpos(m);
        iota(all(gord), 0);
        sort(all(gord), gcomp);
        forn(i, m) gpos[gord[i]] = i;

        auto gfit = [&](int i, int j) {
            return a[i] * g[j].size() >= sg[j];
        };

        vi mf(m + 1), mfl(m + 1), mfr(m + 1);
        ford(i, m) {
            mf[i] = gfit(i, gord[i]) ? mf[i + 1] + 1 : 0;
            mfl[i] = i && gfit(i, gord[i - 1]) ? mfl[i + 1] + 1 : 0;
            mfr[i] = i + 1 < m && gfit(i, gord[i + 1]) ? mfr[i + 1] + 1 : 0;
        }                         

        string ans;
        forn(i, m) {
            int from = gpos[i];
            for (int x: g[i]) {
                i64 ns = sg[i] - x;
                i64 nsz = g[i].size() - 1;
                int L = -1, R = gord.size();
                while (R - L > 1) {
                    int M = (L + R) / 2, j = gord[M];
                    (sg[j] * nsz <= ns * g[j].size() ? L : R) = M;
                }
                int to = R;
                if (to > from) --to;
                bool ok = a[to] * nsz >= ns;
//                cerr << i << ' ' << x << ' ' << from << ' ' << to << ' ' << nsz << ' ' << ns << ' ' << a[to] << ' ' << ok << ' ' << mf[0] << '\n';
//                cerr << mf[0] << ' ' << mfr[from] << ' ' << mf[to + 1] << '\n';
                if (from <= to) ok &= mf[0] >= from && mfr[from] >= to - from && mf[to + 1] >= m - to - 1;
                else ok &= mf[0] >= to && mfl[to + 1] >= from - to && mf[from + 1] >= m - from - 1;
                ans += (ok ? '1' : '0');
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}