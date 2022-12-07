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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL x[4], y[4], a[4], b[4], dist[6];
int ans, cur;
const int INF = 1e9;

void go(int v) {
    if (v == 4) {
        int z = 0;
        REP(i, 3) for (int j = i + 1; j < 4; ++j)
            dist[z++] = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
        sort(dist, dist + 6);
        if (dist[0] != 0 && dist[0] == dist[1] && dist[1] == dist[2] &&
            dist[2] == dist[3] && dist[3] * 2 == dist[4] && dist[4] == dist[5])
            ans = min(ans, cur);
        return;
    }
    LL tmp1, tmp2;
    REP(i, 4) {
        go(v + 1);
        tmp1 = x[v] - a[v];
        tmp2 = y[v] - b[v];
        x[v] = a[v] - tmp2;
        y[v] = b[v] + tmp1;
        ++cur;
    }
    cur -= 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(test, n) {
        REP(i, 4) cin >> x[i] >> y[i] >> a[i] >> b[i];
        ans = INF, cur = 0;
        go(0);
        if (ans == INF) cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}