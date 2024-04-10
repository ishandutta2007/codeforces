#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 * 2 + 10;
vector <int> e[N];
queue <int> q;
int n, m, i, s, t, v[N], x[N], y[N], c[N], ans[N], f[N], g[N];

int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++){
        scanf("%d%d%d", &x[i], &y[i], &c[i]);
        f[x[i]] += c[i];
        f[y[i]] += c[i];
        e[x[i]].push_back(i);
        e[y[i]].push_back(i);
    }
    q.push(1);
    while (!q.empty()){
        s = q.front();
        q.pop();
        v[s] = 1;
        for (i = 0; i < e[s].size(); i++){
            t = s ^ x[e[s][i]] ^ y[e[s][i]];
            if (v[t]) continue;
            g[t] += c[e[s][i]];
            if (g[t] + g[t] == f[t] && t != n) q.push(t);
            if (s == x[e[s][i]]) ans[e[s][i]] = 0; else ans[e[s][i]] = 1;
        }
    }
    for (i = 1; i <= m; i++) printf("%d\n", ans[i]);
}