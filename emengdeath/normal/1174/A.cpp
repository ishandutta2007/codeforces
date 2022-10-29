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
const int N = 1e5 +1;
int a[N];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n + n ; i ++)
        scanf("%d", &a[i]);
    sort(a, a + n + n);
    long long sum = 0, sum1 = 0;
    for (int i = 0; i < n ; i ++)
        sum += a[i], sum1 += a[i +n];
    if (sum != sum1)
    {
        for (int i = 0; i < n + n  ; i ++)
            printf("%d ", a[i]);
    }else printf("-1");
    return 0;
}