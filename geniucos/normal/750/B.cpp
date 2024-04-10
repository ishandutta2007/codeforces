#include<bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7, N, D;

int mul (int x, int y) {return 1LL * x * y % mod;}
int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

/*int comb (int N, int K)
{
    if (K > N || N < 0) return 0;
    int ans = mul (fac[N], invf[N - K]);
    ans = mul (ans, invf[K]);
    return ans;
}*/

void Ans ()
{
    printf ("NO\n");
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N), D = 20000;
int val = 0;
for (int i=1; i<=N; i++)
{
    char sir[30];
    int x;
    scanf ("%d %s\n", &x, sir);
    if (sir[0] == 'E' || sir[0] == 'W')
    {
        if (val == 0 || val == D) Ans ();
        continue;
    }
    if (sir[0] == 'N')
    {
        val -= x;
        if (val < 0) Ans ();
    }
    else
    {
        val += x;
        if (val > D) Ans ();
    }

}
if (val != 0) Ans ();
printf ("YES\n");
return 0;
}