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

const int maxa = 110000;
const i64 P = 998244353;
i64 cnt[maxa + 1], mu[maxa + 1];

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int m;
    cin >> m;
    while (m--) {
        int x, c;
        cin >> x >> c;
        cnt[x] = c;
    }

    mu[1] = 1;
    for1(i, maxa) fore(j, 2, maxa / i) mu[i * j] -= mu[i];

    i64 ans = 0;
    for1(i, maxa) {
        if (!mu[i]) continue;
        i64 S0 = 0, S1 = 0, S2 = 0;
        for (int j = i; j <= maxa; j += i) {
            S0 += cnt[j];
            (S1 += cnt[j] * j) %= P;
            (S2 += cnt[j] * j % P * j) %= P;
        }
        i64 res = 0;
        if (S0 > 1) {
//            cerr << i << ' ' << S0 << ' ' << S1 << ' ' << S2 << '\n';
            i64 p2 = deg(2, S0 - 2);
            (res += (S0 - 1) % P * p2 % P * S2) %= P;
            (res += (S1 * S1 - S2) % P * p2) %= P;
            if (S0 > 2) (res += (S1 * S1 - S2) % P * ((S0 - 2) % P) % P * p2 % P * (P + 1) / 2) %= P;
        }
        (ans += res * mu[i]) %= P;
    }
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}