#include <iostream>
#include <stdio.h>
using namespace std;

int c, x, k, n;
long long ans = 0;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (x + c >= k)
        {
            ans += (x + c) / k;
            c = (x + c) % k;
        }
        else if (c > 0)
        {
            ans++;
            c = 0;
        }
        else c = x;
    }
    if (c > 0) ans++;
    printf("%I64d", ans);
	return 0;
}