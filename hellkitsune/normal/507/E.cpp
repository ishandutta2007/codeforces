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
LL dist[100000];
int pre[100000];

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (dist[lhs] != dist[rhs])
            return dist[lhs] < dist[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;
set<LL> used;
vector<int> ans1, ans2, ans3;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m) {
        int from, to, z;
        cin >> from >> to >> z, --from, --to;
        g[from].pb(mp(to, z));
        g[to].pb(mp(from, z));
    }
    dist[0] = 1ll << 31;
    for (int i = 1; i < n; ++i) dist[i] = 1ll << 60;
    q.insert(0);
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (PII to : g[v]) {
            LL nd = dist[v] + (1ll << 32);
            if (to.second == 1)
                --nd;
            if (nd < dist[to.first]) {
                q.erase(to.first);
                dist[to.first] = nd;
                pre[to.first] = v;
                q.insert(to.first);
            }
        }
    }
    int v = n - 1;
    while (v != 0) {
        used.insert(((LL)min(v, pre[v]) << 32) | max(v, pre[v]));
        v = pre[v];
    }
    REP(i, n) for (PII to : g[i]) if (to.first > i) {
        if (used.count(((LL)i << 32) | to.first)) {
            if (to.second == 0)
                ans1.pb(i + 1), ans2.pb(to.first + 1), ans3.pb(1);
        } else {
            if (to.second == 1)
                ans1.pb(i + 1), ans2.pb(to.first + 1), ans3.pb(0);
        }
    }
    cout << (int)ans1.size() << '\n';
    REP(i, ans1.size())
        cout << ans1[i] << ' ' << ans2[i] << ' ' << ans3[i] << '\n';
    return 0;
}