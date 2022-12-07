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
vector<int> g[200000];
int val[200000];
LL ans = 0;
LL d[2][200000];

const LL INF = 1e18;

void go(int v, int par) {
    for (int to : g[v]) if (to != par)
        go(to, v);
    LL mn = INF, sum = val[v];
    int cnt = 1;
    for (int to : g[v]) if (to != par) {
        if (d[0][to] > d[1][to]) {
            sum += d[0][to];
            mn = min(mn, d[0][to] - d[1][to]);
        } else {
            sum += d[1][to];
            ++cnt;
            mn = min(mn, d[1][to] - d[0][to]);
        }
    }
    cnt %= 2;
    if (cnt == 1) {
        d[0][v] = sum - val[v];
        d[1][v] = sum;
    } else {
        d[1][v] = max(sum - val[v], sum - mn);
        d[0][v] = sum - val[v] - mn;
    }
    ans = max(ans, d[0][v]);
    ans = max(ans, d[1][v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        int par;
        cin >> par >> val[i], --par;
        if (par != -2) g[par].pb(i);
    }
    go(0, -1);
    cout << ans << endl;
    return 0;
}