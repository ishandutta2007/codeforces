#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, m, a[maxn], b[maxn];

int main() {
    scanf("%d %d", &n, &m);
    int s = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), s ^= a[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]), s ^= b[i];
    }
    if (s) puts("NO"), exit(0);
    puts("YES");
    int num = a[n];
    for (int i = 1; i < m; i++) num ^= b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i < n) printf("%d ", j < m ? 0 : a[i]);
            else printf("%d ", j < m ? b[j] : num);
        }
        putchar('\n');
    }
    return 0;
}