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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 210000;
int a[maxn], ans[maxn];
vector<pii> e[maxn];

void dfs(int v, i64 d, vi64 &p, vi &st) {
    int i = lower_bound(all(p), d - a[v]) - p.begin() - 1;
    ++ans[v];
    if (i >= 0) --ans[st[i]];
    st.pb(v);
    p.pb(d);
    for (auto w: e[v]) {
        dfs(w.fi, d + w.se, p, st);
        ans[v] += ans[w.fi];
    }
    st.pop_back();
    p.pop_back();
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
    forn(i, n) cin >> a[i];

    forn(i, n - 1) {
        int p, w;
        cin >> p >> w;
        e[--p].pb(mp(i + 1, w));
    }

    vi64 p;
    vi st;
    dfs(0, 0, p, st);
    forn(i, n) cout << ans[i] - 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}