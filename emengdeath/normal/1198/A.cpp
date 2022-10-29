#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e6;
int n, k;
int a[N], sum[N];
int main(){
    scanf("%d %d", &n, &k);
    k = k * 8 / n;
    if (k >= 20) k = n;
    else
        k = min(1 << k, n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int tot = 1; sum[1] = 1;
    for (int i = 2;i  <= n ; i ++) {
        if (a[i] != a[tot])
            a[++tot] = a[i];
        sum[tot] ++;
    }
    for (int i = 2; i <= tot; i ++)
        sum[i] += sum[i - 1];
    int ans = n;
    for (int i = 1; i <= tot; i ++){
        int r = min(i + k - 1, tot);
        ans = min(ans, sum[i - 1] + sum[tot] - sum[r]);
    }
    printf("%d\n", ans);
    return 0;
}