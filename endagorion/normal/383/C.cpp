#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int maxn = 300000;

vi e[maxn];
int tin[maxn], tout[maxn];
int d[maxn];
int a[maxn];
i64 fenw[maxn];
int t = 0;

void dfs(int v, int p) {
    tin[v] = t++;
    d[v] = (p == -1 ? 0 : d[p] + 1);
    
    forn(i, e[v].size()) {
        int u = e[v][i];
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }

    tout[v] = t;
}

i64 sum(int i) {
    i64 res = 0;
    while (i >= 0) {
        res += fenw[i];
        i = (i & (i + 1)) - 1;
    }
    return res;
}

void add(int i, i64 x) {
    while (i < maxn) {
        fenw[i] += x;
        i = i | (i + 1);
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    forn(i, N) {
        cin >> a[i];
    }
    forn(i, N - 1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }

    dfs(0, -1);
    forn(i, N) {
        if (d[i] & 1) {
            a[i] = -a[i];
        }
        add(tin[i], a[i]);
        add(tin[i] + 1, -a[i]);
    }

/*    forn(j, N) {
        cout << sum(tin[j]) << ' ';
    }
    cout << '\n';*/


    forn(i, M) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, val;
            cin >> x >> val;
            --x;
            if (d[x] & 1) {
                val = -val;
            }
            add(tin[x], val);
            add(tout[x], -val);
        } else {
            int x;
            cin >> x;
            --x;
            i64 res = sum(tin[x]);
            if (d[x] & 1) {
                res = -res;
            }
            cout << res << '\n';
        }
/*        forn(j, N) {
            cout << sum(tin[j]) << ' ';
        }
        cout << '\n';*/
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}