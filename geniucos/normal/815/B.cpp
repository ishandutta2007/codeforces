#include<bits/stdc++.h>

using namespace std;

int N, coef[200009], fac[200009], inv[200009], old[200009];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=1; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

void precCoef (int N)
{
    for (int i=1; i<=N; i++)
        coef[i] = 0;
    if (N % 4 == 0)
    {
        int M = N / 2 - 1;
        for (int i=1, j = 0; i<=N; i += 2, j ++)
        {
            int curr = comb (M, j);
            coef[i] = curr, coef[i + 1] = subtract (0, curr);
        }
    }
    else
    if (N % 4 == 1)
    {
        int M = N / 2;
        for (int i=1, j = 0; i<=N; i += 2, j ++)
            coef[i] = comb (M, j);
    }
    else
    if (N % 4 == 2)
    {
        int M = N / 2 - 1;
        for (int i=1, j = 0; i<=N; i += 2, j ++)
            coef[i] = coef[i + 1] = comb (M, j);
    }
    else
    {
        precCoef (N - 1);
        for (int i=1; i<N; i++)
            old[i] = coef[i];
        coef[1] = 1, coef[N] = mod - 1;
        for (int i=2; i<N; i++)
            if (i & 1) coef[i] = subtract (old[i], old[i - 1]);
            else coef[i] = add (old[i], old[i - 1]);
    }
}

/*void print (int N)
{
    precCoef (N);
    for (int i=1; i<=N; i++)
        if (coef[i] <= 10000) printf ("%3d ", coef[i]);
        else printf ("%3d ", coef[i] - mod);
    printf ("\n");
}

void printAll ()
{
    for (int i=1; i<=20; i++)
        print (i);
}*/

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*Prec (30);
printAll ();
return 0;*/
scanf ("%d", &N), Prec (N);
precCoef (N);
int ans = 0;
for (int i=1; i<=N; i++)
{
    int ai;
    scanf ("%d", &ai);
    adto (ans, mul (ai, coef[i]));
}
printf ("%d\n", ans);

return 0;
}