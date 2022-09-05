#include<bits/stdc++.h>

using namespace std;

int N, dp[200009][3], t[200009], p2[200009], coef[200009];
const int mod = 998244353;
vector < int > v[200009];

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

void dfs (int nod)
{
    if (v[nod].empty ())
    {
        dp[nod][1] = 1;
        dp[nod][0] = 0;
        return ;
    }
    int curr = 1;
    for (auto it : v[nod])
    {
        coef[it] = curr;
        dfs (it);
        curr = mul (curr, add (dp[it][0], dp[it][1]));
    }
    dp[nod][0] = curr;
    curr = 1;
    reverse (v[nod].begin (), v[nod].end ());
    for (auto it : v[nod])
    {
        coef[it] = mul (coef[it], curr);
        adto (dp[nod][2], mul (add (dp[it][2], dp[it][1]), coef[it]));
        curr = mul (curr, add (dp[it][0], dp[it][1]));
    }
    int allProd = 1, forEmpty = 1;
    curr = 1;
    for (auto it : v[nod])
    {
        coef[it] = curr;
        curr = mul (curr, add (dp[it][0], dp[it][1]));
        allProd = mul (allProd, ((long long) 2LL * dp[it][1] + dp[it][0] + dp[it][2]) % mod);
        forEmpty = mul (forEmpty, add (dp[it][0], dp[it][1]));
    }
    dp[nod][1] = subtract (allProd, forEmpty);
    reverse (v[nod].begin (), v[nod].end ());
    curr = 1;
    for (auto it : v[nod])
    {
        coef[it] = mul (coef[it], curr);
        curr = mul (curr, add (dp[it][0], dp[it][1]));
        dp[nod][1] = subtract (dp[nod][1], mul (add (dp[it][1], dp[it][2]), coef[it]));
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=2; i<=N; i++)
    scanf ("%d", &t[i]), v[t[i]].push_back (i);
p2[0] = 1;
for (int i=1; i<=N; i++)
    p2[i] = add (p2[i - 1], p2[i - 1]);
dfs (1);
printf ("%d\n", add (dp[1][0], dp[1][1]));
return 0;
}