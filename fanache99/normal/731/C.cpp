#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

vector<int> g[1 + MAXN];
int color[1 + MAXN], last[1 + MAXN], socks[1 + MAXN];
bool seen[1 + MAXN];
int biggest, nodes, step = 0;

void DFS(int node) {
    nodes++;
    seen[node] = true;
    int now = color[node];
    if (last[now] != step) {
        last[now] = step;
        socks[now] = 1;
    }
    else
        socks[now]++;
    biggest = max(biggest, socks[now]);
    for (auto &it : g[node])
        if (!seen[it])
            DFS(it);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, k, answer = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &color[i]);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!seen[i]) {
            step++;
            biggest = nodes = 0;
            DFS(i);
            answer = answer + nodes - biggest;
        }
    printf("%d\n", answer);
    return 0;
}