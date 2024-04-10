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

const int maxa = 33000;
i64 b[maxa];
vi64 divs[maxa];

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int p = 2; p * p <= x; ++p) if (x % p == 0) return false;
    return true;
}

void addp(int i, int p, int z) {
//    cerr << i << ' ' << p << ' ' << z << '\n';
    int sz = divs[i].size();
    forn(j, sz) {
        int m = divs[i][j];
        forn(k, z) {
            m /= p;
            divs[i].pb(m);
        }
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

    int n;
    cin >> n;
    vi64 a(n);
    forn(i, n) cin >> a[i];
    
    forn(i, maxa) {
        b[i] = a[0] + i;
        divs[i] = {b[i]};
    }

    fore(p, 2, maxa) {
        i64 s = a[0] + maxa - 1;
        s -= s % p;
        while (s >= a[0]) {
            assert(s % p == 0);
            int z = 0;
            while (b[s - a[0]] % p == 0) {
                b[s - a[0]] /= p;
                ++z;
            }
            addp(s - a[0], p, z);
            s -= p;
        }
    }

    forn(i, maxa) if (b[i] > 1) addp(i, b[i], 1);
    set<int> xs;
    forn(i, maxa) for (int d: divs[i]) xs.insert(d);
    cerr << xs.size() << '\n';
/*    forn(i, maxa) {
        cerr << a[0] + i << ": ";
        for (int d: divs[i]) cerr << d << ' ';
        cerr << '\n';
    }*/

    vi vxs(all(xs));

    i64 ans = 1e18;
    for (int x: vxs) {
//        cerr << x << '\n';
        i64 res = 0;
        forn(i, n) {
            int t = -a[i] % x;
            if (t < 0) t += x;
//            i64 cx1 = t, cx = (a[i] + t) / x - cx1;
//            cerr << a[i] << ' ' << x << ' ' << cx1 << ' ' << cx << '\n';
            if (a[i] >= 1LL * t * (x - 1)) res += (a[i] + t) / x;
            else {
                res = 1e18;
                break;
            }
        }
        uin(ans, res);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}