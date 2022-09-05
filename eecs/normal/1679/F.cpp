#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
int n, m, f[1 << 9], g[1 << 9], mask[10];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        mask[u] |= 1 << v, mask[v] |= 1 << u;
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        memset(g, 0, sizeof(g));
        for (int j = 0; j < 1 << 9; j++) {
            for (int k = 0; k < 10; k++) if (!(j >> k & 1)) {
                red(g[(j | ((1 << k) - 1)) & mask[k]] += f[j] - P);
            }
        }
        swap(f, g);
    }
    int s = 0;
    for (int i = 0; i < 1 << 9; i++) {
        red(s += f[i] - P);
    }
    cout << s << "\n";
    return 0;
}