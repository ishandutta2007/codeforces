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

vector<pii> sws;
vi a;
int n;

void swp(int i, int j) {
    if (2 * abs(i - j) < n) {
        cerr << i << ' ' << j << '\n';
        assert(false);
    }
    swap(a[i], a[j]);
    sws.pb({i + 1, j + 1});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

//    cin >> n;
    scanf("%d", &n);
    a.resize(n);
    forn(i, n) scanf("%d", &a[i]), --a[i];
    int l = 0, r = n / 2;
    while (1) {
        while (l < n / 2 && a[l] < n / 2) ++l;
        if (l == n / 2) break;
        while (a[r] >= n / 2) ++r;
        assert(r < n);
        if (abs(l - r) >= n / 2) swp(l, r);
        else {
            swp(l, n - 1);
            swp(0, n - 1);
            swp(0, r);
            swp(0, n - 1);
            swp(l, n - 1);
        }
    }

    forn(i, n) assert((a[i] < n / 2) == (i < n / 2));

    forn(i, n) {
        while (a[i] != i) {
            int j = i < n / 2 ? n - 1 : 0;
            int v = a[i];
            swp(i, j);
            swp(v, j);
            swp(i, j);
        }
    }

    assert(sws.size() <= 5 * n);
    assert(is_sorted(all(a)));
    printf("%d\n", (int)sws.size());
    for (auto w: sws) printf("%d %d\n", w.fi, w.se);//cout << w.fi << ' ' << w.se << '\n';


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}