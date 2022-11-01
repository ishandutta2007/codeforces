#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    if(k == 1) {
        printf("YES\n%d\n", n);
        return 0;
    }
    if(k == 2) {
        if(n < 3 || n == 4) printf("NO\n");
        else printf("YES\n%d %d\n", (n-1)/2, n-(n-1)/2);
        return 0;
    }

    long long sum = 1LL * k * (k + 1) / 2;
    if(sum > n) puts("NO");
    else {
        int level = (n - sum) / k;
        n = (n - sum) % k;

        int llast = min((k-3) + level, n / 2);

        n -= 2 * llast;
        int last = min((k-2)+level+llast, n);
        n -= last;

        if(n > 0) {
            puts("NO");
            return 0;
        }

        puts("YES");
        for(int i = 1; i + 2 <= k; i++) {
            printf("%d ", i + level);
        }
        printf("%d %d\n", k-1+level+llast, k+level+llast+last);
    }

    return 0;
}