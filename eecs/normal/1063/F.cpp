#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, f[maxn], nxt[maxn], ed[maxn];
char s[maxn];

int main() {
    scanf("%d %s", &n, s + 1);
    for (int i = 1; i <= n + 1; i++) {
        nxt[i] = min(n + 1, i + 1);
    }
    fill(f + 1, f + n + 1, 1);
    for (int k = 2; ; k++) {
        bool flag = 0;
        for (int i = k - 1; i <= n; i++) {
            while (nxt[i] != n + 1 && s[i - k + 2] != s[nxt[i] - k + 2]) nxt[i] = nxt[nxt[i]];
        }
        for (int i = n; i >= k - 1; i--) {
            ed[i] = ed[nxt[i]] ? ed[nxt[i]] : (f[i] ? i : 0);
        }
        for (int i = k; i <= n; i++) {
            f[i] = 0;
            if (ed[i - 1] && ed[i - 1] - (k - 1) >= i) f[i] = 1;
            if (ed[i] && ed[i] - (k - 1) >= i) f[i] = 1;
            flag |= f[i];
        }
        if (!flag) { printf("%d\n", k - 1); break; }
    }
    return 0;
}