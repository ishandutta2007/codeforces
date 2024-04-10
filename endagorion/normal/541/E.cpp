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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int MAXN = 2000;
vi e[MAXN];
int vis[MAXN], d[MAXN];

vi comp;

bool bfs(int v) {
    vi q;
    q.pb(v);
    d[v] = 0;
    vis[v] = 1;
    int cur = 0;
    while (cur < q.size()) {
        int v = q[cur++];
        for (int u: e[v]) {
            if (vis[u]) {
                if (d[u] == d[v]) return false;
                continue;
            }
            vis[u] = 1;
            d[u] = d[v] + 1;
            q.pb(u);
        }
    }
    comp = q;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M;
    cin >> N >> M;
    forn(i, M) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    forn(i, N) d[i] = -1;
    int ans = 0;
    forn(i, N) {
        if (vis[i]) continue;
        comp.clear();
        if (!bfs(i)) {
            ans = -1;
            break;
        }
        vi c = comp;
        int res = 0;
        for (int v: c) {
            for (int u: c) vis[u] = 0;
            assert(bfs(v));
            for (int u: c) uax(res, d[u]);
        }
        ans += res;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}