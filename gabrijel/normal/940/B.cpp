#include <bits/stdc++.h>
using namespace std;

int n, k, a, b;
long long int rj = 0;

int main()
{
    scanf("%d%d%d%d", &n, &k, &a, &b);
    if (k == 1) k = 2 * 1e9 + 100;
    int x = n;
    while (x > 1)
    {
        if (x % k != 0)
        {
            rj += (long long) a * (x % k);
            x -= (x % k);
        }
        else
        {
            if (b < (long long) a * (x - x / k))
            {
                rj += b;
                x /= k;
            }
            else
            {
                rj += (long long) a * x;
                x -= x;
            }
        }
    }
    if (x == 0) cout << rj - a;
    else cout << rj;
    return 0;
}