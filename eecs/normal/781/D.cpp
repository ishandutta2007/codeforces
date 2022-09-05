#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, m;
struct mat { bitset<maxn> b[maxn]; } A, b[61][2];

mat operator * (const mat &A, const mat &B) {
    mat C;
    for (int i = 1; i <= n; i++) {
        C.b[i].reset();
        for (int j = 1; j <= n; j++) {
            if (A.b[i][j]) C.b[i] |= B.b[j];
        }
    }
    return C;
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v, t; scanf("%d %d %d", &u, &v, &t);
        if (!t) b[0][0].b[u].set(v);
        else b[0][1].b[u].set(v);
    }
    for (int i = 1; i <= 60; i++) {
        b[i][0] = b[i - 1][0] * b[i - 1][1];
        b[i][1] = b[i - 1][1] * b[i - 1][0];
    }
    A.b[1].set(1);
    long long ans = 0;
    for (int i = 60, j = 0; ~i; i--) {
        mat tmp = A * b[i][j];
        if (tmp.b[1].any()) A = tmp, ans |= 1LL << i, j ^= 1;
    }
    printf("%lld\n", ans > 1e18 ? -1 : ans);
    return 0;
}