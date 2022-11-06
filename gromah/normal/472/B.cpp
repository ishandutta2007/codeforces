#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 2000 + 5

int n, k, ans, A[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++)
        scanf("%d", A + i);
    sort(A + 1, A + n + 1);
    for (int i = n; i > 0; i -= k)
        ans += (A[i] - 1) * 2;
    printf("%d\n", ans);
    return 0;
}