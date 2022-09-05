#include<bits/stdc++.h>

using namespace std;

int N, M;
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

/*void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}*/

int g1 (int n) {return (1LL * n * (n + 1) / 2) % mod;}
int g2 (int n) {return (1LL * n * (n + 1) / 2 * (2 * n + 1) / 3) % mod;}

int v0[1000009], v1[1000009], v2[1000009], phi[1000009];
void precV (int lim)
{
    for (int i=1; i<=lim; i++)
        phi[i] = i;
    for (int i=2; i<=lim; i++)
        if (phi[i] == i)
            for (int j=i; j<=lim; j+=i)
                phi[j] /= i, phi[j] *= i - 1;
    for (int i=1; i<=lim; i++)
    {
        v0[i] = subtract (mul (i, g1 (i)), g2 (i));///sum of x * y with x + y = i equal to sum of j(i-j)
        v0[i] = subtract (v0[i], mul (i, i - 1)); ///-x - y, i - 1 times
    }
    for (int i=1; i<=lim; i++)
        for (int j=i + i; j<=lim; j+=i)
            adto (v0[j], i * phi[j / i]); /// there are phi[j / i] values of 1<=k<j, gcd (j, k)=i
    for (int i=1; i<=lim; i++)
        v0[i] = add (v0[i], v0[i]);
    for (int i=1; i<=lim; i++)
    {
        int curr = mul (i, mul (i, i));///sum of (x - y) ^ 2 = sum of (i - 2j) ^ 2 with 1<=j<=i
        curr = subtract (curr, mul (4 * i, g1 (i)));
        adto (curr, mul (4, g2 (i)));
        adto (v0[i], curr);
    }
/*    for (int s = 1; s <= lim; s ++)
        for (int x=1; x<=s; x++)
        {
            int y = s - x;
            int i2 = add (subtract (mul (x, y), x + y), __gcd (x, y));
            if (y == 0) i2 = 0;
            int i4 = add (i2, i2);
            adto (v0[s], add (i4, mul (x - y, x - y)));
        }*/
    for (int i=1; i<=lim; i++)
    {
        v1[i] = add (v1[i - 1], mul (i - 1, v0[i]));
        v2[i] = add (v2[i - 1], mul (mul (i - 1, i - 1), v0[i]));
        adto (v0[i], v0[i - 1]);
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

precV (1000000);

int Tests;
scanf ("%d", &Tests);
while (Tests --)
{
    scanf ("%d %d", &N, &M);
/*    int ans = 0;
    for (int x=0; x<=N; x++)
        for (int y=1; x + y<=M && x + y<=N; y++)
        {
            int ways = (N - x - y + 1) * (M - y - x + 1);
            int i2 = x * y - x - y + __gcd (x, y);
            if (x == 0 || y == 0) i2 = 0;
            int i4 = i2 + i2, squares = i4 + (x - y) * (x - y);
            ans += ways * squares;
        }*/
    int K = min (N, M), ans = mul (mul (N, M), v0[K]);
    ans = subtract (ans, mul (N + M, v1[K]));
    adto (ans, v2[K]);
    printf ("%d\n", ans);
}

return 0;
}