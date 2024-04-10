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

const int maxn = 50;
string f[maxn];
int par[maxn], sz[maxn];
int m[maxn][maxn], id[maxn];
int isind[1 << 23], dp[1 << 23];
vi maxcl[maxn];

int root(int i) {
    if (par[i] == i) return i;
    return par[i] = root(par[i]);
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
    forn(i, n) cin >> f[i];
    forn(i, n) par[i] = i;
    forn(i, n) forn(j, i) if (f[i][j] == 'A') par[root(i)] = root(j);
    forn(i, n) ++sz[root(i)];
    int K = 0;
    bool ok = true;
    forn(i, n) {
        if (par[i] != i || sz[i] == 1) continue;
        id[i] = K++;
        forn(u, n) forn(j, n) {
            if (root(u) != i) continue;
            int v = root(j);
            if (v > i || sz[v] == 1) continue;
//            cerr << id[i] << ' ' << u << ' ' << j << '\n';
            m[id[i]][id[v]] |= f[u][j] == 'X';
            m[id[v]][id[i]] |= f[u][j] == 'X';
        }
    } 
    forn(i, K) {
        forn(j, K) cerr << m[i][j];
        cerr << '\n';
    }
    forn(i, K) ok &= !m[i][i];
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }
//    cerr << K << '\n';
    isind[0] = 1;
    forn(i, 1 << K) {
        if (!i) continue;
        int j = 0;
        while (!((i >> j) & 1)) ++j;
        int pi = i ^ (1 << j);
        if (!isind[pi]) continue;
        isind[i] = 1;
//        cerr << i << ' ' << pi << '\n';
        forn(k, K) if ((pi >> k) & 1) isind[i] &= !m[k][j];
//        if (isind[i]) cerr << i << '\n';
    }
//    cerr << "-\n";

    forn(i, 1 << K) {
        if (!isind[i]) continue;
        bool maximal = true;
        forn(j, K) {
            if ((i >> j) & 1) continue;
            maximal &= !isind[i | (1 << j)];
        }
        if (maximal) {
            forn(j, K) if ((i >> j) & 1) maxcl[j].pb(i);
        }
    }

    forn(i, 1 << K) dp[i] = 1e9;
    dp[0] = 0;
    forn(i, 1 << K) {
        int j = 0;
        while ((i >> j) & 1) ++j;
        for (int m: maxcl[j]) uin(dp[i | m], dp[i] + 1);
    }
    cout << n - 1 + dp[(1 << K) - 1] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}