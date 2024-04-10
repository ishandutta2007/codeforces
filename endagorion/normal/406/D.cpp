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

const int maxn = 200000;
i64 x[maxn], y[maxn];
int pr[maxn];
int d[maxn];
int up[20][maxn];
vi e[maxn];

int jump(int u, int dd) {
    for (int k = 19; k >= 0; --k) {
        if (dd >= (1 << k)) {
            dd -= 1 << k;
            u = up[k][u];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = jump(u, d[u] - d[v]);
    if (u == v) return u;
    for (int k = 19; k >= 0; --k) {
        if (up[k][u] != up[k][v]) {
            u = up[k][u];
            v = up[k][v];
        }
    }
    return pr[u];
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    forn(i, N) {
        cin >> x[i] >> y[i];
    }
    vector<int> p;
    pr[N - 1] = -1;
    p.pb(N - 1);
    for (int i = N - 2; i >= 0; --i) {
        while (p.size() >= 2) {
            int j = p[p.size() - 1], k = p[p.size() - 2];
            if ((x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]) > 0) {
                p.pop_back();
            } else {
                break;
            }
        }
        pr[i] = p.back();
        e[pr[i]].pb(i);
        p.pb(i);
    }
    d[N - 1] = N - 1;
    for (int i = N - 2; i >= 0; --i) {
        d[i] = d[pr[i]] + 1;
    }
    forn(i, N) {
        up[0][i] = pr[i];
    }
    forn(k, 19) {
        forn(j, N) {
            up[k + 1][j] = up[k][up[k][j]];
        }
    }

    int M;
    cin >> M;
    forn(i, M) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        cout << lca(x, y) + 1 << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}