#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e6  + 1;
int n, k;
int phi[N], a[N], d[N];
int main() {
    scanf("%d %d", &n, &k);
    if (k == 1) {
        printf("3\n");
        return 0;
    }
    for (int i = 2; i <= n ;  i ++) {
        if (!a[i])
            d[a[i] =  ++d[0]] = i, phi[i] = i -1 ;
        for (int j = 1 ; j <= a[i] && 1ll * i * d[j] <= n; j ++)
        {
            a[d[j] * i ] = j;
            phi[d[j] * i] = phi[i] * (d[j] - (j != a[i]));
        }
    }
    sort(phi + 3, phi + n + 1);
    long long ans = 0;
    for (int i = 0; i < k ; i ++)
        ans += phi[i + 3];
    printf("%lld\n", ans + 2);
    return 0;
}