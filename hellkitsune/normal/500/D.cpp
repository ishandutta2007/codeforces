#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[100000];
int a[100000], b[100000], l[100000];
int d[100000];
double p[100000];

void dfs(int v, int par = -1) {
    d[v] = 1;
    for (int to : g[v]) if (to != par) {
        dfs(to, v);
        d[v] += d[to];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n - 1) {
        cin >> a[i] >> b[i] >> l[i], --a[i], --b[i];
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }
    dfs(0);
    double res = 0, di = (double)n * (n - 1) * (double)(n - 2);
    REP(i, n - 1) {
        double tmp = 0;
        int cnt = min(d[a[i]], d[b[i]]);
        tmp += (double)cnt * (n - cnt);
        p[i] = 6 * tmp * (n - 2);
        res += l[i] * p[i];
    }
    int q;
    cin >> q;
    REP(i, q) {
        int r, w;
        cin >> r >> w, --r;
        res -= (l[r] - w) * p[r];
        l[r] = w;
        cout << setprecision(12) << fixed << res / di << '\n';
    }
    return 0;
}