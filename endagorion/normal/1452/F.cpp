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

i64 f(int b, i64 x) {
    if (!x) return 0;
    if (x == (1LL << b)) return (1LL << b) - 1;
    i64 h = 1LL << (b - 1), z = min(x, h);
    return f(b - 1, z) + f(b - 1, x - z) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    vi64 cnt(n);
    forn(i, n) cin >> cnt[i];
    while (q--) {
        int type, k;
        i64 x;
        cin >> type >> k >> x;
        if (type == 1) cnt[k] = x;
        else {
            auto a = cnt;

            vi64 ps0(n + 1), ps1(n + 1);
            forn(i, n) ps0[i + 1] = ps0[i] + a[i], ps1[i + 1] = ps1[i] + (a[i] << i);
            
            if (ps1[n] < x) {
                cout << -1 << '\n';
                continue;
            }

            i64 res = 0;

            for (int i = n - 1; i > k; --i) {
                if (ps1[i] >= x) continue;
//                cerr << i << ' ' << x << ' ' << ps1[i] << ' ' << a['\n';
                i64 z = 1 + ((x - ps1[i] - 1) >> i);
                assert(z <= a[i]);
                res += z;
                a[i] -= z;
                a[i - 1] += 2 * z;
                ps1[i] += z << i;
                ps0[i] += 2 * z;
            }

            assert(ps1[k + 1] >= x);

            fore(i, k + 1, n - 1) {
                if (ps0[k + 1] >= x) break;
                i64 z = min(a[i], (x - ps0[k + 1]) >> (i - k));
                res += (z << (i - k)) - z;
                a[i] -= z;
                a[k] += z << (i - k);
                ps0[k + 1] += z << (i - k);;
            }

/*                    cerr << s0 << ' ' << s1 << '\n';
                    for (auto x: a) cerr << x << ' ';
                    cerr << '\n';*/
        
            cout << res + max(0LL, x - ps0[k + 1]) << '\n';            
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}