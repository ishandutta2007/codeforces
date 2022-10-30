#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<LL, LL> PI;

const DB eps = 1e-8;
const int N = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
struct Edge{
    int y, next;
} e[N];
PI p[N], dp[N];
int v[N], dfn[N], low[N], top, inz[N], z[N], a[N], fa[N], head[N], tot, x[N], y[N], tim = 0;
map <string, int> S;
string s;

PI Get(string s){
    PI ret = MP(0, s.size());
    for (int i = 0; i < s.size(); i++)
    if (s[i] == 'r') ret.first++;
    return ret;
}

void Addedge(int x, int y){
    e[++tot].y = y; e[tot].next = head[x]; head[x] = tot;
}
void Pop(int x){
    int l = inz[x];
    for (int i = l; i <= top; i++){
        fa[z[i]] = x;
        inz[z[i]] = 0;
        p[x] = min(p[x], p[z[i]]);
    }
    top = l - 1;
}

void Tarjan(int x){
    v[x] = 1;
    dfn[x] = low[x] = ++tim;
    z[++top] = x; inz[x] = top;
    for (int p = head[x]; p != -1; p = e[p].next)
    if (!v[e[p].y]){
        Tarjan(e[p].y);
        low[x] = min(low[x], low[e[p].y]);
    }else if (inz[e[p].y]) low[x] = min(low[x], dfn[e[p].y]);
    if (low[x] == dfn[x]) Pop(x);
}

PI Dfs(int x){
    if (v[x]) return dp[x];
    v[x] = 1; dp[x] = p[x];
    for (int p = head[x]; p != -1; p = e[p].next)
        dp[x] = min(dp[x], Dfs(e[p].y));
    return dp[x];
}


int main(){
    int n, m, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        if (s[j] >= 'A' && s[j] <= 'Z') s[j] = s[j] - 'A' + 'a';
        if (!S[s]){
            S[s] = ++cnt;
            p[cnt] = Get(s);
            fa[cnt] = cnt;
        }
        a[i] = S[s];
    }
    scanf("%d", &m);
    tot = -1, memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++){
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        if (s[j] >= 'A' && s[j] <= 'Z') s[j] = s[j] - 'A' + 'a';
        if (!S[s]){
            S[s] = ++cnt;
            p[cnt] = Get(s);
            fa[cnt] = cnt;
        }
        x[i] = S[s];
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        if (s[j] >= 'A' && s[j] <= 'Z') s[j] = s[j] - 'A' + 'a';
        if (!S[s]){
            S[s] = ++cnt;
            p[cnt] = Get(s);
            fa[cnt] = cnt;
        }
        y[i] = S[s];
        Addedge(x[i], y[i]);
    }

    for (int i = 1; i <= cnt; i++)
    if (!v[i]) Tarjan(i);

    tot = -1, memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++)
    if (fa[x[i]] != fa[y[i]]) Addedge(fa[x[i]], fa[y[i]]);
    PI ans = MP(0, 0);

    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; i++){
        Dfs(fa[a[i]]);
        ans.first += dp[fa[a[i]]].first;
        ans.second += dp[fa[a[i]]].second;
    }

    printf("%I64d %I64d\n", ans.first, ans.second);
}