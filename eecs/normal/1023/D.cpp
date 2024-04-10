#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, a[maxn], nxt[maxn], L[maxn], R[maxn];

int find(int x) {
    return x == nxt[x] ? x : nxt[x] = find(nxt[x]);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), R[a[i]] = i;
        if (!L[a[i]]) L[a[i]] = i;
    }
    iota(nxt + 1, nxt + n + 2, 1);
    if (!L[q]) {
        for (int i = 1; i <= n; i++) {
            if (!a[i]) { a[i] = q, L[q] = R[q] = i; break; }
        }
        if (!L[q]) puts("NO"), exit(0);
    }
    for (int i = q; i > 1; i--) {
        if (!L[i]) continue;
        for (int j = find(L[i]); j <= R[i]; j = find(j)) {
            if (!a[j]) a[j] = i;
            if (a[j] ^ i) puts("NO"), exit(0);
            nxt[j] = j + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i]) a[i] = 1;
    }
    puts("YES");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}