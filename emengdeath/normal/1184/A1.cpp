#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
long long n;
long long ans;
void update(long long x) {
    long long y = n / x;
    if (y - x - 1<= 0) return;
    if ((y - x - 1) % 2 != 0) return ;
    if (ans == -1 || ans > x)
        ans = x;
}
int main() {
    scanf("%lld", &n);
    n --;
    ans = -1;
    for (int i = 1; (long long)i * i <= n ; i ++)
        if (n % i == 0) update(i), update(n / i );
    if (ans == -1) printf("NO\n");
    else
    printf("%lld %lld\n", ans, (n / ans - ans - 1) / 2);
    return 0;
}