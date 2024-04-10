#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        printf("%d %d\n", min_element(a + 1, a + n + 1) - a,
            max_element(a + 1, a + n + 1) - a);
    }
    return 0;
}