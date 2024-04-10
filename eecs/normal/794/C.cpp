#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n;
char s[maxn], t[maxn], ans[maxn];

int main() {
    scanf("%s %s", s + 1, t + 1), n = strlen(s + 1);
    sort(s + 1, s + n + 1);
    sort(t + 1, t + n + 1);
    int l1 = 1, r1 = n;
    int l2 = 1, r2 = n;
    for (int i = 1, cur = 0; i <= n; i++, cur ^= 1) {
        if (!cur) {
            if (s[l1] < t[r2]) {
                ans[i] = s[l1++];
            } else {
                int cnt = (n + 1) / 2 - i / 2;
                l1 += cnt - 1;
                cnt = n / 2 - (i - 1) / 2;
                r2 -= cnt - 1;
                for (int j = n; j >= i; j--) {
                    if (!((n - j) & 1)) ans[j] = s[l1--];
                    else ans[j] = t[r2++];
                }
                break;
            }
        } else {
            if (t[r2] > s[l1]) {
                ans[i] = t[r2--];
            } else {
                int cnt = (n + 1) / 2 - i / 2;
                l1 += cnt - 1;
                cnt = n / 2 - (i - 1) / 2;
                r2 -= cnt - 1;
                for (int j = n; j >= i; j--) {
                    if (!((n - j) & 1)) ans[j] = t[r2++];
                    else ans[j] = s[l1--];
                }
                break;
            }
        }
    }
    printf("%s\n", ans + 1);
    return 0;
}