#include<bits/stdc++.h>
int main(){
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);
    int *a = new int[n * k];
    for(int i = 0; i < n * k; i += 1)
        scanf("%d", a + i);
    std::sort(a, a + n * k);
    if(a[n - 1] - a[0] > l) printf("0");
    else{
        int m = std::upper_bound(a, a + n * k, a[0] + l) - a;
        long long ans = 0;
        for(int i = 0; i <= (m - 1) / k; i += 1)
            ans += a[i * k];
        for(int i = m - 1, j = n - (m - 1) / k - 1; j; i -= 1)
            if(i % k) ans += a[i], j -= 1;
            printf("%lld", ans);
    }
}