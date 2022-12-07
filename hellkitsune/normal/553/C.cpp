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

int n, m;
vector<PII> g[100000];
int a[100000];
queue<int> q;
const int MOD = 1e9 + 7;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) a[i] = -1;
    REP(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        if (from == 0) {
            a[to] = w;
            q.push(to);
        } else if (to == 0) {
            a[from] = w;
            q.push(from);
        } else {
            g[from].pb(mp(to, w ^ 1));
            g[to].pb(mp(from, w ^ 1));
        }
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && a[i] == -1) {
            a[i] = 0;
            q.push(i);
            ans += ans;
            if (ans >= MOD) ans -= MOD;
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (PII to : g[v]) if (a[to.first] == -1) {
                a[to.first] = a[v] ^ to.second;
                q.push(to.first);
            } else if (a[to.first] != (a[v] ^ to.second)) {
                printf("0\n");
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}