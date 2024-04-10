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

i64 solve(vi as, int bc, i64 A, i64 B, i64 C) {
    i64 ans = 0, res = 0;
    int ptr = 0;
    while (ptr < (int)as.size() && as[ptr] <= 1) ++ptr;
    int L = 0;
    while (L < (int)as.size() && !as[L]) ++L;
    while (1) {
        if (!bc || (ptr == as.size())) {
            if (ptr < as.size() && as[ptr] > 1) uax(ans, res + A);
            if (L < (int)as.size() && as[L] == 1) {
                res -= C;
                if (L + 2 < (int)as.size()) ++bc;
                --as[L];
                while (L < (int)as.size() && !as[L]) ++L;
            } else break;
        } else {
            res += A;
            uax(ans, res);
            --as[ptr];
            while (ptr < (int)as.size() && as[ptr] <= 1) ++ptr;
        }
//        cerr << res << ' ';
        if (!bc) break;
        --bc;
        res += B;
        uax(ans, res);
//        cerr << res << ' ';
    }
//    cerr << '\n';
    return ans;
}

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
        i64 a, b, c;
        string s;
        cin >> n >> a >> b >> c >> s;
        vi as;
        int bc = 0;
        int lc = 0, nc = 0;
        for (char c: s) {
            if (c - '0' == lc) ++nc;
            else {
                if (lc == 0) as.pb(nc);
                else bc += nc - 1;
                lc ^= 1;
                nc = 1;
            }
        }
        as.pb(lc == 0 ? nc : 0);
        if (lc == 1) bc += nc - 1;
        if (as.size() == 1) {
            cout << (n > 1 ? a : 0LL) << '\n';
            continue;
        }
        swap(as[0], as.end()[-2]);
        sort(all(as) - 2);
/*        cerr << bc << '\n';
        cerr << "as: ";
        for (int x: as) cerr << x << ' ';
        cerr << '\n';*/
        i64 ans = solve(as, bc, a, b, c);
        if (bc) uax(ans, solve(as, bc - 1, a, b, c) + b);
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}