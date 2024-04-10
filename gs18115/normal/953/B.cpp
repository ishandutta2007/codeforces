#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int Gcd (long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return Gcd (b, a%b);
    }
}

long long n, i, g, sum, p2, p[123456];

int main()
{
    scanf ("%lld", &n);
    scanf ("%lld", &p[0]);
    g = 0;
    for (i = 1; i < n; i ++)
    {
        scanf ("%lld", &p[i]);
        if (p[i] >= p[0])
        {
            p2 = p[i] - p[0];
        }
        else
        {
            p2 = p[0] - p[i];
        }
        g = Gcd(g, p2);
    }
    sort (p, p + n);
    for (i = 0; i < n - 1; i ++)
    {
        sum += (p[i + 1] - p[i]) / g - 1;
    }
    printf ("%lld", sum);
    return 0;
}