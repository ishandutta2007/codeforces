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

const int MAXN = 300000;
int par[MAXN], rk[MAXN];

int root(int x) {
    if (x == par[x]) return x;
    return par[x] = root(par[x]);
}

bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (rk[x] > rk[y]) swap(x, y);
    par[x] = y;
    rk[y] = max(rk[y], rk[x] + 1);
    return true;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int N, Q;
//    cin >> N >> Q;
    scanf("%d%d", &N, &Q);
    forn(i, N) par[i] = i;
    set<int> lead;
    forn(i, N) lead.insert(i);
    forn(i, Q) {
        int t;
        int x, y;
//        cin >> t >> x >> y;
        scanf("%d%d%d", &t, &x, &y);
        --x; --y;
        if (t == 1) unite(x, y);
        if (t == 2) {
            ++y;
            while (1) {
                set<int>::iterator it = lead.upper_bound(x);
                if (it == lead.end() || *it >= y) break;
                unite(x, *it);
                lead.erase(it);
            }
        }
        if (t == 3) {
            //cout << (root(x) == root(y) ? "YES" : "NO") << '\n';
            printf("%s\n", (root(x) == root(y) ? "YES": "NO"));
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}