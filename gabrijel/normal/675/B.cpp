#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d, mini, maxi, poc, kolko;
long long int rj = 0;

int main()
{
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    mini = min(min(a + c, c + d), min(b + d, b + a));
    maxi = max(max(a + c, c + d), max(b + d, b + a));
    for (int i = 1; i <= n; i++)
    {
        poc = maxi + i + 1;
        kolko = poc - mini - i;
        if (kolko < 1 || kolko > n) continue;
        else rj += n - kolko + 1;
    }
    cout << rj;
    return 0;
}