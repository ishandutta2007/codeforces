#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int maxn = 1111111;
int fa[maxn], head[maxn], dist[maxn], q[maxn], s[maxn];
bool visit[maxn];
int n, m, k, num;

struct Edge{
    int x, next;
}gragh[maxn * 2];

int find(int u){
    if (fa[u] == u) return u;
    fa[u] = find(fa[u]);
    return fa[u];
}

void add_edge(int x, int y){
    gragh[++num].x = y;
    gragh[num].next = head[x];
    head[x] = num;
}

void solve(int start){
    int l = 1, r = 1;
    q[l] = start;
    s[l] = 0;
    visit[start] = true;
    while (l <= r){
        int now = q[l];
        for (int i = head[now]; i; i = gragh[i].next)
            if (!visit[gragh[i].x]){
                visit[gragh[i].x] = true;
                q[++r] = gragh[i].x;
                s[r] = s[l] + 1;
            }
        ++l;
    }
    int tmp = q[r];
    for (int i = 1; i <= r; ++i){
        fa[q[i]] = start;
        visit[q[i]] = false;
    }
    l = r = 1;
    q[l] = tmp; s[l] = 0;
    visit[tmp] = true;
    while (l <= r){
        int now = q[l];
        for (int i = head[now]; i; i = gragh[i].next){
            if (!visit[gragh[i].x]){
                visit[gragh[i].x] = true;
                q[++r] = gragh[i].x;
                s[r] = s[l] + 1;
            }
        }
        ++l;
    }
    dist[start] = s[r];
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    int num = 0;
    for (int i = 1; i <= m; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }
    for (int i = 1; i <= n; ++i) fa[i] = i;
    memset(visit, false, sizeof(visit));
    for (int i = 1; i <= n; ++i)
        if (!visit[i]) solve(i);
    for (; k; --k){
        int kind, x, y;
        scanf("%d", &kind);
        if (kind == 1){
            scanf("%d", &x);
            printf("%d\n", dist[find(x)]);
        } else {
            scanf("%d%d", &x, &y);
            int u = find(x), v = find(y);
            if (u == v) continue;
            fa[u] = v;
            dist[v] = max(max(dist[u], dist[v]), (1 + (dist[u] + 1) / 2 + (dist[v] + 1) / 2));
        }
    }
    return 0;
}