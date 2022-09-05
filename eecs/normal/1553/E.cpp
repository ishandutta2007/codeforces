#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int T, n, m, p[maxn], num[maxn], nxt[maxn], vis[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        fill(num, num + n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]), p[i]--;
            num[(i - p[i] + n) % n]++;
        }
        for (int k = 0; k < n; k++) if (num[k] >= n / 3) {
            fill(vis, vis + n, 0);
            int c = n;
            for (int i = 0; i < n; i++) if (!vis[i]) {
                c--;
                for (int j = i; !vis[j]; j = p[(j + k) % n]) vis[j] = 1;
            }
            if (c <= m) ans.push_back(k);
        }
        printf("%d", ans.size());
        for (int x : ans) printf(" %d", x);
        putchar('\n');
    }
    return 0;
}