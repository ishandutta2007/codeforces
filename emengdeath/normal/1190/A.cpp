#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e5 + 1;
long long n, k;
int m;
long long a[N];
int main()
{
    scanf("%lld %d %lld", &n, &m, &k );
    for (int i = 1; i <= m; i ++) {
        scanf("%lld", &a[i]);
    }
    int l = 1;
    long long R = k;
    int ans = 0;
    while (l <= m) {
        ans ++;
        if (R < a[l]) {
            R += (a[l] - R) / k * k;
            if (R < a[l]) R += k;
        }
        int sum = 0;
        while (l <= m && a[l] <= R) l ++, sum ++;
        R += sum;
    }
    printf("%d\n", ans);
    return 0;
}