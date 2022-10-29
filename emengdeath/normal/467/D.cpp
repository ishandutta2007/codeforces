#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int N = 1e6;
int n, m;
map<string, int> w;
vector<int> g[N], gg[N];
pair<int, int> f[N], v[N];
int du[N];
string s;
int tot = 0;
int a[N];
pair<int, pair<int, int> > read() {
    cin>>s;
    int len = s.length();
    int sum = 0;
    for (int i = 0; i < len; i ++)
    {
        int x = ((s[i]>='A' && s[i]<= 'Z') ? s[i] - 'A' + 1: s[i] - 'a' + 1);
        s[i] = x;
        sum += (x == 'r' - 'a' + 1);
    }
    if (w.find(s) == w.end()) {
        f[w[s] = ++tot] = {sum, len};
    }
    return {w[s], {sum, len}};
}
int dfn[N], low[N], stack[N], cnt, instack[N];
int belong[N], cntscc;
void dfs(int x) {
    low[x] = dfn[x] = ++cnt;
    instack[stack[++stack[0]] = x] = 1;
    for (auto u:g[x])
        if (!dfn[u]) {
            dfs(u);
            low[x] = min(low[x], low[u]);
        }else
        if (instack[u])
            low[x] = min(low[x], dfn[u]);
    if (dfn[x] == low[x]) {
        ++cntscc;
        v[cntscc] = {1e9, 1e9};
        do{
            v[cntscc] = min(v[cntscc], f[stack[stack[0]]]);
            belong[stack[stack[0]]] = cntscc;
            instack[stack[stack[0]--]] = 0;
        } while (stack[stack[0] + 1] != x);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++){
        auto u = read();
        a[i] = u.first;
    }
    scanf("%d", &m);
    while (m --) {
        auto u = read();
        auto v = read();
        g[v.first].push_back(u.first);
    }
    for (int i = 1; i <= tot; i ++)
        if (!dfn[i]) {
            dfs(i);
        }
    for (int i = 1; i <= tot; i ++) {
        for (auto u:g[i])
        if (belong[i] != belong[u]){
            gg[belong[i]].push_back(belong[u]);
            du[belong[u]] ++;
        }
    }
    vector<int> d;
    for (int i = 1; i <= cntscc; i ++) {
        if (!du[i])
            d.push_back(i);
    }
    for (int i = 0; i < d.size(); i ++)
        for (auto u:gg[d[i]]) {
            v[u] = min(v[u], v[d[i]]);
            if (!(--du[u]))
                d.push_back(u);
        }
    long long ans0 = 0, ans1 = 0;
    for (int i = 1; i <= n; i ++)
        ans0 += v[belong[a[i]]].first, ans1 += v[belong[a[i]]].second;
    printf("%lld %lld", ans0, ans1);
    return 0;
}