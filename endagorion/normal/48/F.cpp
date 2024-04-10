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
typedef __float128 ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 510000;
i64 a[maxn], c[maxn], w[maxn];
int ord[maxn];

mt19937 rng;

bool better(int i, int j) {
    i64 V = c[i] * w[j] - c[j] * w[i];
    if (V) return V < 0;
    return i < j;
}

i64 whole;
ld part;

void nth(int L, int R, i64 W) {
    if (L == R) return;
    int p = L + rng() % (R - L);
    int v = ord[p];
    swap(ord[R - 1], ord[p]);
    int l = L, r = R - 1;
    while (l < r) {
        if (better(ord[l], v)) ++l;
        else swap(ord[l], ord[--r]);
    }
    swap(ord[r++], ord[R - 1]);
//    cerr << L << ' ' << R << ' ' << l << ' ' << r << ": ";
//    fore(i, L, R - 1) cerr << ord[i] << ' ';
//    cerr << '\n';
    i64 TL = 0;
    i64 whole1 = 0.0;
    fore(i, L, l - 1) TL += w[ord[i]], whole1 += c[ord[i]];
    if (TL > W) {
        nth(L, l, W);
        return;
    }
    whole += whole1;
    W -= TL;
    int mid = ord[l];
    if (W <= w[mid]) {
        whole += W * c[mid] / w[mid];
        part += (ld)1.0 * (W * c[mid] % w[mid]) / w[mid];
        return;
    }
    W -= w[mid];
    whole += c[mid];
    nth(r, R, W);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;
    cerr.precision(15);
    cerr << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int d, n, W;
    cin >> d >> n >> W;
    forn(i, n) cin >> w[i];
    forn(i, n) cin >> c[i];
    forn(i, n) cin >> a[i];

    iota(ord, ord + n, 0);
    ld ans = 0.0;
    forn(i, d) {
        nth(0, n, W);
//        cerr << (long double)(whole + part) << '\n';
        forn(j, n) c[j] -= a[j];
    }

    i64 extra = part;
    whole += extra;
    part -= extra;
    cout << whole << '.';
    cout.fill('0');
    cout.width(15);
    cout << i64(1e15 * part) << '\n';
//    cout << (long double)(whole + part) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}