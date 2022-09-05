#include <bits/stdc++.h>
using namespace std;

int n, m, q, ban[1000010];
char s[1000010];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + (i - 1) * m + 1);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (s[(i - 2) * m + j] == 'X' && s[(i - 1) * m + j - 1] == 'X') ban[j]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        ban[i] += ban[i - 1];
    }
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        puts(ban[r] > ban[l] ? "No" : "Yes");
    }
    return 0;
}