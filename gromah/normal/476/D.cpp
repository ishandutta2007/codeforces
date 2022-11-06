#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, k, Ord[N];
LL ans, Set[N][5];

inline int gcd(int x, int y)
{
    return !y ? x : gcd(y, x % y);
}

int main()
{
    scanf("%d%d", &n, &k);
    printf("%d\n", (n * 6 - 1) * k);
    for (int i = 0; i < n; i ++)
        printf("%d %d %d %d\n", (1 + i * 6) * k, (2 + i * 6) * k, (3 + i * 6) * k, (5 + i * 6) * k);
    return 0;
}