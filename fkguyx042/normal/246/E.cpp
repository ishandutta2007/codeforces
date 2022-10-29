#include<cstdio>
#include<utility>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<iterator>
#include<iostream>
using namespace std;

#define maxn 100010
typedef pair<int, int> pii;


vector<int> adj[maxn];
vector< pii > point[maxn];

map<pii, int> vis;
char s[maxn][23];
int pos[maxn][2], depth[maxn], tot, n, v, k;

void dfs(int k, int d) {
    pos[k][0] = ++tot;
    point[d].push_back(make_pair(tot, k));
    depth[k] = d;
    for (vector<int>::iterator p = adj[k].begin(); p != adj[k].end(); ++p) {
        dfs(*p, d + 1);
    }
    pos[k][1] = ++tot;
}

int solve() {
    if (vis[make_pair(v, k)])
        return vis[make_pair(v, k)] - 1;
    vector<pii>::iterator l, r;
    set <string> str;
    l = lower_bound(point[depth[v] + k].begin(), point[depth[v] + k].end(), make_pair(pos[v][0], maxn));
    r = lower_bound(point[depth[v] + k].begin(), point[depth[v] + k].end(), make_pair(pos[v][1], 0));
    for (vector<pii>::iterator p = l; p != r; ++p) {
        str.insert(s[(*p).second]);
    }
    return (vis[make_pair(v, k)] = str.size() + 1) - 1;
}

int main() {
    int m, i, p;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%s%d", &s[i], &p);
        adj[p].push_back(i);
    }
    dfs(0, 0);
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &v, &k);
        printf("%d\n", solve());
    }
    return 0;
}