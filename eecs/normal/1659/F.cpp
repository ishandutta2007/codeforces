#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, x, d[maxn], p[maxn];
bool vis[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        fill(d + 1, d + n + 1, 0);
        for (int i = 1, u, v; i < n; i++) {
            scanf("%d %d", &u, &v);
            d[u]++, d[v]++;
        }
        int rt = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            if (p[i] ^ i) cnt++;
            if (d[i] == n - 1) rt = i;
        }
        if (!rt || !cnt || cnt == 2 && p[x] == x) { puts("Alice"); continue; }
        if (p[rt] ^ rt && (x == rt || x == p[rt])) { puts("Bob"); continue; }
        cnt = (x != rt) ^ (n % 2);
        fill(vis + 1, vis + n + 1, 0);
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            for (int j = i; !vis[j]; j = p[j]) vis[j] = 1;
            cnt ^= 1;
        }
        puts(cnt ? "Alice" : "Bob");
    }
    return 0;
}