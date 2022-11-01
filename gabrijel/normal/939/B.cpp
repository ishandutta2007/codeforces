#include <bits/stdc++.h>
using namespace std;

long long int n;
int k;

int main()
{
    long long int x;
    long long int koliko = 1e18 + 1;
    long long int rj1, rj2;
    scanf("%lld%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &x);
        if (n % x < koliko)
        {
            koliko = n % x;
            rj1 = i + 1;
            rj2 = n / x;
        }
    }
    printf("%lld %lld", rj1, rj2);
    return 0;
}