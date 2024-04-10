#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int s = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), s |= a[i];
        }
        printf("%d\n", s);
    }
    return 0;
}