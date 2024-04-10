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

int closed[9][9];
const int maxn = 110000;
int cnt[8];
int closemask[maxn];
int prv[maxn][8];

int close_enough[8][1 << 8];

int fastD[9], fastM[9];

pi64 operator+(pi64 a, pi64 b) {
    if (a.fi != b.fi) return max(a, b);
    a.se += b.se;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    string s;
    cin >> n >> s;

    if (s == string(n, s[0])) {
        cout << 1 << ' ' << 1LL * n * (n - 1) / 2 << '\n';
        return 0;
    }

    forn(j, 8) prv[0][j] = -1;
    forn(j, 8) forn(k, 8) closed[j][k] = 1e9;
    forn(i, n) {
        forn(j, 8) prv[i + 1][j] = prv[i][j];
        int k = s[i] - 'a';
        prv[i + 1][k] = i;

        ++cnt[k];
        forn(j, 8) {
            if (prv[i + 1][j] < 0) continue;
            uin(closed[j][k], i - prv[i + 1][j]);
            uin(closed[k][j], i - prv[i + 1][j]);
        }
    }

//    forn(j, 8) forn(k, 8) if (closed[j][k] < 1e8) cerr << j << ' ' << k << ' ' << closed[j][k] << '\n';

    forn(i, n) forn(j, 8) {
        int k = s[i] - 'a';
        int p = prv[i + 1][j];
        if (p < 0) continue;
        int d = i - p;
        if (d == closed[j][k]) {
            closemask[i] |= 1 << j;
            closemask[p] |= 1 << k;
        }
    }

//    forn(i, n) cerr << "closemask " << i << ' ' << closemask[i] << '\n';


    forn(i, n) {
        int k = s[i] - 'a';
        forn(mask, 1 << 8) if (mask & closemask[i]) ++close_enough[k][mask];
    }

    pi64 ans = mp(-1, 0);
    forn(i, n) {
        forn(j, 8) fastD[j] = 1e9, fastM[j] = 0;

        forn(j, 8) closed[j][8] = closed[8][j] = 1e9;

        fore(d, -15, 15) {
            int x = i + d;
            if (x < 0 || x >= n) continue;
            int xk = s[x] - 'a';
            if (abs(d) < closed[8][xk]) closed[8][xk] = closed[xk][8] = abs(d);
        }

//        forn(j, 8) if (closed[8][j] < 1e8) cerr << "closed " << i << ' ' << (char)('a' + j) << ' ' << closed[8][j] << '\n';

        fore(d, -15, 15) {
            int x = i + d;
            if (x < 0 || x >= n) continue;
            int xk = s[x] - 'a';
            if (abs(d) == closed[8][xk]) {
                fastD[xk] = abs(d);
                fastM[xk] = 1 << 8;
//                cerr << "fast " << i << ' ' << x << ' ' << abs(d) << '\n';
            }
        }

        vi vis(8);
        while (1) {
            int bj = -1;
            forn(j, 8) {
                if (vis[j] || fastD[j] > 1e8) continue;
                if (bj == -1 || fastD[j] < fastD[bj]) bj = j;
            }
            if (bj == -1) break;
            vis[bj] = 1;

            forn(k, 8) {
                int td = fastD[bj] + 1 + closed[bj][k];
                if (td < fastD[k]) fastD[k] = td, fastM[k] = 0;
                if (td == fastD[k]) fastM[k] |= 1 << bj;
            }
        }

        forn(j, 8) {
            if (!cnt[j]) continue;
            int fastN = close_enough[j][fastM[j] & 255];
//            cerr << i << ' ' << (char)('a' + j) << ' ' << fastD[j] << ' ' << fastM[j] << ' ' << fastN << '\n';
            if (fastM[j] & 256) {
                int cd = closed[8][j];
                for (int x: {i - cd, i + cd}) {
                    if (x < 0 || x > n || s[x] - 'a' != j) continue;
                    if (!(fastM[j] & closemask[x])) ++fastN;
                    if (!cd) break;
                }
            }

            pi64 p(fastN == cnt[j] ? mp(fastD[j], cnt[j]) : mp(fastD[j] + 1, cnt[j] - fastN));
//            cerr << i << ' ' << (char)('a' + j) << ' ' << fastD[j] << ' ' << fastM[j] << ' ' << p.fi << ' ' << p.se << '\n';
            ans = ans + p;
        }
    }

    assert(ans.se % 2 == 0);
    ans.se /= 2;
    cout << ans.fi << ' ' << ans.se << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}