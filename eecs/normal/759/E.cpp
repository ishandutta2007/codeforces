#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 320010, P = 1000000007, B = 1e9;
int n, a[maxn], b[maxn], c[maxn], f[maxn * 2], g[maxn * 2], U[maxn], need[maxn];
char val[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= 20000; i++) {
        a[++n] = 1e9;
    }
    scanf("%s", val + 1);
    int len = strlen(val + 1), tot = 0;
    reverse(val + 1, val + len + 1);
    for (int i = 1; i <= len; i += 9) {
        tot++;
        for (int j = min(len, i + 8); j >= i; j--) {
            c[tot] = c[tot] * 10 + val[j] - '0';
        }
    }
    vector<array<int, 2>> V;
    for (int i = 1, j; i <= n; i = j + 1) {
        for (j = i; j < n && a[j + 1] == 1; j++);
        V.push_back({i, j});
    }
    for (int i = 0; i + 1 < V.size(); i++) {
        if (i) {
            long long x = 0;
            for (int j = tot; j; j--) {
                x = x * B + c[j];
                c[j] = x / a[V[i][0]], x %= a[V[i][0]];
            }
        }
        while (tot > 1 && !c[tot]) tot--;
        for (int j = tot; j; j--) {
            need[i] = (1LL * B * need[i] + c[j]) % a[V[i + 1][0]];
        }
        U[i] = accumulate(b + V[i][0], b + V[i][1] + 1, 0);
    }
    f[0] = 1;
    for (int i = 0, lim = 0; i + 1 < V.size(); i++) {
        int o = lim;
        lim = (i ? lim / a[V[i][0]] : 0) + U[i];
        if (lim < need[i]) puts("0"), exit(0);
        for (int j = V[i][0]; j <= V[i][1]; j++) if (b[j]) {
            copy(f, f + lim + 1, g);
            for (int k = 0, s = 0; k <= lim; k++) {
                red(s += f[k] - P);
                if (k > b[j]) red(s -= g[k - b[j] - 1]);
                f[k] = s;
            }
        }
        for (int j = 0; j <= lim; j++) {
            int o = f[j];
            if (j >= need[i] && (j - need[i]) % a[V[i + 1][0]] == 0) red(f[(j - need[i]) / a[V[i + 1][0]]] += o - P);
            red(f[j] -= o);
        }
    }
    printf("%d\n", f[0]);
    return 0;
}