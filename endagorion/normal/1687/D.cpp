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

const int maxn = 1100000;
int a[maxn];
int L[maxn], R[maxn];

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
    int V = 0;
    forn(i, n) {
        int x;
        cin >> x;
        if (V && x == a[V - 1]) continue;
        else a[V++] = x;
    }
    n = V;
    forn(i, n) L[i] = i, R[i] = i;
    vi ord(n - 1);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){return a[i + 1] - a[i] < a[j + 1] - a[j];});
    ord.pb(n - 1);
    int ptr = 0;
    vector<pi64> segs;

    for (i64 x = 2; x <= a[n - 1]; ++x) {
        while (ptr < ord.size()) {
            int i = ord[ptr];
            if (i + 1 == n || a[i + 1] - a[i] >= x) break;
            int l = L[i], r = R[i + 1];
            L[r] = L[l] = l;
            R[l] = R[r] = r;
//            cerr << x << ' ' << i << ' ' << l << ' ' << r << '\n';
            ++ptr;
        }
//        cerr << x << ' ' << ptr << '\n';
        fore(j, ptr, n - 1) {
            int i = ord[j];
//            cerr << i << ' ' << L[i] << ' ' << R[i] << '\n';
//            assert(i == R[i]);
            i64 l = x * x - x + 1 - a[i], r = x * x - 1 - a[L[i]];
            uax(l, 0LL);
            ++r;
            if (l < r) {
                segs.pb({l, r});
//                cerr << x << ' ' << a[L[i]] << ' ' << a[i] << ' ' << l << ' ' << r << '\n';
            }
        }
    }

    sort(all(segs));
    i64 x = 0;
    for (auto [l, r]: segs) {
        if (x < l) break;
        uax(x, r);
    }
    cout << x << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}