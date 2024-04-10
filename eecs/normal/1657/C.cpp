#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int T, n, p[maxn];
char s[maxn], t[maxn];
bool vis[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &n, s + 1);
        for (int i = 1; i <= n; i++) {
            t[i << 1] = s[i], t[i << 1 | 1] = '$';
        }
        t[0] = '.', t[1] = '$', n = n * 2 + 1;
        fill(p, p + n + 1, 0);
        int id, mx = 0;
        for (int i = 2; i < n; i++) {
            if (mx > i) p[i] = min(mx - i, p[2 * id - i]);
            while (t[i - p[i]] == t[i + p[i]]) p[i]++;
            if (i + p[i] > mx) mx = i + p[i], id = i;
        }
        n /= 2;
        int cur = 1, cnt = 0;
        while (cur < n) {
            if (s[cur] == '(' && s[cur + 1] == ')') {
                cnt++, cur += 2;
            } else {
                bool flag = 0;
                for (int i = cur + 1; i <= n; i++) {
                    if (i + cur - p[i + cur] < 2 * cur) {
                        cnt++, flag = 1, cur = i + 1; break;
                    }
                }
                if (!flag) break;
            }
        }
        printf("%d %d\n", cnt, n - cur + 1);
    }
    return 0;
}