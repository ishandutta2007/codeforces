#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int T, x;
char s[1000010];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &x, s + 1);
        int len = strlen(s + 1), ans = len;
        for (int i = 1; i <= x; i++) {
            ans = (ans + 1LL * (ans - i + P) * (s[i] - '0' - 1)) % P;
            if (len < x) {
                for (int j = len + 1; j <= min(x, len + (len - i) * (s[i] - '0' - 1)); j++) {
                    s[j] = s[j - (len - i)];
                }
                len = min(x, len + (len - i) * (s[i] - '0' - 1));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}