#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

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
typedef long double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 210000;
i64 a[maxn], ps[maxn];
ld sinv[maxn], P[maxn];
ld dp[2][maxn];

ld conv(pair<ld, ld> a, pair<ld, ld> b) {
    return a.fi * b.fi + a.se * b.se;
}

bool ccw(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c) {
    return (b.first - a.first) * (c.se - a.second) - (c.first - a.first) * (b.second - a.second) > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    cin >> n >> k;
    forn(i, n) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
        sinv[i + 1] = sinv[i] + 1.0 / a[i];
        P[i + 1] = P[i] + 1.0 * ps[i + 1] / a[i];
    }
    forn(i, n + 1) dp[0][i] = 1e18;
    dp[0][0] = 0.0;
    forn(j, k) {
//        cerr << j << '\n';
        forn(i, n + 1) dp[1][i] = 1e18;
        vector< pair<ld, ld> > st;
        st.pb(mp(ps[j], dp[0][j] + ps[j] * sinv[j] - P[j]));
        int opt = 0;
        for (int i = j + 1; i <= n; ++i) {
            pair<ld, ld> x = mp(-sinv[i], 1.0);
            while (opt + 1 < st.size() && conv(x, st[opt]) > conv(x, st[opt + 1])) ++opt;
            dp[1][i] = P[i] + conv(x, st[opt]);
//            cerr << dp[1][i] << ' ';
            pair<ld, ld> z = mp(ps[i], dp[0][i] + ps[i] * sinv[i] - P[i]);
            while (st.size() > 1 && (!ccw(st[st.size() - 2], st.back(), z))) st.pop_back();
            st.pb(z);
        }
//        cerr << '\n';
        forn(i, n + 1) dp[0][i] = dp[1][i];
    }
    cout << (double)dp[0][n] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}