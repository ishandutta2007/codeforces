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

vi64 a;
int n, k;

int sp;
int T;

i64 query(int i) {
#ifndef LOCAL_DEFINE
    cout << "? " << i + 1 << endl;
    i64 x;
    cin >> x;
    return x;
#else
    i64 ans = a[i];
    ++T;
//    cerr << i << ' ' << ans << '\n';
    vi64 b(n);
    forn(i, n) {
        int j = (i + 1) % n;
        b[j] += a[i] - a[i] / 2;
    }
    forn(i, n) {
        int j = (i + n - 1) % n;
        if (i == sp) j = (i + 1) % n;
        b[j] += a[i] / 2;
    }
    a = b;
    return ans;
#endif
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> k;

#ifdef LOCAL_DEFINE
    srand(time(0));
//    sp = rand() % n;
//    sp = 0;
    cin >> sp;
    a = vi64(n, k);
#endif

    int i = 0;
    int s = min(n / 10 + 1, 500);
    while (__gcd(s, n) != 1) ++s;
    i64 x;
    while (1) {
        x = query(i);
        if (x != k) break;
        i += s;
        i %= n;
    }

    while (x > k) {
        i = (i + n - 1) % n;
        x = query(i);
    }
    while (x < k) {
        i = (i + 1) % n;
        x = query(i);
    }

    cout << "! " << i + 1 << endl;
#ifdef LOCAL_DEFINE
    assert(i == sp);
    cerr << T << '\n';
#endif


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}