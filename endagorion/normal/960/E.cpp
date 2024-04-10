#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 210000;
const i64 P = 1000000000 + 7;
i64 a[maxn];
i64 sum[2][maxn], cnt[2][maxn];
vi e[maxn];

i64 ans = 0;

void dfs(int v, int p) {
    cnt[1][v] = 1;
    sum[1][v] = a[v];
    (ans += a[v]) %= P;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
        forn(d, 2) {
            int a = v, b = u;
            if (d) swap(a, b);
            forn(z, 2) forn(zz, 2) (ans += (z ? -1 : 1) * (-sum[z][a] * cnt[zz][b] + cnt[z][a] * sum[zz][b])) %= P;
        }
        forn(z, 2) {
            (cnt[z][v] += cnt[z ^ 1][u]) %= P;
            (sum[z][v] += a[v] * cnt[z ^ 1][u] - sum[z ^ 1][u]) %= P;
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
    forn(i, n) {
        cin >> a[i];
        if (a[i] < 0) a[i] += P;
    }
    forn(i, n - 1) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        e[v].pb(u);
        e[u].pb(v);
    }
    dfs(0, -1);
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}