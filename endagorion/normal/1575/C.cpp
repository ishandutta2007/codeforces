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

const i64 P = 1000000000 + 7;

i64 c2(i64 n) {
    i64 a = n, b = n - 1;
    (a & 1 ? b : a) /= 2;
    a %= P; b %= P;
    return a * b % P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    vi64 cnt(k);
    i64 s = 0, ts = 0;

    i64 ans = 0;
    vi64 a(n);
    forn(i, n) {
        cin >> a[i];
        (ts += a[i]) %= k;
    }

    forn(i, n) {
        i64 x = a[i];
        s += x; s %= k;
        (ans += cnt[s]) %= P;
        ++cnt[s];
        (ans += cnt[(s - m * ts % k + k) % k]) %= P;
    }
//    forn(i, k) cerr << cnt[i] << ' ';
//    cerr << '\n';

    vi64 rcnt(k);
    if (s == 0) forn(i, k) rcnt[i] = m * cnt[i];
    else {
        i64 is = k - s;
        i64 sum = 0;
        forn(i, m) sum += cnt[is * i % k];
        i64 mod = 0;
        forn(i, k) {
            rcnt[mod] = sum;
            (mod += s) %= k;
            sum += cnt[mod];
            sum -= cnt[(mod + m * is) % k];
        }
    }

//    ++rcnt[m * s % k];
    forn(i, k) (rcnt[i] -= cnt[i]) %= P;
//    forn(i, k) cerr << rcnt[i] << ' ';
//    cerr << '\n';
    
    forn(i, k) {
        (ans += cnt[i] % P * rcnt[i]) %= P;
    }
    (ans *= m) %= P;
//    cout << ans << '\n';
    if (m * s % k == 0) (ans += P - (1LL * n * m - 1) % P) %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}