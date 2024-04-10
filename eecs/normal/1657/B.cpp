#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, B, x, y;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &B, &x, &y);
        long long ans = 0;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (cur + x <= B) cur += x;
            else cur -= y;
            ans += cur;
        }
        printf("%lld\n", ans);
    }
    return 0;
}