#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
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

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const i64 P = 1000000000 + 7;
const int MAXN = 110000;
vector<pii> e[MAXN];
int val[MAXN];

void add_edge(int x, int y, int z) {
    e[x].pb(mp(y, z));
    e[y].pb(mp(x, z));
}

bool dfs(int v, int z) {
    if (val[v] != -1) return val[v] == z;
    val[v] = z;
    for (pii p: e[v]) {
        if (!dfs(p.fi, z ^ p.se)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, K;
    cin >> N >> K;
    forn(i, K) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        --x; --y;
        if (x < y) swap(x, y);
        if (x + y >= N) {
            int d = x + y - N + 1;
            x -= d;
            y -= d;
        }
//        cerr << x << ' ' << y << ' ' << c << '\n';
        int l = x - y, r = x + y;
        add_edge(l, r + 2, c == 'o' ? 1 : 0);
    }
    forn(i, N + 2) val[i] = -1;
    if (!dfs(0, 0) || !dfs(1, 0)) {
        cout << 0 << '\n';
        return 0;
    }
    i64 ans = 1;
    forn(i, N + 2) {
        if (val[i] != -1) continue;
        if (!dfs(i, 0)) ans = 0;
        ans *= 2; ans %= P;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}