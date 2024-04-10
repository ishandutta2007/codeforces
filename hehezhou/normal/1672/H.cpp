#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[200010];
int sum1[200010], sum2[200010];
int main() {
    scanf("%d%d%s", &n, &m, s + 1);
    for (int i = 1; i <= n; i++) {
        s[i] -= '0';
        sum1[i] = sum1[i - 1];
        sum2[i] = sum2[i - 1];
        if (s[i] == s[i - 1]) (s[i] ? sum1 : sum2)[i]++;
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", 1 + max(sum1[r] - sum1[l], sum2[r] - sum2[l]));
    }
}