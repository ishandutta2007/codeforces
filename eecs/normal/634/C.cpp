#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, A, B, q, c1[maxn], c2[maxn], cur[maxn];

void add1(int p, int v) {
    for (; p <= n; p += p & -p) c1[p] += v;
}

int sum1(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c1[p];
    return s;
}

void add2(int p, int v) {
    for (; p; p -= p & -p) c2[p] += v;
}

int sum2(int p) {
    int s = 0;
    for (; p <= n; p += p & -p) s += c2[p];
    return s;
}

int main() {
    scanf("%d %d %d %d %d", &n, &K, &A, &B, &q);
    for (int _ = 1, op, x, y; _ <= q; _++) {
        scanf("%d %d", &op, &x);
        if (op == 1) {
            scanf("%d", &y);
            add1(x, -min(B, cur[x]));
            add2(x, -min(A, cur[x]));
            cur[x] += y;
            add1(x, min(B, cur[x]));
            add2(x, min(A, cur[x]));
        } else {
            printf("%d\n", sum1(x - 1) + sum2(x + K));
        }
    }
    return 0;
}