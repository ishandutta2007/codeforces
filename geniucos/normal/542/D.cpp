#include<bits/stdc++.h>

using namespace std;

int nr, nr2, nr3, nr4, st[7000], dr[7000], pr[200009];
long long A, div2[7000];
bool cr[1000009];
pair < long long, long long > Div[7000];
map < long long, int > mp;
map < int, int > prec_dp[7000];

long long prime (long long val)
{
    val --;
    if (val <= 1) return -1;
    for (int i=1; i<=nr3 && 1LL * pr[i] * pr[i] <= val; i++)
        if (val % pr[i] == 0)
        {
            while (val % pr[i] == 0) val /= pr[i];
            if (val == 1) return pr[i];
            return -1;
        }
    return val;
}

int dp (int i, int j)
{
    if (div2[i] == 1) return 1;
    if (j == 0) return 0;
    if (prec_dp[j].count (i)) return prec_dp[j][i];
    int &val = prec_dp[j][i];
    val = dp (i, j - 1);
    for (int k=st[j]; k<=dr[j]; k++)
        if (div2[i] % Div[k].second == 0 && mp.count (div2[i] / Div[k].second))
        {
            int curr = dp (mp[div2[i] / Div[k].second], j - 1);
            val += curr;
        }
    //if (val != 0) printf ("(%d, %d) -> %d\n", i, j, val);
    return val;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d", &A);
long long aux = A;
for (int i=1; 1LL * i * i <= aux; i++)
    if (A % i == 0) div2[++nr2] = i;
for (int i=nr2; i>=1; i--)
    if (A / div2[i] != div2[i]) div2[++nr2] = A / div2[i];
for (int i=2; 1LL * i * i <= A; i++)
    if (cr[i] == 0)
    {
        pr[++nr3] = i;
        for (long long j=1LL * i * i; j <= A / j; j+=i)
            cr[j] = 1;
    }
for (int i=1; i<=nr2; i++)
{
    long long curr = prime (div2[i]);
    if (curr != -1) Div[++nr] = make_pair (curr, div2[i]);
}
sort (Div + 1, Div + nr + 1);
//for (int i=1; i<=nr; i++)
  //  printf ("%I64d %I64d\n", Div[i].second, Div[i].first);
for (int i=1; i<=nr2; i++)
    mp[div2[i]] = i;
for (int i=1; i<=nr; i++)
{
    int j;
    for (j=i; j<=nr; j++)
        if (Div[j].first != Div[i].first) break;
    j --, st[++nr4] = i, dr[nr4] = j;
    i = j;
}
printf ("%d\n", dp (mp[A], nr4));
return 0;
}