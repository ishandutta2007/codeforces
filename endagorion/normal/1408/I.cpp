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

const int maxl = 16;
const i64 P = 998244353;
int a[1 << maxl];
i64 tr[1 << maxl][maxl + 1];
i64 buf[maxl + 1], b1[maxl + 1], b2[maxl + 1];
int pc[1 << maxl];

i64 fact[maxl + 1], tcaf[maxl + 1];
i64 ans[1 << maxl];

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

int n, k, c;

void mul(i64 *a, i64 *b, i64 *c) {
    forn(i, k + 1) c[i] = 0;
    forn(i, k + 1) forn(j, k - i + 1) (c[i + j] += a[i] * b[j]) %= P;
}

void dnc(int s, int b) {
    if (!b) return;
//    cerr << s << ' ' << b << '\n';
    int m = s + (1 << (b - 1)), e = s + (1 << b);
    dnc(s, b - 1);
    dnc(m, b - 1);
    int rhc = (1 << (b - 1)) >= k ? accumulate(a + m + k, a + e, 0) % 2 : 0;
    forn(i, 1 << (b - 1)) {
        forn(z, k + 1) {
            b1[z] = tr[s + i][z];
            b2[z] = tr[m + i][z];
        }
        mul(b1, b2, tr[s + i]);
        forn(z, k + 1) tr[m + i][z] = tr[s + i][z] * (rhc ? -1 : 1);
    }
    fore(i, max(s + k, m), min(e - 1, m + k - 1)) {
        if (!a[i]) continue;
//        cerr << i << ' ' << s << ' ' << b << '\n';
        forn(j, 1 << b) {
            forn(z, k + 1) b1[z] = tcaf[z] * (pc[(i - z) & j] & 1 ? -1 : 1);
            mul(tr[s + j], b1, b2);
            forn(z, k + 1) tr[s + j][z] = b2[z];
        }
    }
}

void dnc1(int s, int b) {
    if (!b) return;
    dnc1(s, b - 1);
    dnc1(s + (1 << (b - 1)), b - 1);
    forn(i, 1 << (b - 1)) {
        i64 x = ans[s + i], y = ans[s + i + (1 << (b - 1))];
        ans[s + i] = (x + y) % P;
        ans[s + i + (1 << (b - 1))] = (x - y) % P;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    fact[0] = 1;
    for1(i, maxl) fact[i] = fact[i - 1] * i % P;
    forn(i, maxl + 1) tcaf[i] = deg(fact[i], -1);

    forn(i, 1 << maxl) pc[i] = __builtin_popcount(i);

    cin >> n >> k >> c;
    forn(i, n) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    forn(i, 1 << c) tr[i][0] = 1;
    dnc(0, c);

    forn(i, 1 << c) ans[i] = tr[i][k];
    dnc1(0, c);
    int S = accumulate(a, a + (1 << c), 0);
    i64 iS = deg(S, -k);
    forn(i, 1 << c) {
        (ans[i] *= fact[k]) %= P;
        (ans[i] *= iS) %= P;
        (ans[i] *= deg(2, -c)) %= P;
        if (ans[i] < 0) ans[i] += P;
        cout << ans[i] << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}