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

const int maxn = (1 << 25) + 1;
const i64 P = 1051131;
int a[maxn];
i64 eig[26];
int eigc[maxn];
int E = 0;

template<class T>
void add(T &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

i64 deg(i64 x, i64 d) {
    if (x < 0) x += P;
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

    int m, s;
    i64 t;
    cin >> m >> t >> s;
    for1(i, s) cin >> a[i];
    fore(j, s + 1, 1 << m) a[j] = (101 * a[j - s] + 10007) % P;
    a[0] = a[1 << m];

    ford(k, m) {
        forn(i, 1 << k) {
            int s = a[i] - a[i + (1 << k)];
            if (s & 1) s += P;
            s /= 2;
            if (s < 0) s += P;
//            cerr << k + 1 << ' ' << i << ' ' << a[i] << ' ' << a[i + (1 << k)] << ' ' << s << '\n';
            eigc[E++] = s;
            add(a[i], P - s);
//            cerr << a[i] << ' ';
        }
//        cerr << '\n';
    }

    forn(k, m + 1) {
        eig[k] = k ? -(1 << (k - 1)) : 0;
        fore(j, k + 1, m) eig[k] = 2 * eig[k] + (1 << (j - 1));
        eig[k] %= P;
//        cerr << eig[k] << ' ';
        eig[k] = deg(eig[k] + 1, t);
//        cerr << eig[k] << '\n';
    }

//    forn(k, m + 1) cerr << eig[k] << ' ';
//    cerr << '\n';

//    forn(k, m + 1) cerr << eig[k] << ' ' << eigc[k] << '\n';

    a[0] = 1LL * a[0] * eig[0] % P;
    forn(k, m) {
        ford(i, 1 << k) {
            int s = eigc[--E];
            s = 1LL * s * eig[k + 1] % P;
            add(a[i + (1 << k)] = a[i], P - s);
            add(a[i], s);
        }
    }

//    forn(i, 1 << m) cerr << a[i] << ' ';
//    cerr << '\n';
    int X = 0;
    forn(i, 1 << m) X ^= a[i];
    cout << X << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}