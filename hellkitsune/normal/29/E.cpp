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
vector<int> g[500];
queue<int> q;
int d[1 << 19];
int pre[1 << 19];
vector<int> ans1, ans2;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m) {
        int from, to;
        cin >> from >> to, --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    REP(i, 1 << 19) d[i] = -1;
    d[n - 1] = 0;
    q.push(n - 1);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        bool flag = false;
        if (tmp & (1 << 18)) {
            flag = true;
            tmp ^= (1 << 18);
        }
        int u = tmp >> 9;
        int v = tmp & 511;
        if (flag) tmp ^= (1 << 18);
        if (flag) {
            for (int to : g[v]) if (to != u) {
                int val = (u << 9) | to;
                if (d[val] == -1) {
                    d[val] = d[tmp] + 1;
                    pre[val] = tmp;
                    q.push(val);
                }
            }
        } else {
            for (int to : g[u]) {
                int val = (1 << 18) | (to << 9) | v;
                if (d[val] == -1) {
                    d[val] = d[tmp];
                    pre[val] = tmp;
                    q.push(val);
                }
            }
        }
    }
    int pos = (n - 1) << 9;
    if (d[pos] == -1) {
        cout << -1 << '\n';
        return 0;
    }
    cout << d[pos] << '\n';
    ans1.pb(n - 1);
    ans2.pb(0);
    while (pos != n - 1) {
        pos = pre[pos];
        pos = pre[pos];
        ans1.pb(pos >> 9);
        ans2.pb(pos & 511);
    }
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    REP(i, ans1.size()) cout << ans1[i] + 1 << ' ';
    cout << '\n';
    REP(i, ans2.size()) cout << ans2[i] + 1 << ' ';
    cout << '\n';
    return 0;
}