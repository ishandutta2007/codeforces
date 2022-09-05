#include<bits/stdc++.h>

using namespace std;

int N, K, y[1000009];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}
void multo (int &x, int y) {x = (1LL * x * y) % mod;}
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
void divto (int &x, int y) {multo (x, power (y, mod - 2));}

int main ()
{
scanf ("%d %d", &N, &K);
y[0] = 0;
for (int i=1; i<=K + 2; i++)
    y[i] = add (y[i - 1], power (i, K));
if (N <= K + 2)
{
    printf ("%d\n", y[N]);
    return 0;
}
int curr = 1;
for (int i=2; i<=K + 2; i++)
    multo (curr, N - i), divto (curr, 1 - i + mod);
int ans = mul (curr, y[1]);
for (int i=2; i<=K + 2; i++)
{
    multo (curr, N - (i - 1));
    divto (curr, N - i);
    multo (curr, (i - 1) - (K + 2) + mod);
    divto (curr, i - 1);
    adto (ans, mul (curr, y[i]));
}
printf ("%d\n", ans);
return 0;
}