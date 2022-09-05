#include<bits/stdc++.h>

using namespace std;

int phi, nr, N, M, type[200009], code[200009], val[10009], how[10009], dp[10009], cnt[10009];
bool ap[200009];
vector < int > ans, v[209];

int pow (int a, int b, int mod)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = 1LL * p * a % mod;
        a = 1LL * a * a % mod;
    }
    return p;
}

int gcd (int a, int b)
{
    int r;
    while (b)
        r = a % b, a = b, b = r;
    return a;
}

int Move (int x, int y)
{
    int val = type[y] / type[x];
    x /= type[x], y /= type[y];
    return (1LL * val * y * pow (x, phi - 1, M)) % M;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M), phi = M;
if (M == 1)
{
    printf ("1\n0\n");
    return 0;
}
int aux = M;
for (int i=2; i<=aux; i++)
    if (aux % i == 0)
    {
        phi /= i, phi = phi * (i - 1);
        while (aux % i == 0) aux /= i;
    }
for (int i=0; i<M; i++)
    type[i] = gcd (i, M), code[type[i]] = 1;
for (int i=1; i<=M; i++)
    if (code[i] != 0)
        code[i] = ++nr, val[nr] = i;
for (int i=0; i<M; i++)
    cnt[code[type[i]]] ++;
for (int i=1; i<=N; i++)
{
    int bi;
    scanf ("%d", &bi);
    int t = type[bi];
    cnt[code[t]] --, ap[bi] = 1;
}
for (int i=0; i<M; i++)
    if (ap[i] == 0)
        v[code[type[i]]].push_back (i);
int maxi = 0, bg = -1;
for (int i=1; i<=nr; i++)
{
    for (int j=1; j<i; j++)
        if (val[i] % val[j] == 0 && dp[j] > dp[i])
            dp[i] = dp[j], how[i] = j;
    dp[i] += cnt[i];
    if (dp[i] > maxi)
        maxi = dp[i], bg = i;
}
printf ("%d\n", maxi);
int i = bg;
while (i)
{
    //printf ("%d\n", i);
    for (auto it = v[i].begin (); it != v[i].end (); it ++)
        ans.push_back (*it);
    i = how[i];
}
reverse (ans.begin (), ans.end ());
vector < int > chk;
int curr = 1, currP = 1;
for (auto it = ans.begin (); it != ans.end (); it ++)
{
    int val = Move (curr, *it);
    printf ("%d ", val), curr = *it;
    currP = (1LL * currP * val) % M, chk.push_back (currP);
}
printf ("\n");
//for (auto it = chk.begin (), it2 = ans.begin (); it != chk.end (); it ++, it2 ++)
  //  printf ("%d %d\n", *it, *it2);
return 0;
}