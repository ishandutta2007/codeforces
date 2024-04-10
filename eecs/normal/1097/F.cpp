#include <bits/stdc++.h>
using namespace std;

int n, q, mu[7010];
bitset<7010> b[100010], c[7010], d[7010];

int main() {
    scanf("%d %d", &n, &q), mu[1] = 1;
    for (int i = 1; i <= 7000; i++) {
        for (int j = i + i; j <= 7000; j += i) mu[j] -= mu[i];
    }
    for (int i = 1; i <= 7000; i++) {
        for (int j = i; j <= 7000; j += i) {
            c[j].set(i);
            if (mu[j / i]) d[i].set(j);
        }
    }
    while (q--) {
        int op, x, y, z, v; scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d", &x, &v);
            b[x] = c[v];
        } else if (op == 2) {
            scanf("%d %d %d", &x, &y, &z);
            b[x] = (b[y] ^ b[z]);
        } else if (op == 3) {
            scanf("%d %d %d", &x, &y, &z);
            b[x] = (b[y] & b[z]);
        } else {
            scanf("%d %d", &x, &v);
            putchar(((b[x] & d[v]).count() % 2) + '0');
        }
    }
    return 0;
}