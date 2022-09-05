#include<bits/stdc++.h>

using namespace std;

int N, nr, nr2, E[30], cnt[2000009];
long long ans, P[30], a[1000009], Div[2000009];

long long gcd (long long a, long long b)
{
    long long r;
    while (b) r = a % b, a = b, b = r;
    return a;
}

int get_id (long long val)
{
    int p = 1, u = nr2;
    while (p <= u)
    {
        int mij = (p + u) >> 1;
        if (Div[mij] == val) return mij;
        if (Div[mij] < val) p = mij + 1;
        else u = mij - 1;
    }
}

void back (int pos, long long val)
{
    if (pos == nr + 1)
    {
        Div[++nr2] = val;
        return ;
    }
    back (pos + 1, val);
    for (int i=1; i<=E[pos]; i++)
        val = 1LL * val * P[pos], back (pos + 1, val);
}

void Solve (long long val)
{
    long long aux = val;
    nr = nr2 = 0;
    for (int i=2; 1LL * i * i <= aux; i++)
        if (aux % i == 0)
        {
            P[++nr] = i, E[nr] = 0;
            while (aux % i == 0) aux /= i, E[nr] ++;
        }
    if (aux > 1) P[++nr] = aux, E[nr] = 1;
    back (1, 1);
    sort (Div + 1, Div + nr2 + 1);
    for (int i=1; i<=nr2; i++)
        cnt[i] = 0;
    for (int i=1; i<=N; i++)
    {
        long long curr = gcd (val, a[i]);
        cnt[get_id (curr)] ++;
    }
    for (int i=1; i<=nr; i++)
        for (int j=1; j<=nr2; j++)
        {
            long long curr = Div[j];
            while ((val / curr) % P[i] == 0) curr = 1LL * curr * P[i], cnt[j] += cnt[get_id (curr)];
        }
    for (int i=nr2; i>=1; i--)
        if (cnt[i] >= (N + 1) / 2)
        {
            if (Div[i] > ans) ans = Div[i];
            break;
        }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*double p = 1.0 - 1.0 / (1 << 5), aux = 1;
int E = 13;
while (E --) aux = aux * p;
printf ("%.10f\n", p);
return 0;*/

scanf ("%d", &N), srand (time (0));
for (int i=1; i<=N; i++)
    scanf ("%I64d", &a[i]);
random_shuffle (a + 1, a + N + 1);
int steps = 9;
for (int i=1; i<=N && i<=steps; i++)
    Solve (a[i]);
printf ("%I64d\n", ans);
return 0;
}