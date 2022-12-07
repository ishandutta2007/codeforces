#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <unordered_map>
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

int n, q, cnt = 0;
unordered_map<int, int> ma;
int p[200000];
bool b[2000001];
vector<int> a[100000];
vector<int> g[100000];
int d[200000];
int ans[200000];
int dist[100000];

void doThings(int v, int x) {
    int upTo = sqrt(x) + 5;
    a[v].clear();
    for (int i = 0; p[i] <= upTo; ++i) {
        if (x == 1) break;
        if (x % p[i] == 0) {
            x /= p[i];
            while (x % p[i] == 0) x /= p[i];
            a[v].pb(i);
        }
    }
    if (x != 1) a[v].pb(ma[x]);
}

void go(int v, int par) {
    ans[v] = -1;
    vector<PII> re;
    for (int i : a[v]) {
        if (d[i] != -1 && (ans[v] == -1 || dist[d[i]] > dist[ans[v]]))
            ans[v] = d[i];
        re.pb(mp(i, d[i]));
        d[i] = v;
    }
    for (int to : g[v]) if (to != par)
        go(to, v);
    for (PII e : re) d[e.first] = e.second;
}

void dfs(int v, int par, int curDist) {
    dist[v] = curDist;
    for (int to : g[v]) if (to != par)
        dfs(to, v, curDist + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    REP(i, 2000001) b[i] = true;
    for (int i = 2; i <= 10000; ++i) if (b[i])
        for (int j = i * i; j <= 2000000; j += i)
            b[j] = false;
    for (int i = 2; i <= 2000000; ++i) if (b[i]) {
        ma[i] = cnt;
        p[cnt++] = i;
    }
    cin >> n >> q;
    REP(i, n) {
        int x;
        cin >> x;
        doThings(i, x);
    }
    REP(i, n - 1) {
        int x, y;
        cin >> x >> y, --x, --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, -1, 0);
    REP(i, cnt) d[i] = -1;
    go(0, -1);
    REP(i, q) {
        int x;
        cin >> x;
        if (x == 1) {
            int y;
            cin >> y, --y;
            if (ans[y] == -1) cout << "-1\n";
            else cout << ans[y] + 1 << '\n';
        } else {
            int y, z;
            cin >> y >> z, --y;
            doThings(y, z);
            go(0, -1);
        }
    }
    return 0;
}