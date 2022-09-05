#include<bits/stdc++.h>

using namespace std;

int N, vol[109], pt[109], ans[109], c[109][109], old[109][109], dp[109][109][109];
const int mod = 1e9 + 7;
vector < int > v[109], fii[109];

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

void dfs (int nod, int tata)
{
    vol[nod] = 1;
    for (auto it : v[nod])
        if (it != tata)
            fii[nod].push_back (it), dfs (it, nod), vol[nod] += vol[it];
}

void solve (int nod)
{
    int sz = 1;
    dp[nod][1][0] = 1;
    for (auto it : fii[nod])
    {
        solve (it);
        for (int j=1; j<=sz; j++)
            for (int k=0; k<sz; k++)
                old[j][k] = dp[nod][j][k], dp[nod][j][k] = 0;
        for (int j1=1; j1<=sz; j1++)
            for (int k1=0; k1<sz; k1++)
                if (old[j1][k1] != 0)
                    for (int j2=1; j2<=vol[it]; j2++)
                        for (int k2=0; k2<vol[it]; k2++)
                            if (dp[it][j2][k2] != 0)
                            {
                                int curr = mul (old[j1][k1], dp[it][j2][k2]);
                                adto (dp[nod][j1 + j2][k1 + k2], curr);
                                adto (dp[nod][j1][k1 + k2 + 1], mul (curr, j2));
                            }
        sz += vol[it];
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*printf ("100\n");
for (int i=2; i<=100; i++)
    printf ("1 %d\n", i);
return 0;*/

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
dfs (1, -1);
solve (1);
pt[0] = 1;
for (int i=1; i<=N; i++)
    pt[i] = mul (pt[i - 1], N);
for (int j=1; j<=N; j++)
    for (int k=0; k<N; k++)
        adto (ans[N - 1 - k], mul (dp[1][j][k], j));
for (int k=0; k<N; k++)
    if (N - k >= 2)
        ans[k] = mul (ans[k], pt[N - k - 2]);
    else
        ans[k] = 1;
c[0][0] = 1;
for (int i=1; i<=N; i++)
{
    c[i][0] = 1;
    for (int j=1; j<=i; j++)
        c[i][j] = add (c[i - 1][j - 1], c[i - 1][j]);
}
for (int i=N - 1; i>=0; i--)
    for (int j=i + 1; j<N; j++)
        ans[i] = subtract (ans[i], mul (ans[j], c[j][i]));
for (int i=0; i<N; i++)
    printf ("%d ", ans[i]);
printf ("\n");
return 0;
}