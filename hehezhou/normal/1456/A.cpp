#include <bits/stdc++.h>
using namespace std;
int T;
int n, p, k, x, y;
char s[100010];
int qwq[100010];
void rmain() {
    scanf("%d%d%d", &n, &p, &k);
    scanf("%s", s + 1);
    for (int i = n; i > 0; i--) {
        if (i + k > n) qwq[i] = 0;
        else qwq[i] = qwq[i + k];
        if (s[i] == '0') qwq[i]++;
    }
    int ans = 0x3f3f3f3f;
    scanf("%d%d", &x, &y);
    for (int i = p; i <= n; i++) ans = min(ans, qwq[i] * x + (i - p) * y);
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}