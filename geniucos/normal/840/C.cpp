#include<bits/stdc++.h>

using namespace std;

int nr, F[809];
const int mod = 1e9 + 7;

namespace countConsecutiveEqualLess {
    int sz, c[809][809], dp[809][809];
    int calc (int N)
    {
        c[0][0] = 1;
        for (int i=1; i<=N; i++)
        {
            c[i][0] = 1;
            for (int j=1; j<=i; j++)
            {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                if (c[i][j] >= mod) c[i][j] -= mod;
            }
        }
        dp[1][F[1] - 1] = 1, sz = F[1];
        for (int i=1; i<nr; sz += F[i + 1], i++)
            for (int j=0; j<sz; j++)
                if (dp[i][j])
                    for (int p=0; p<=j && p<=F[i + 1]; p ++)
                        for (int k=0; p + k<=F[i + 1] && p + k <= sz + 1; k ++)
                        if (k + p > 0)
                        {
                            long long val = (1LL * dp[i][j] * c[j][p]) % mod;
                            val = (1LL * val * c[sz + 1 - j][k]) % mod;
                            val = (1LL * val * c[F[i + 1] - 1][k + p - 1]) % mod;
                            dp[i + 1][j + F[i + 1] - k - 2 * p] += val;
                            if (dp[i + 1][j + F[i + 1] - k - 2 * p] >= mod) dp[i + 1][j + F[i + 1] - k - 2 * p] -= mod;
                        }
        return dp[nr][0];
    }
};

int nrP, pr[33000], cr[33000], rep[309];
map < int, int > mp[309];
bool eqq (int i, int j)
{
    for (auto it : mp[i])
        if (mp[j][it.first] % 2 != it.second % 2) return 0;
    for (auto it : mp[j])
        if (mp[i][it.first] % 2 != it.second % 2) return 0;
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int N;
scanf ("%d", &N);

for (int i=2; i * i<=32000; i++)
    if (cr[i] == 0)
        for (int j=i * i; j<=32000; j+=i)
            cr[j] = i;
for (int i=2; i<=32000; i++)
    if (cr[i] == 0)
        pr[++nrP] = i;
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    for (int j=1; j<=nrP && pr[j] * pr[j] <= x; j++)
        if (x % pr[j] == 0)
        {
            while (x % pr[j] == 0)
                x /= pr[j], mp[i][pr[j]] ++;
        }
    if (x > 1) mp[i][x] ++;
}
nr = 0;
for (int i=1; i<=N; i++)
{
    bool pe_bune = 1;
    for (int j=1; j<=nr; j++)
        if (eqq (rep[j], i))
        {
            F[j] ++, pe_bune = 0;
            break;
        }
    if (pe_bune)
        rep[++nr] = i, F[nr] = 1;
}
int ans = countConsecutiveEqualLess::calc (N);
for (int i=1; i<=nr; i++)
    for (int j=1; j<=F[i]; j++)
        ans = (1LL * ans * j) % mod;
printf ("%d\n", ans);
return 0;
}