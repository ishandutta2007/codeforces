#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;

int parent[300105],ranks[300105],ans[300105];
int n,m,q,x,y;
vector<int> g[300105];

int get_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = get_set(parent[v]);
}

void unite_sets(int a, int b, bool upd_ans = true) {
    a = get_set(a);
    b = get_set(b);
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap(a, b);
        parent[b] = a;
        if (upd_ans)
            ans[a] = max(max(ans[a], ans[b]), (ans[b] + 1) / 2 + (ans[a] + 1) / 2 + 1);
        if (ranks[a] == ranks[b])
            ++ranks[a];
    }
}

int u[300105],d[300105];

int diameter(int v) {
    vector<int> curg;
    queue< pii > q;
    q.push(make_pair(v, 0));
    while (!q.empty()) {
        int curv = q.front().first;
        int curd = q.front().second;
        q.pop();
        if (u[curv]) continue;
        u[curv] = 1;
        d[curv] = curd;
        curg.push_back(curv);
        ++curd;
        for (int i = 0; i < g[curv].size(); ++i)
            q.push(make_pair(g[curv][i], curd));
    }

    v = 0;
    for (int i = 0; i < curg.size(); ++i)
        if (d[v] < d[curg[i]])
            v = curg[i];

    q.push(make_pair(v, 0));
    while (!q.empty()) {
        int curv = q.front().first;
        int curd = q.front().second;
        q.pop();
        if (u[curv] == 2) continue;
        u[curv] = 2;
        d[curv] = curd;
        ++curd;
        for (int i = 0; i < g[curv].size(); ++i)
            q.push(make_pair(g[curv][i], curd));
    }

    v = 0;
    for (int i = 0; i < curg.size(); ++i)
        v = max(v, d[curg[i]]);
    return v;
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for (int i = 1; i <= n; ++i)
        parent[i] = i;
    while (m--) {
        scanf("%d%d",&x,&y);
        unite_sets(x, y, false);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        if (u[i]) continue;
        ans[get_set(i)] = diameter(i);
    }

    while (q--) {
        scanf("%d%d",&y,&x);
        if (y == 1) {
            printf("%d\n", ans[get_set(x)]);
        } else {
            scanf("%d",&y);
            unite_sets(x,y);
        }
    }

    return 0;
}