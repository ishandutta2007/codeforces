#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n;
char s[maxn], a[maxn], b[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &n, s + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') cnt++;
        }
        if (cnt & 1) { puts("NO"); continue; }
        if (s[1] == '0' || s[n] == '0') { puts("NO"); continue; }
        int s1 = 0, s2 = 1;
        int cnt1 = 1, cnt2 = 1;
        bool flag = 1;
        for (int i = 2; i < n; i++) {
            if (s[i] == '0') {
                if (++s1 % 2 == 1) {
                    a[i] = '(', b[i] = ')';
                    cnt1++, cnt2--;
                } else {
                    a[i] = ')', b[i] = '(';
                    cnt1--, cnt2++;
                }
            } else {
                if (++s2 <= (n - cnt) / 2) {
                    a[i] = b[i] = '(';
                    cnt1++, cnt2++;
                } else {
                    a[i] = b[i] = ')';
                    cnt1--, cnt2--;
                }
            }
            if (cnt1 < 0 || cnt2 < 0) { flag = 0; break; }
        }
        if (!flag) { puts("NO"); continue; }
        puts("YES");
        a[1] = b[1] = '(', a[n] = b[n] = ')';
        for (int i = 1; i <= n; i++) {
            putchar(a[i]);
        }
        putchar('\n');
        for (int i = 1; i <= n; i++) {
            putchar(b[i]);
        }
        putchar('\n');
    }
    return 0;
}