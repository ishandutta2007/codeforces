#include <iostream>
#include <fstream>
using namespace std;

long long i, j, n, a[123456], dp[123456], sum;

int main()
{
    scanf ("%I64d", &n);
    i = 1;
    j = 0;
    dp[0] = 0;
    while (i < n)
    {
        j = j + 1;
        dp[j] = dp[j - 1] * 2 + i;
        i = i * 2;
    }
    while (i > 1)
    {
        i = i / 2;
        j = j - 1;
        if ((n - 1) & i) sum = sum + i + dp[j];
        n = n - i;
    }
    printf ("%I64d", sum);
    return 0;
}