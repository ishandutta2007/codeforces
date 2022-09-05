#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, K, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        bool flag = 0;
        for (int i = 1; i < n; i++) {
            if (binary_search(a + i + 1, a + n + 1, a[i] + K)) flag = 1;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}