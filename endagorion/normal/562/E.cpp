#pragma comment(linker, "/STACK:512000000")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <ctime>
#include <cassert>
#include <bitset>
#include <cmath>
#include <queue>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef long double ld;

bool bad3(pii a, pii b, pii c) {
    i64 x1 = b.fi - a.fi, y1 = b.se - a.se;
    i64 x2 = c.fi - a.fi, y2 = c.se - a.se;
    return x1 * y2 - x2 * y1 >= 0;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int N, M;
    scanf("%d%d", &N, &M);
    vector<pii> a(N), b(M);
    int x, y;
    scanf("%d%d", &x, &y);
    forn(i, N) scanf("%d%d", &a[i].fi, &a[i].se);
    forn(i, M) scanf("%d%d", &b[i].fi, &b[i].se);
    sort(all(b));
    vector<pii> st;
    forn(i, M) {
        while (st.size() > 1 && bad3(st[st.size() - 2], st.back(), b[i])) st.pop_back();
        if (st.size() == 1 && st[0].se <= b[i].se) st.pop_back();
        st.pb(b[i]);
    }
    bool w = false;
    forn(i, N) {
        if (a[i].fi < st[0].fi && a[i].se < st[0].se) continue;
        if (a[i].fi < st.back().fi && a[i].se < st.back().se) continue;
        if (a[i].fi >= st.back().fi || a[i].se >= st[0].se) {
            w = true;
            break;
        }
        int p = lower_bound(all(st), mp(a[i].fi, -1)) - st.begin();
        if (p > 0 && bad3(st[p - 1], st[p], a[i])) {
            w = true;
            break;
        }
    }
    cout << (w ? "Max" : "Min") << '\n';

    return 0;
}