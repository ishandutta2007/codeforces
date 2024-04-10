#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 1;
vector<int>g[N], gg;
vector<int>d[2];
bool bz[N];
int leaf[N], deep[N], ssize[N], ggg;
int n;
int sum[N + 100], collect[N + 100];
bool check(vector<int> & a)
{
    for (int i = 1; i < a.size(); i ++)
        if (g[a[i]].size() != g[a[0]].size() || ssize[a[i]] != ssize[a[0]]) return 0;
    return 1;
}
void dfs(int x, int fa){
    deep[x] ++;
    for (auto u: g[x])
        if (fa != u){
            deep[u] = deep[x];
            dfs(u, x);
        }
}

bool check(int root){
    deep[root] = 0;
    dfs(root, 0);
    for (int i = 1; i <= n; i ++)
        collect[deep[i]] = 0;
    for (int i = 1; i<= n ; i ++)
        if (!collect[deep[i]]){
            collect[deep[i]] = g[i].size();
        } else
        if (collect[deep[i]] != g[i].size()){
            return 0;
        }
    return 1;
}
int main()
{
    scanf("%d", &n);
    if (n == 1){
        printf("1");
        return 0;
    }
    for (int i = 1;  i < n ; i ++){
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n ; i ++)
        if (g[i].size() == 1)
        {
           bz[i] = 1;
           d[0].push_back(i);
           leaf[i] = i;
        }
    bool sig = 0;
    bool is_able = 1;
    int root = 0;
    if (d[sig].size() == 1)d[sig][0];
    while (d[sig].size()){
        d[sig ^ 1].clear();
        if (d[sig].size() == 1)
            root = d[sig][0];
        if (!check(d[sig])){
            is_able = 0;
            for (auto u:d[sig]) {
                sum[g[u].size()]++;
                if (ssize[u] == 1) ggg = leaf[u];
            }
            for (auto u:d[sig])
                if (sum[g[u].size()] == 1)
                    gg.push_back(leaf[u]);
            break;
        }
        for (auto u:d[sig])
            for (auto v:g[u]) {
                if (!bz[v]) {
                    bz[v] = 1;
                    d[sig ^ 1].push_back(v);
                    leaf[v] = leaf[u];
                }
                ssize[v] ++;
            }
        sig ^= 1;
    }
    if (is_able && root)
    {
        printf("%d\n", root);
        return 0;
    }
    if (!gg.size()){
        for (auto u:d[sig ^ 1])
            sum[g[u].size()] ++;
        for (auto u:d[sig ^ 1])
            if (sum[g[u].size()] == 1)
                gg.push_back(leaf[u]);
        if (!gg.size())
            for (auto u:d[sig ^ 1])
                if (sum[g[u].size()] == d[sig^1].size()) {
                    gg.push_back(leaf[u]);
                    break;
                }
    }
    if (gg.size() > 2){
        if (ggg && check(ggg))
        {
            printf("%d\n", ggg);
            return 0;
        }
        printf("-1\n");
        return 0;
    }
    for (auto u:gg)
        if (check(u)){
            printf("%d\n", u);
            return 0;
        }
    if (ggg && check(ggg))
    {
        printf("%d\n", ggg);
        return 0;
    }
    printf("-1");
    return 0;
}