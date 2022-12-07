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

vector<PII> g[100];
bool rev = false;
int ans, n;

int go(int v, int par = -1) {
    if (par == -1) {
        if (rev) return go(g[v][1].first, v) + g[v][1].second;
        return go(g[v][0].first, v) + g[v][0].second;
    }
    if (v == 0) return 0;
    REP(i, 2) if (g[v][i].first != par) {
        return go(g[v][i].first, v) + g[v][i].second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        int from, to, w;
        cin >> from >> to >> w, --from, --to;
        g[from].pb(mp(to, 0));
        g[to].pb(mp(from, w));
    }
    ans = go(0);
    rev = true;
    ans = min(ans, go(0));
    cout << ans << endl;
    return 0;
}