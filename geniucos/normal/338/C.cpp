#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int maxn, nr, N, best, n_primes, pr[1000009], t[20], ap[20];
bool cr[1000009];
long long a[20];

map < long long , int > mp;

struct number
{
    int ex[200];

    number ()
    {
        memset (ex, 0, sizeof (ex));
    }

    number (long long val)
    {
        memset (ex, 0, sizeof (ex));
        for (int i=1; 1LL * pr[i] * pr[i] <= val && i <= nr; i ++)
            if (val % pr[i] == 0)
            {
                int E = 0;
                while (val % pr[i] == 0)
                    val /= pr[i], E ++;

                if (mp[pr[i]] == 0)
                    mp[pr[i]] = ++n_primes;
                ex[mp[pr[i]]] = E;
            }

        if (val > 1)
        {
            if (mp[val] == 0)
                mp[val] = ++n_primes;
            ex[mp[val]] ++;
        }
    }
}A[20], B[20];

number diff (number a, number b)
{
    for (int i=1; i<=n_primes; i++)
        a.ex[i] -= b.ex[i];
    return a;
}

int ok (number a)
{
    int tot = 0;
    for (int i=1; i<=n_primes; i++)
    {
        if (a.ex[i] < 0)
            return -1;
        tot += a.ex[i];
    }
    return tot;
}

void back (int pos)
{
    if (pos == N + 1)
    {
        int nr_noduri = 0;

        for (int i=1; i<=N; i++)
            B[i] = A[i], ap[i] = 0;

        for (int i=1; i<=N; i++)
        {
            if (t[i]) B[t[i]] = diff (B[t[i]], B[i]), ap[t[i]] = 1;
            else nr_noduri ++;
        }

        if (nr_noduri >= 2)
            nr_noduri = 1;
        else
            nr_noduri = 0;

        for (int i=1; i<=N; i++)
        {
            int curr = ok (B[i]);
            if (curr == 1 && ap[i] == 0)
                curr = 0;
            if (curr == -1)
                return ;

            nr_noduri += curr + 1;
        }

        if (nr_noduri < best)
            best = nr_noduri;

        return ;
    }

    for (int i=0; i<pos; i++)
        if (a[i] % a[pos] == 0)
            t[pos] = i, back (pos + 1);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

maxn = 1000000;

for (int i=2; i*i <= maxn; i++)
    if (cr[i] == 0)
    {
        for (int j=i*i; j<=maxn; j+=i)
            cr[j] = 1;
    }

for (int i=2; i<=maxn; i++)
    if (cr[i] == 0)
        pr[++nr] = i;

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%I64d", &a[i]);

sort (a + 1, a + N + 1);
reverse (a + 1, a + N + 1);

for (int i=1; i<=N; i++)
    A[i] = B[i] = number (a[i]);

best = 100000;
back (1);
printf ("%d\n", best);

return 0;
}