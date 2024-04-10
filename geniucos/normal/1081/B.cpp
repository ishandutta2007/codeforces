#include<bits/stdc++.h>

using namespace std;

int N, a[100009], ans[100009];
vector < int > v[100009];
/*const int mod = ;

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

int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}*/

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), a[i] = N - a[i], v[a[i]].push_back (i);
int nr = 1;
for (int sz=1; sz<=N; sz++)
    if (!v[sz].empty ())
    {
        if (v[sz].size () % sz != 0)
        {
            printf ("Impossible\n");
            return 0;
        }
        int f = sz;
        for (auto j : v[sz])
        {
            ans[j] = nr;
            if (--f == 0)
                f = sz, nr ++;
        }
    }
printf ("Possible\n");
for (int i=1; i<=N; i++)
    printf ("%d%c", ans[i], " \n"[i == N]);
return 0;
}