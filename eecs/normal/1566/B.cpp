#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n;
char s[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1), n = strlen(s + 1);
        int ans = 2;
        bool flag0 = 1, flag1 = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') flag0 = 0;
            else flag1 = 0;
        }
        if (flag0) ans = 0;
        else if (flag1) ans = 1;
        int ans2 = 0;
        for (int i = 1; i <= n; i++) if (s[i] == '0') {
            ans2++;
            int j = i;
            while (j <= n && s[j] == '0') j++;
            i = j - 1;
        }
        printf("%d\n", min(ans, ans2));
    }
    return 0;
}