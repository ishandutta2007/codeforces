#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, x[maxn], y[maxn], fa[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d", &n);
    iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (x[i] == x[j] || y[i] == y[j]) fa[find(i)] = find(j);
        }
    }
    int C = 0;
    for (int i = 1; i <= n; i++) {
        if (i == find(i)) C++;
    }
    printf("%d\n", C - 1);
    return 0;
}