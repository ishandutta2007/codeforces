#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, ans, p[maxn], b[maxn];
bool vis[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        ans++;
        for (int j = i; !vis[j]; j = p[j]) vis[j] = 1;
    }
    if (ans == 1) ans--;
    if (accumulate(b + 1, b + n + 1, 0) % 2 == 0) ans++;
    printf("%d\n", ans);
    return 0;
}