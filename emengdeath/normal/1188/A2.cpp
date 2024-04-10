#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
const int N = 1001;
vector<pair<int, int> > g[N];
vector<int> p[N];
vector<pair<pair<int, int>, long long> > ans;
int fa[N], deep[N], hlim[N], a[N], faa[N];
long long co[N][N];
long long lim[N];
int n;
int getfa(int x)
{
    return faa[x] == x? x : faa[x] = getfa(faa[x]);
}
void dfs(int x) {
    deep[x] ++;
    if (g[x].size() == 1) {
        p[x].push_back(x);
        lim[x] = hlim[x];
        return;
    }
    for (auto u:g[x])
        if (u.first != fa[x]) {
            fa[u.first] = x;
            hlim[u.first] = u.second;
            deep[u.first] = deep[x];
            dfs(u.first);
        }
}
bool cmp(int x, int y) {
    return deep[x] > deep[y];
}

void add(int x ,int y, long long v) {

    while (v >= 1e9) {
        ans.push_back(make_pair(make_pair(x, y), 1e9));
        v -= 1e9;
    }
    while (v < -1e9) {
        ans.push_back(make_pair(make_pair(x, y), -1e9));
        v += 1e9;
    }
    ans.push_back(make_pair(make_pair(x, y), v));
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n ; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    if (n == 2) {
        printf("YES\n");
        printf("1\n");
        printf("1 2 %d\n", g[1][0].second);
        return 0;
    }
    int root = 1;
    while (g[root].size() == 1) root++;
    for (int i = 1; i <= n ; i ++)
        if (g[i].size() >= 3) {
            root = i;
            break;
        }
    dfs(root);
    for (int i = 1; i <= n; i ++)
        a[i] = i, faa[i] = i;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++) {
        int x = a[i];
        long long all = 0;
        for (auto u:p[x])
            all += lim[u];
        if (all != hlim[x] && p[x].size() == 1) {
            printf("NO\n");
            return 0;
        }
        if (abs(all - hlim[x]) & 1) {
            printf("NO\n");
            return 0;
        }
        long long v = (all - hlim[x]) / 2;
        if (v != 0) {
            int y = 0;
            int z = 0;
            while (z < p[x].size()&& faa[p[x][z]] == faa[p[x][y]] ) z++;
            if (z == p[x].size()) {
                printf("NO\n");
                return 0;
            }
            y = p[x][y];
            z = p[x][z];
            lim[y] -= v;
            lim[z] -= v;
            co[y][z] += v;
        }
        if (x == root) break;
        for (auto u:p[x])
            if (lim[u])
                p[fa[x]].push_back(u), faa[u] = x;
    }
    vector<int> d=p[root];
    for (int i = 1; i < d.size(); i ++)
    {
        if (faa[d[i]]  != faa[d[0]]) {
            swap(d[1], d[i]);
            break;
        }
    }
    for (int i = 2; i < d.size(); i ++)
        if (faa[d[i]] != faa[d[1]]) {
            co[d[1]][d[i]] += lim[d[i]];
            lim[d[1]] -= lim[d[i]];
            lim[d[i]] = 0;
        }

    for (int i = 1; i < d.size(); i ++)
        if (faa[d[i]] != faa[d[0]]) {
            co[d[0]][d[i]] += lim[d[i]];
            lim[d[0]] -= lim[d[i]];
            lim[d[i]] = 0;
        }
    if (lim[d[0]]) {
        int z = 0;
        while (z < d.size() && (faa[d[z]] == faa[d[0]] || faa[d[z]] == faa[d[1]])) z ++;
        if (z == d.size()) {
            printf("NO");
            return 0;
        }
        if (abs(lim[d[0]]) & 1) {
            printf("NO");
            return 0;
        }
        co[d[0]][d[1]] += lim[d[0]] / 2;
        co[d[0]][d[z]] += lim[d[0]] / 2;
        co[d[z]][d[1]] -= lim[d[0]] / 2;
    }
    for (int i = 1; i <= n ; i ++)
        for (int j = i + 1; j <= n; j ++)
            if ((co[i][j]+= co[j][i])) {
                add(i, j, co[i][j]);
            }
    printf("YES\n");
    printf("%d\n", ans.size());
    for (auto u:ans){
        printf("%d %d %lld\n", u.first.first, u.first.second, u.second);
    }
    return 0;
}