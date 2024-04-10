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

i64 GCD(i64 x, i64 y) {
    while (x) {
        y %= x;
        swap(x, y);
    }
    return y;
}

struct Stack {
    vi64 a, g;

    Stack()
        : a()
        , g({0})
    {
    }

    void push(i64 x) {
        g.pb(a.empty() ? 0LL : GCD(g.back(), abs(x - a[0])));
        a.pb(x);
    }

    void pop() {
        g.pop_back();
        a.pop_back();
    }
};

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
        int n;
        cin >> n;
        vi64 a(n);
        forn(i, n) cin >> a[i];
        Stack ls, rs;
        int L = 0, R = 0;
        int ans = 0;
        while (L < n) {
            while (R < n) {
                rs.push(a[R]);
                i64 g = GCD(ls.g.back(), rs.g.back());
                if (!ls.a.empty() && !rs.a.empty()) g = GCD(g, abs(ls.a[0] - rs.a[0]));
                if (g == 1) {
                    rs.pop();
                    break;
                } else ++R;
            }
            uax(ans, R - L);
            if (ls.a.empty()) {
                while (!rs.a.empty()) {
                    ls.push(rs.a.back());
                    rs.pop();
                }
            }
            ls.pop();
            ++L;
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}