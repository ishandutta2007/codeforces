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

const int maxn = 1100;
vi e[maxn];
int a[maxn], b[maxn];

int dfs(int v, int p) {
    if (a[v]) return v;
    for (int u: e[v]) {
        if (u == p) continue;
        int z = dfs(u, v);
        if (z != -1) return z;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for1(i, n) e[i].clear();
        forn(i, n - 1) {
            int x, y;
            cin >> x >> y;
            e[x].pb(y);
            e[y].pb(x);
        }
        for1(i, n) a[i] = b[i] = 0;
        int k1;
        cin >> k1;
        forn(i, k1) {
            int x;
            cin >> x;
            a[x] = 1;
        }
        int k2;
        cin >> k2;
        forn(i, k2) {
            int x;
            cin >> x;
            b[x] = 1;
        }

        int z = 1;
        while (!b[z]) ++z;
        cout << "B " << z << endl;
        int v;
        cin >> v;
        int w = dfs(v, -1);
        cout << "A " << w << endl;
        int ww;
        cin >> ww;
        if (b[ww]) cout << "C " << w << endl;
        else cout << "C " << -1 << endl;
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}