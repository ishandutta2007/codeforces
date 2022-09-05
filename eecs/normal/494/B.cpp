#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 100010, P = 1000000007, B = 233;
int n, m, f[maxn], g[maxn], g0[maxn];
char s[maxn], t[maxn];
ull h[maxn], ht, pw[maxn];
vector<int> V;

int main() {
    scanf("%s %s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    if (n < m) puts("0"), exit(0);
    for (int i = pw[0] = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * B;
        h[i] = h[i - 1] * B + s[i];
    }
    for (int i = 1; i <= m; i++) {
        ht = ht * B + t[i];
    }
    auto get = [&](int l, int r) {
        return h[r] - h[l - 1] * pw[m];
    };
    for (int i = 1; i + m - 1 <= n; i++) {
        if (get(i, i + m - 1) == ht) V.push_back(i);
    }
    g[0] = 1;
    for (int i = 1, j = 0; i <= n; i++) {
        int ways = 0;
        if (!V.empty() && V[0] + m - 1 <= i) {
            while (j + 1 < V.size() && V[j + 1] + m - 1 <= i) j++;
            ways = (1LL * V[j] * g[V[j] - 1] - g0[V[j] - 1] + P) % P;
        }
        g[i] = (g[i - 1] + ways) % P;
        g0[i] = (g0[i - 1] + 1LL * i * ways) % P;
    }
    printf("%d\n", (g[n] + P - 1) % P);
    return 0;
}