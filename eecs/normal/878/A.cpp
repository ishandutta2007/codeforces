#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, ans1, ans2, num[maxn];
char op[maxn][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s %d", op[i], &num[i]);
    }
    for (int i = 0; i < 10; i++) {
        int x = 0, y = 1;
        for (int j = 1; j <= n; j++) {
            int t = num[j] >> i & 1;
            if (op[j][0] == '|') x |= t, y |= t;
            if (op[j][0] == '&') x &= t, y &= t;
            if (op[j][0] == '^') x ^= t, y ^= t;
        }
        if (x && y) {
            ans1 |= 1 << i;
        } else if (!x && !y) {
            ans1 |= 1 << i;
            ans2 |= 1 << i;
        } else if (x && !y) {
            ans2 |= 1 << i;
        } else {
            
        }
    }
    puts("2");
    printf("| %d\n", ans1);
    printf("^ %d\n", ans2);
    return 0;
}