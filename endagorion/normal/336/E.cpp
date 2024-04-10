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

int n, k;
const i64 P = 1000000000 + 7;

vi64 timesx(vi64 a) {
    if (a.empty()) return {};
    a.insert(a.begin(), 0);
    if (a.size() > k + 1) a.resize(k + 1);
    return a;
}

vi64 &operator+=(vi64 &a, const vi64 &b) {
    if (a.size() < b.size()) a.resize(b.size());
    forn(i, b.size()) {
        a[i] += b[i];
        if (a[i] >= P) a[i] -= P;
    }
    return a;
}

vvi64 mul(vvi64 a, int m) {
    vvi64 c = a;
/*    int mm = (int)(a.size() - 1) ^ m;
    int rm = mm;
    while (1) {
        c[rm | m] += timesx(a[rm]);
        if (!rm) break;
        --rm; rm &= mm;
    }*/
    forn(i, a.size()) {
        if (i & m) continue;
        c[i | m] += timesx(a[i]);
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> k;
    vvi64 dp(1 << 4);
    dp[0] = {1};

    while (n--) {
        vvi64 ndp(1 << 12);
        forn(mask, 1 << 4) {
            int nmask = 0;
            forn(i, 4) {
                if (!((mask >> i) & 1)) continue;
                nmask |= 3 << (2 * i);
                nmask |= 1 << (8 + i);
            }
            ndp[nmask] += dp[mask];
        }
        forn(i, 4) ndp = mul(ndp, (3 << (2 * i)) + (1 << (8 + i)));
        forn(i, 4) ndp = mul(ndp, (15 << (2 * i)) % 255 + (((3 << i) % 15) << 8));
        forn(i, 8) ndp = mul(ndp, 1 << i);
        forn(i, 4) ndp = mul(ndp, (3 << (2 * i + 1)) % 255);

        vvi64 rdp(1 << 8);
        forn(mask, 1 << 12) {
            int nmask = (mask >> 8) * 17;
            rdp[nmask] += ndp[mask];
        }

        forn(i, 4) rdp = mul(rdp, 1 << i);
        dp.assign(1 << 4, {});
        forn(mask, 1 << 8) {
            int nmask = mask >> 4;
            dp[nmask] += rdp[mask];
        }
    }

    forn(i, 4) dp = mul(dp, 1 << i);
    forn(i, 4) dp = mul(dp, (3 << i) % 15);

    vi64 ans;
    forn(mask, 1 << 4) ans += dp[mask];

    ans.resize(k + 1);
//    forn(i, k + 1) cerr << ans[i] << ' ';
//    cerr << '\n';
    i64 res = ans[k];
    for1(i, k) (res *= i) %= P;
    cout << res << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}