#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T, n;
ll a[20];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            while (!(a[i] % 2)) a[i] /= 2, cnt++;
        }
        sort(a + 1, a + n + 1);
        a[n] *= 1LL << cnt;
        printf("%lld\n", accumulate(a + 1, a + n + 1, 0LL));
    }
    return 0;
}