#include<bits/stdc++.h>

using namespace std;

int coef[10], put2[1000009], N, dp2[7][1000009], sg[1000009], ans[1000009], mod = 1e9 + 7;
char dig[7][1000009];
//int Konst = 3, M = 1000;
int Konst = 6, M = 1000000;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int substract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}

struct str
{
    int s, s2, n;
    str (){}
    str (int _s, int _s2, int _n): s (_s), s2 (_s2), n (_n) {}
    str (int x) {s = x, s2 = mul (x, x), n = 1;}
    int calc ()
    {
        if (n == 1) return s2;
        return mul (put2[n - 2], add (mul (s, s), s2));
    }
}dp[7][1000009];
str operator + (str a, str b) {return str (add (a.s, b.s), add (a.s2, b.s2), a.n + b.n);}
str operator - (str a, str b) {return str (substract (a.s, b.s), substract (a.s2, b.s2), a.n - b.n);}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

coef[1] = 1;
for (int i=2; i<=Konst; i++)
    coef[i] = coef[i - 1] * 10;
for (int i=0; i<M; i++)
{
    int aux = i;
    sg[i] = 0;
    for (int j=1; j<=Konst; j++)
        dig[j][i] = aux % 10, aux /= 10, sg[i] += dig[j][i];
    sg[i] &= 1;
}

scanf ("%d", &N), put2[0] = 1;
for (int i=1; i<=N; i++)
    put2[i] = add (put2[i - 1], put2[i - 1]);
for (int i=1; i<=N; i++)
{
    int val;
    scanf ("%d", &val);
    str curr = str (val);
    dp[0][val] = dp[0][val] + curr;
}
for (int i=1; i<=Konst; i++)
    for (int j=0; j<M; j++)
    {
        ///calculez dp[i][j]
        for (int k=dig[i][j]; k<10; k++)
            dp[i][j] = dp[i][j] + dp[i - 1][j + (k - dig[i][j]) * coef[i]];
    }
for (int j=0; j<=M; j++)
{
    ans[j] = dp[Konst][j].calc ();
   // if (ans[j] != 0) printf ("%d %d\n", j, ans[j]);
    //if (sg[j]) dp2[0][j] = substract (0, ans[j]);
    //else dp2[0][j] = ans[j];
}
//printf ("\n");
long long ans2 = 0;
for (int j=M - 1; j>=0; j--)
{
    int curr = ans[j];
    for (int i=1; i<=Konst; i++)
        for (int k=dig[i][j]; k<10; k++)
            dp2[i][j] = add (dp2[i][j], dp2[i - 1][j + (k - dig[i][j]) * coef[i]]);
    curr = substract (curr, dp2[Konst][j]);
    for (int i=0; i<=Konst; i++)
        dp2[i][j] = 0;
    dp2[0][j] = curr;
    for (int i=1; i<=Konst; i++)
        for (int k=dig[i][j]; k<10; k++)
            dp2[i][j] = add (dp2[i][j], dp2[i - 1][j + (k - dig[i][j]) * coef[i]]);
    //if (curr != 0) printf ("%d %d\n", j, curr);
    ans2 = ans2 ^ (1LL * curr * j);
}
printf ("%I64d\n", ans2);
return 0;
}