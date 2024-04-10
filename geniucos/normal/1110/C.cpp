#include<bits/stdc++.h>

using namespace std;

int N, M, K, x[100009], y[100009];

int gcd (int a, int b)
{
    int r;
    while (b)
        r = a % b, a = b, b = r;
    return a;
}

int brute (int a)
{
    int ans = 0;
    for (int b=1; b<a; b++)
    {
        int curr = gcd (a ^ b, a & b);
        if (curr > ans)
            ans = curr;
    }
    return ans;
}

int f (int a)
{
    int k = 0;
    while ((1 << k) <= a)
        k ++;
    if (a == (1 << k) - 1)
    {
        for (int d = 2; 1LL * d * d <= a; d ++)
            if (a % d == 0)
                return a / d;
        return 1;///is prime
    }
    return (1 << k) - 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*for (int i=2; i<=10000; i++)
    if (f (i) != brute (i))
    {
        printf ("wa %d\n", i);
        return 0;
    }*/

int tests;
scanf ("%d", &tests);
while (tests --)
{
    int a;
    scanf ("%d", &a);
    printf ("%d\n", f (a));
//    assert (f (a) == brute (a));
}
return 0;
}