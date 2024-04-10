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

const int maxn = 310000;
i64 fs[maxn], f1[maxn];

void addf(i64 *f, int i, int x) {
    for (; i < maxn; i |= i + 1) f[i] += x;
}

i64 sumf(i64 *f, int i) {
    uin(i, maxn - 1);
    i64 s = 0;
    for (; i >= 0; i &= i + 1, --i) s += f[i];
    return s;
}

const int B = 500;
i64 mc[B][B];
int sm[B];

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
    i64 ans = 0;
    i64 total = 0;
    forn(i, n) {
        int x;
        cin >> x;
        if (x < B) {
            forn(i, x) ans += mc[x][i] * i;
            ans += 1LL * i * x;
            for1(y, x - 1) if (sm[y]) ans += x % y - x;
            sm[x] = 1;
        } else {
            int mr = maxn / x + 1;
            ans += total;
            vi64 ps1(mr + 1);
//            forn(i, mr + 1) pss[i] = fsum(fs, i * x);
            forn(i, mr + 1) ps1[i] = sumf(f1, i * x - 1);
            for1(i, mr) {
                ans -= 1LL * (ps1[i] - ps1[i - 1]) * x * (i - 1);
            }
//            cerr << ans << '\n';
            ans += 1LL * i * x;
            int k = 1;
            while (x / k >= B) {
                i64 sg = sumf(fs, x / k) - sumf(fs, x / (k + 1));
//                cerr << x << ' ' << k << ' ' << sg << '\n';
                ans -= sg * k;
                ++k;                
            }
            for1(y, x / k) if (sm[y]) ans += x % y - x;
        }

        addf(f1, x, 1);
        addf(fs, x, x);
        for1(y, B - 1) ++mc[y][x % y];
        total += x;
        cout << ans << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}