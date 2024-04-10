#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

void success() { puts("possible"); exit(0); }
void fail() { puts("impossible"); exit(0); }

int n, m, k, x, y, u[300105];
set<int> visit, s[300105];

void dfs(int v) {
    if (u[v]) return;
    u[v] = 1;
    visit.erase(visit.find(v));
    if (visit.empty()) success();
    int cnt = 0, cur = 0;
    while (v != 1 || cnt < k) {
        set<int>::iterator it = visit.lower_bound(cur + 1);
        if (it == visit.end()) break;
        cur = *it;
        if (cur == v || s[v].find(cur) != s[v].end()) continue;
        dfs(cur);
        ++cnt;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    while (m--) {
        cin >> x >> y;
        s[x].insert(y);
        s[y].insert(x);
    }
    if (n - s[1].size() - 1 < k) fail();
    for (int i = 1; i <= n; ++i)
        visit.insert(i);

    dfs(1);

    fail();

    return 0;
}