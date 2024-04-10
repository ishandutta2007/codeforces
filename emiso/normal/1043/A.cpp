#include <bits/stdc++.h>

using namespace std;

int a[110], sum1, sum2, ans, n, k;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        k = max(k, a[i]);
    }
    for(int i = 0; i < n; i++) {
        sum1 += (k - a[i]);
        sum2 += a[i];
    }
    while(sum1 <= sum2) {
        ans++;
        sum1 += n;
    }
    printf("%d\n", ans + k);
    return 0;
}