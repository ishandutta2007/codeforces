#include <bits/stdc++.h>
using namespace std;

const int maxn = 755, maxm = 10000010;
int n, tot = 1, ch[maxm][2], ed[maxm], fail[maxm];
int cnt, head[maxn * 2], lev[maxn * 2];
char s[maxm];
vector<int> V[maxn];
bitset<maxn> b[maxn];
struct edge { int to, cap, nxt; } e[1500000];

void add_edge(int u, int v) {
    e[cnt] = (edge){v, 1, head[u]}, head[u] = cnt++;
    e[cnt] = (edge){u, 0, head[v]}, head[v] = cnt++;
}

bool bfs(int s, int t) {
    fill(lev, lev + t + 1, 0);
    queue<int> Q; Q.push(s), lev[s] = 1;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && !lev[e[i].to]) {
                Q.push(e[i].to), lev[e[i].to] = lev[v] + 1;
            }
        }
    }
    return lev[t];
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    int inc = 0;
    for (int i = head[v]; ~i && inc < f; i = e[i].nxt) {
        if (e[i].cap && lev[e[i].to] == lev[v] + 1) {
            int d = dfs(e[i].to, t, min(e[i].cap, f - inc));
            e[i].cap -= d, e[i ^ 1].cap += d, inc += d;
        }
    }
    if (!inc) lev[v] = -1;
    return inc;
}

int dinic(int s, int t) {
    int f = 0;
    while (bfs(s, t)) f += dfs(s, t, INT_MAX);
    return f;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int cur = 1, len = strlen(s + 1);
        for (int j = 1; j <= len; j++) {
            int c = s[j] - 'a';
            if (!ch[cur][c]) ch[cur][c] = ++tot;
            cur = ch[cur][c], V[i].push_back(cur);
        }
        ed[cur] = i;
    }
    queue<int> Q;
    Q.push(ch[0][0] = ch[0][1] = 1);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        if (!ed[v]) ed[v] = ed[fail[v]];
        for (int c : {0, 1}) {
            if (!ch[v][c]) {
                ch[v][c] = ch[fail[v]][c];
            } else {
                Q.push(ch[v][c]), fail[ch[v][c]] = ch[fail[v]][c];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int p : V[i]) {
            if (ed[p]) b[i].set(ed[p]);
            if (ed[fail[p]]) b[i].set(ed[fail[p]]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[j].test(i)) b[j] |= b[i];
        }
    }
    int s = 0, t = 2 * n + 1;
    for (int i = 1; i <= n; i++) {
        add_edge(s, i), add_edge(i + n, t);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i ^ j) {
            if (b[i].test(j)) add_edge(i, j + n);
        }
    }
    printf("%d\n", n - dinic(s, t));
    for (int i = 1; i <= n; i++) {
        if (lev[i] > 0 && lev[i + n] <= 0) printf("%d ", i);
    }
    return 0;
}