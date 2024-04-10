#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, con[maxn], c[maxn];

void add(int p) {
    for (; p <= n << 1; p += p & -p) c[p]++;
}

int query(int p) {
    int tot = 0;
    for (; p; p -= p & -p) tot += c[p];
    return tot;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d %d", &x, &y);
        con[x] = y, con[y] = x;
    }
    long long s1 = 0, s2 = 0;
    for (int i = 1; i <= n << 1; i++) if (con[i] < i) {
        int x = query(i) - query(con[i] - 1), y = i - con[i] - 1 - x * 2;
        s1 += 1LL * y * (n - 1 - y);
        s2 += 1LL * x * (n - 1 - x - y);
        add(con[i]);
    }
    printf("%lld\n", 1LL * n * (n - 1) * (n - 2) / 6 - s1 / 2 - s2);
    return 0;
}