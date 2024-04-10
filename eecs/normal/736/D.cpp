#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, maxm = 500010;
int n, m, u[maxm], v[maxm];
bitset<maxn> b[maxn], c[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u[i], &v[i]), b[u[i]].set(v[i]);
    }
    for (int i = 1; i <= n; i++) {
        c[i].set(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) if (b[j][i]) {
            swap(b[i], b[j]), swap(c[i], c[j]); break;
        }
        for (int j = 1; j <= n; j++) if (i ^ j && b[j][i]) {
            b[j] ^= b[i], c[j] ^= c[i];
        }
    }
    for (int i = 1; i <= m; i++) {
        puts(c[v[i]][u[i]] ? "NO" : "YES");
    }
    return 0;
}