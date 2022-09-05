#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], nxt[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i; i--) {
        if (i == n || a[i] >= a[i + 1]) nxt[i] = i;
        else nxt[i] = nxt[i + 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, nxt[i] - i + 1);
        if (nxt[i] < n) ans = max(ans, nxt[i] + 1 - i + 1);
        if (nxt[i] < n && ((i == nxt[i] || a[nxt[i] + 1] > a[nxt[i] - 1] + 1) ||
            (nxt[nxt[i] + 1] == nxt[i] + 1 || a[nxt[i] + 2] > a[nxt[i]] + 1))) {
            ans = max(ans, nxt[nxt[i] + 1] - i + 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}