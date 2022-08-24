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

const int MAXN = 150000;
vector<pii> e[MAXN];
int cc[MAXN];

bool dfs(int v, int c) {
    if (cc[v] == c) return true;
    if (cc[v] == -1) cc[v] = c;
    if (cc[v] != c) return false;
    for (pii p: e[v]) {
        if (!dfs(p.fi, c ^ p.se)) return false;
    }
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
        int x, y, t;
        cin >> x >> y >> t;
        --x; --y; t ^= 1;
        e[x].pb(mp(y, t));
        e[y].pb(mp(x, t));
    }
    forn(i, N) cc[i] = -1;
    const i64 P = 1000000000 + 7;
    i64 ans = (P + 1) / 2;
    forn(i, N) {
        if (cc[i] != -1) continue;
        if (dfs(i, 0)) ans *= 2, ans %= P;
        else ans = 0;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}