#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        bool flag = 0;
        for (int i = 1; i < n; i++) {
            flag |= *max_element(a + 1, a + i + 1) > *min_element(a + i + 1, a + n + 1);
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}