#include <iostream>
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

    i64 d, n, m;
    cin >> d >> n >> m;
    deque<pi64> st;
    st.pb(mp(n, 0));
    i64 px = 0;
    i64 tl = n;
    i64 ans = 0;
    vector<pii> a(m);
    forn(i, m) cin >> a[i].fi >> a[i].se;
    sort(all(a));
    forn(i, m) {
        i64 x = a[i].fi, p = a[i].se;
//        cin >> x >> p;
        x -= px;
        px += x;
        while (x && !st.empty()) {
            i64 y = min(x, st.front().fi);
            ans += y * st.front().se;
            x -= y;
            tl -= y;
            st.front().fi -= y;
            if (!st.front().fi) st.pop_front();
        }
        if (x) {
            cout << -1 << '\n';
            return 0;
        }
        while (!st.empty() && st.back().se >= p) {
            tl -= st.back().fi;
            st.pop_back();
        }
        if (tl < n) st.push_back(mp(n - tl, p));
        tl = n;
    }
    {
        i64 x = d - px;
        while (x && !st.empty()) {
            i64 y = min(x, st.front().fi);
            ans += y * st.front().se;
            x -= y;
            tl -= y;
            st.front().fi -= y;
            if (!st.front().fi) st.pop_front();
        }
        if (x) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}