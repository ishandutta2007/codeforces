#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;

#ifdef DEBUG
#define dout(x) cerr<<x;
#else
#define dout(x)
#endif

using namespace std;

int n, a[111111], b[111111], l[111111], used[111111], sz[111111];
long long ans;
vector<int> g[111111];

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = 1;
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); i++) if (!used[g[v][i]]) {
        dfs(g[v][i]);
        sz[v]+=sz[g[v][i]];
    }
}

int q;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a[i] >> b[i] >> l[i];
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }
    dfs(1);
    cin >> q;
    for (int i = 0; i < n-1; i++) {
        int cur = min(sz[a[i]], sz[b[i]]);
        ans += cur * 1ll * (n-cur) * 1ll * l[i];
    }
    for (int i = 0; i < q; i++) {
        int r, w;
        cin >> r >> w;
        r--;
        int cur = min(sz[a[r]], sz[b[r]]);
        ans-=cur * 1ll * (n-cur) * 1ll * (l[r] - w);
        l[r] = w;
        printf("%.10f\n", ( (double) ans) / (double)n / (double)(n - 1) * 2 * 3);
    }
    return 0;
}