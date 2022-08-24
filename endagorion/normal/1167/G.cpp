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

const int D = 7008;
using bs = bitset<2 * D>;
bs L, R;
int lx = -2 * D, rx = -D;
int lptr = 0, rptr = 0;

const int maxn = 410000;
int xs[maxn];
set<int> dx;
ld angle[D];

const ld PI = atan2(0, -1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    angle[0] = PI / 2;
    for1(i, D - 1) angle[i] = atan(1.0 / i);

    int n, d;
    cin >> n >> d;
    forn(i, n) {
        cin >> xs[2 * i];
        xs[2 * i + 1] = xs[2 * i] + 1;
        if (i && xs[2 * i] == xs[2 * i - 1]) dx.insert(xs[2 * i]);
    }
    n *= 2;

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        if (dx.count(x)) {
            cout << PI << '\n';
            continue;
        }
        while (x - lx >= D) {
            lx += D;
            L = L >> D;
            while (lptr < n && xs[lptr] < lx + 2 * D) L[xs[lptr++] - lx] = 1;
        }
        while (rx < x) {
            rx += D;
            R = R << D;
            while (rptr < n && xs[rptr] <= rx) R[rx - xs[rptr++]] = 1;
        }
        auto lb = L >> (x - lx), rb = R >> (rx - x);
        rb[0] = 0;
        ld ang = 0;
        if (lb.any()) uax(ang, angle[lb._Find_first()]);
        if (rb.any()) uax(ang, angle[rb._Find_first()]);
        auto cb = lb & rb;
//        cerr << x << ' ' << lb << ' ' << rb << ' ' << cb << '\n';
        if (cb.any()) uax(ang, 2 * angle[cb._Find_first()]);
        cout << ang << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}