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
bool has[300][300] = {};
vector<int> g[300];
int ord[300], pos = 0, k = 0;
vector<int> ans;

void dfs(int v, int pre = -1) {
    bool leaf = true;
    for (int to : g[v]) if (to != pre) {
        leaf = false;
        dfs(to, v);
        REP(i, n) has[v][i] |= has[to][i];
    }
    if (leaf) {
        has[v][v] = true;
        ++k;
    }
}

void go(int v, int pre = -1) {
    ans.pb(v);
    if (v == ord[pos]) {
        ++pos;
        return;
    }
    int sz = (int)g[v].size() - (pre != -1);
    REP(i, sz) {
        bool flag = false;
        for (int to : g[v]) if (to != pre && has[to][ord[pos]]) {
            go(to, v);
            ans.pb(v);
            flag = true;
            break;
        }
        if (!flag) {
            cout << -1 << '\n';
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n - 1) {
        int from, to;
        cin >> from >> to, --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0);
    REP(i, k) cin >> ord[i], --ord[i];
    go(0);
    for (int x : ans) cout << x + 1 << ' ';
    cout << endl;
    return 0;
}