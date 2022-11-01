#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1005 * 2;

int n, head[N], numE = 0, d[N], rt, w[N], s[N], faW[N];

int X[N], Y[N], Z[N], t;

struct E{
    int next, v, w;
} e[N << 1];

void inline add(int u, int v, int w) {
    e[++numE] = (E) { head[u], v, w };
    head[u] = numE;
}

bool o = 1;

void dfs(int u, int fa) {
    if (u != rt && !e[head[u]].next) {
        s[u] = u;
        return;
    }
    LL sum = 0;
    int v1 = -1, v2 = -1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        faW[v] = e[i].w;
        dfs(v, u);
        if (v1 == -1) v1 = s[v];
        else if (v2 == -1) v2 = s[v]; 
        s[u] = s[v];
        sum += e[i].w;
    }
    if (u != rt) {
        if (faW[u] > sum) {
            o = 0;
        }
        int nd = (sum - faW[u]) / 2;
        ++t;
        X[t] = v1, Y[t] = v2, Z[t] = nd;
        w[v1] -= nd, w[v2] -= nd;
    }
}

int main() {
    read(n);
    for (int i = 1, u, v, w; i < n; i++) {
        read(u), read(v), read(w);
        d[u]++, d[v]++;
        add(u, v, w), add(v, u, w);
    }
    for (int i = 1; i <= n; i++)
        if (d[i] == 2) o = 0;
    if (!o) { puts("NO"); return 0; }
    rt = 1;
    while (d[rt] != 1) rt++;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1 && i != rt) {
            w[i] = e[head[i]].w;
            //cout << i << "!!!!" << w[i] << endl;
        }
    }
    dfs(rt, 0);
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1 && i != rt) {
            ++t;
            X[t] = i, Y[t] = rt, Z[t] = w[i];
        }
    }
    //if (!o) { puts("NO"); return 0; }
    puts("YES");
    printf("%d\n", t);
    for (int i = 1; i <= t; i++) {
        printf("%d %d %d\n", X[i], Y[i], Z[i]);
    }
}