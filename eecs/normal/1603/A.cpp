#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            int p = 2;
            while (a[i] % p == 0) p++;
            if (p > i + 1) flag = 0;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}