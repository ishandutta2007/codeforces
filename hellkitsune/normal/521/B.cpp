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

int m;
int x[100000], y[100000];
map<PII, int> ma;
int ans = 0;
vector<int> g[100000], rev[100000];
int indeg[100000] = {}, outdeg[100000] = {};
set<int> se;
int cnt[100000] = {};
bool used[100000] = {};

const int MOD = 1e9 + 9;

int main() {
    scanf("%d", &m);
    REP(i, m) scanf("%d%d", x + i, y + i);
    REP(i, m) ma[mp(x[i], y[i])] = i;
    REP(i, m) {
        for (int j = -1; j <= 1; ++j) {
            auto it = ma.find(mp(x[i] + j, y[i] - 1));
            if (it != ma.end()) {
                g[i].pb(it->second);
                rev[it->second].pb(i);
                ++indeg[it->second];
                ++outdeg[i];
            }
        }
    }
    REP(i, m) if (outdeg[i] == 1)
        ++cnt[g[i][0]];
    REP(i, m) if (cnt[i] == 0)
        se.insert(i);
    bool maxim = true;
    while (!se.empty()) {
        int cur;
        if (maxim) {
            cur = *se.rbegin();
        } else {
            cur = *se.begin();
        }
        maxim = !maxim;
        se.erase(cur);
        used[cur] = true;
        ans = ((LL)ans * m + cur) % MOD;
        for (int x : rev[cur]) {
            if (--outdeg[x] == 1 && !used[x]) {
                for (int to : g[x]) {
                    if (++cnt[to] == 1) {
                        se.erase(to);
                    }
                }
            }
        }
        if (outdeg[cur] == 1) {
            for (int to : g[cur]) if (--cnt[to] == 0) {
                if (!used[to]) {
                    se.insert(to);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}