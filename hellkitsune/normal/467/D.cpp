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
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, cnt = 0;
map<string, int> ma;
int d[100000], le[100000], ri[100000];
bool vis[300000];
PII se[300000] = {};
vector<int> g[300000];
string s, t;

void dfs(int v) {
    vis[v] = true;
    for (int to : g[v]) {
        se[v] = min(se[v], se[to]);
        if (!vis[to]) dfs(to);
        se[v] = min(se[v], se[to]);
    }
}

inline int toInt(string &s) {
    REP(i, s.length()) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    auto it = ma.find(s);
    if (it != ma.end()) return it->second;
    REP(i, s.length()) se[cnt].first += s[i] == 'r';
    se[cnt].second = (int)s.length();
    return ma[s] = cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        cin >> s;
        d[i] = toInt(s);
    }
    cin >> m;
    REP(i, m) {
        cin >> s >> t;
        g[toInt(s)].pb(toInt(t));
    }
    REP(step, 5) {
        REP(i, cnt) vis[i] = false;
        REP(i, cnt) if (!vis[i]) dfs(i);
    }
    LL ans1 = 0, ans2 = 0;
    REP(i, n) {
        ans1 += se[d[i]].first;
        ans2 += se[d[i]].second;
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}