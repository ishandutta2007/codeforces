#include <bits/stdc++.h>

#define MAXN 100100

using namespace std;

int sz[MAXN], st[MAXN], ft[MAXN], ver[MAXN], color[MAXN], cnt[MAXN], t = 1;
int max_color_size = -1, a, b, n;
long long q[MAXN], ans = -1;
vector<int> adj[MAXN];

void calc(int node, int parent) {
    sz[node] = 1;

    ver[t] = node;
    st[node] = t++;

    for(int i=0;i<adj[node].size();i++) {
        int v = adj[node][i];
        if(v == parent) continue;

        calc(v, node);
        sz[node] += sz[v];
    }

    ft[node] = t;
}

void add(int color) {
    cnt[color]++;
    if(cnt[color] > max_color_size) {
        ans = color;
        max_color_size = cnt[color];
    }

    else if(cnt[color] == max_color_size)
        ans += color;
}

void dfs(int node, int parent, bool keep) {
    int big_child = -1, max_sz = -1;

    for(int i=0;i<adj[node].size();i++) {
        int v = adj[node][i];
        if(v != parent && sz[v] > max_sz) {
            big_child = v;
            max_sz = sz[v];
        }
    }

    for(int i=0;i<adj[node].size();i++) {
        int v = adj[node][i];
        if(v != parent && v != big_child)
            dfs(v, node, 0);
    }

    if(big_child != -1)
        dfs(big_child, node, 1);

    for(int i=0; i<adj[node].size();i++) {
        int v = adj[node][i];
        if(v == parent || v == big_child) continue;

        for(int T = st[v]; T < ft[v]; T++) {
            int newVertex = ver[T];
            add(color[newVertex]);
        }
    }
    add(color[node]);
    assert(ans != -1 && max_color_size != -1);
    q[node] = ans;

    if(keep) return;

    for(int T = st[node]; T < ft[node]; T++) {
        int newVertex = ver[T];
        cnt[color[newVertex]]--;
        assert(cnt[color[newVertex]] >= 0);
    }

    max_color_size = -1;
    ans = -1;

}

int main() {
    scanf("%d", &n);

    for(int i=1;i<=n;i++) {
        scanf("%d", &color[i]);
    }

    for(int i=1;i<n;i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calc(1, -1);
    dfs(1, -1, 0);

    for(int i=1;i<=n;i++) {
        printf("%lld ", q[i]);
    }
    return 0;
}