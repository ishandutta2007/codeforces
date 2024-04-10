#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
char s[maxn];
bool cur[4];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int lst0 = -1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            if (lst0 == -1) puts("1 1"), lst0 = 1;
            else puts("3 1"), lst0 = -1;
        } else {
            for (int j = 0; j < 4; j++) if (!cur[j]) {
                printf("%d %d\n", j + 1, 2);
                cur[j] = 1; break;
            }
            bool flag = 1;
            for (int j = 0; j < 4; j++) flag &= cur[j];
            if (flag) fill(cur, cur + 4, 0);
        }
    }
    return 0;
}