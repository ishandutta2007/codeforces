#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5

int n, F[N];
LL ans, Sum[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", F + i);
    sort(F + 1, F + n + 1);
    if (n == 1)
        ans = F[1];
    else
    {
        for (int i = 1; i < n; i ++)
            ans += (LL) (i + 1) * F[i];
        ans += (LL) n * F[n];
    }
    cout << ans << endl;
    return 0;
}