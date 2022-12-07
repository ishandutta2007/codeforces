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
vector<int> g[3000];
int cnt[3000];
LL ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m) {
        int x, y;
        cin >> x >> y, --x, --y;
        g[x].pb(y);
    }
    REP(i, n) {
        REP(j, n)
            cnt[j] = 0;
        for (int v : g[i]) {
            for (int u : g[v])
                ++cnt[u];
        }
        REP(j, n) if (i != j && cnt[j])
            ans += ((cnt[j] - 1) * cnt[j]) >> 1;
    }
    cout << ans << '\n';
    return 0;
}