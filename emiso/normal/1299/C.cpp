#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], sum[MN], where[MN];

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }

    where[n] = n;
    for(int i = n-1; i >= 1; i--) {
        where[i] = i;
        while(where[i] < n) {
            double m1 = 1.0 * (sum[where[i]] - sum[i-1]) / (where[i] - i + 1);
            double m2 = 1.0 * (sum[where[where[i]+1]] - sum[i-1]) / (where[where[i]+1] - i + 1);

            if(m2 < m1) where[i] = where[where[i]+1];
            else break;
        }
    }

    for(int i = 1; i <= n; i = where[i] + 1) {
        double m = 1.0 * (sum[where[i]] - sum[i-1]) / (where[i] - i + 1);
        for(int l = i; l <= where[i]; l++)
            printf("%.9f\n", m);
    }
    return 0;
}