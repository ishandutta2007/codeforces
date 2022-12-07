#include <cstdio>
#include <cmath>
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
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = 2e18 + 9;
int n, m, b;
pair<int, PII> f[100];
LL cost[1 << 20];

int main() {
    scanf("%d%d%d", &n, &m, &b);
    REP(i, n) {
        scanf("%d%d", &f[i].second.first, &f[i].first);
        int k;
        scanf("%d", &k);
        f[i].second.second = 0;
        REP(j, k) {
            int x;
            scanf("%d", &x);
            f[i].second.second |= (1 << (x - 1));
        }
    }
    sort(f, f + n);
    m = 1 << m;
    REP(i, m)
        cost[i] = INF;
    cost[0] = 0;
    LL ans = INF;
    REP(i, n) {
        REP(j, m)
            if (cost[j] + f[i].second.first < cost[j | f[i].second.second])
                cost[j | f[i].second.second] = cost[j] + f[i].second.first;
        if (cost[m - 1] + b * 1ll * f[i].first < ans)
            ans = cost[m - 1] + b * 1ll * f[i].first;
    }
    if (ans < INF)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}