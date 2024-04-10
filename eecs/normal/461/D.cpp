#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, K, cnt, vis[maxn], val[maxn];
vector<pair<int, int>> G[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &K);
    while (K--) {
        int a, b; char s[2];
        scanf("%d %d %s", &a, &b, s);
        int c = s[0] == 'o';
        int l = (b <= a ? a - b + 1 : b - a + 1) + 1;
        int len = min({a, n - a + 1, b, n - b + 1});
        int r = l + 2 * (len - 1);
        G[l - 2].emplace_back(r, c), G[r].emplace_back(l - 2, c);
    }
    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        for (auto e : G[v]) {
            if (!vis[e.first]) {
                val[e.first] = val[v] ^ e.second, dfs(e.first);
            } else if (val[e.first] ^ val[v] ^ e.second) {
                puts("0"), exit(0);
            }
        }
    };
    for (int i = 0; i <= n + 1; i++) {
        if (!vis[i]) cnt++, dfs(i);
        if (!i && vis[1]) cnt++;
    }
    printf("%d\n", qp(2, cnt - 2));
    return 0;
}