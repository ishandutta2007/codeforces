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

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vi64 a(n);
        forn(i, n) cin >> a[i];

        vvi64 score;
        multiset<i64> msc;
        {
            int M = n;
            vi ps;
            for (int p = 2; p * p <= M; ++p) {
                if (M % p == 0) {
                    ps.pb(p);
                    while (M % p == 0) M /= p;
                }
            }
            if (M > 1) ps.pb(M);
            for (int p: ps) {
                vi64 sc(n / p);
                forn(i, n) sc[i % sc.size()] += a[i] * (n / p);
                score.pb(sc);
                for (auto x: sc) msc.insert(x);
            }
        }

        cout << *msc.rbegin() << '\n';
        while (q--) {
            int i, x;
            cin >> i >> x;
            --i;
            i64 delta = x - a[i];
            a[i] = x;
            for (auto &sc: score) {
                int l = sc.size();
                msc.erase(msc.find(sc[i % l]));
                sc[i % l] += delta * l;
                msc.insert(sc[i % l]);
            }
            cout << *msc.rbegin() << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}