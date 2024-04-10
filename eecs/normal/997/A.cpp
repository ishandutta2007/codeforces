#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, x, y;
char s[maxn];

int main() {
    scanf("%d %d %d %s", &n, &x, &y, s + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (s[i] == '0') {
        int j = i;
        while (j <= n && s[j] == '0') j++;
        cnt++, i = j;
    }
    printf("%lld\n", min(1LL * cnt * y, y + 1LL * max(0, cnt - 1) * x));
    return 0;
}