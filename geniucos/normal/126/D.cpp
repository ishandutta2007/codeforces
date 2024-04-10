#include<bits/stdc++.h>

using namespace std;

int T, nr, Nr, v[100];
long long cu, fara, aux, fib[100];

int ways (int i, int j) {return (j - i) / 2;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &T);
fib[0] = fib[1] = 1;
for (int i=2; fib[i - 1] + fib[i - 2] <= 1e18; i++)
    fib[i] = fib[i - 1] + fib[i - 2], Nr = i;
while (T --)
{
    scanf ("%I64d", &aux), nr = 0;
    for (int i=Nr; i>=1; i--)
        if (aux >= fib[i]) aux -= fib[i], v[++nr] = i;
    reverse (v + 1, v + nr + 1), cu = 1, fara = 0;
    for (int i=1; i<=nr; i++)
    {
        long long old_cu = cu, old_fara = fara;
        cu = old_cu + old_fara;
        fara = 1LL * old_cu * ways (v[i - 1] + 1, v[i]) + 1LL * old_fara * ways (v[i - 1], v[i]);
    }
    printf ("%I64d\n", cu + fara);
}

return 0;
}