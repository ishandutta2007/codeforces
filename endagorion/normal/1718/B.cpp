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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    vi64 fib = {1, 1};
    fib.reserve(100);
    while (fib.back() < (i64)2e11) fib.pb(fib.end()[-1] + fib.end()[-2]);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi64 a(n);
        forn(i, n) cin >> a[i];
        vi ord(n);
        iota(all(ord), 0);
        i64 s = accumulate(all(a), 0LL);
//        cerr << s << '\n';
        int sp = upper_bound(all(fib), s) - fib.begin();
        bool ok = fib[sp] == s + 1;
//        cerr << s << ' ' << fib[sp] << '\n';
        vi used(sp - 1, -1);
        auto set_used = [&](int j, int x) {
            if (used[j] != -1) ok = false;
            else used[j] = x;
        };
        if (ok) ford(j, sp - 1) {
            if (used[j] != -1) continue;
            sort(all(ord), [&](int i, int j){return a[i] > a[j];});
            int x = 0;
            while (x < n && a[ord[x]] >= fib[j]) ++x;
/*            cerr << fib[j] << ' ' << x << '\n';
            for (auto i: ord) cerr << a[i] << ' ';
            cerr << '\n';
            for (int v: used) cerr << v << ' ';
            cerr << '\n';*/
            if (x == 0) {
                ok = false;
                break;
            }
            if (x == 1) {
                a[ord[0]] -= fib[j];
                set_used(j, ord[0]);
                continue;
            }
            if (x == 2) {
                if (j + 1 < used.size() && used[j + 1] == ord[0]) swap(ord[0], ord[1]);
                if (!(j & 1) || a[ord[1]] > fib[j]) {
                    ok = false;
                    break;
                }
                a[ord[0]] -= fib[j];
                a[ord[1]] -= fib[j];
                set_used(j, ord[0]);
                for (int k = j - 1; k >= 0; k -= 2) set_used(k, ord[1]);
            }
        }
//        for (auto x: used) cerr << x << ' ';
//        cerr <<'\n';
        ok &= a == vi64(n, 0) && !count(all(used), -1);
/*        if (used.size() >= 2) {
            ok &= used[0] != used[1];
        }*/
        forn(j, (int)used.size() - 1) ok &= used[j] != used[j + 1];
        cout << (ok ? "YES" : "NO") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}