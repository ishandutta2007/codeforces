#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, a[maxn], vis[maxn];
char s[maxn], t[maxn];

int main() {
    scanf("%s %s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    auto chk = [&](int x) {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= x; i++) {
            vis[a[i]] = 1;
        }
        int j = 1;
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            if (s[i] == t[j]) j++;
        }
        return j > m;
    };
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}