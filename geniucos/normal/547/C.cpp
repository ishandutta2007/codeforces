#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int N, M, dp[500009], cr[500009], pr[500009], nu[500009], A[500009], coef[500009], ap[500009], mul[500009];

vector < int > v[500009];

int f (int p)
{
    if (p == 1)
        return 1;
    if (cr[p] == 0)
        return -1;
    if (nu[p])
        return 0;
    if (pr[p] & 1)
        return -1;
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=1; i<=500000; i++)
    for (int j=i; j<=500000; j+=i)
        v[j].push_back (i);

for (int i=2; i<=500000; i++)
    if (cr[i] == 0)
    {
        for (int j=i+i; j<=500000; j+=i)
            cr[j] = 1, pr[j] ++;
        if (1LL * i * i <= 500000)
        {
            for (int j = i * i; j<=500000; j += i * i)
                nu[j] = 1;
        }
    }

for (int i=1; i<=500000; i++)
    coef[i] = f(i);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &A[i]);

long long Tot = 0;
while (M)
{
    M --;
    int ind, pl;
    scanf ("%d", &ind);
    if (ap[ind] == 0)
        pl = 1, ap[ind] = 1;
    else
        pl = -1, ap[ind] = 0;
    for (vector < int > :: iterator it = v[A[ind]].begin (); it != v[A[ind]].end (); it ++)
    {
        int now = mul[*it];
        if (pl == -1)
            now = 1 - mul[*it];
        Tot += 1LL * now * coef[*it];
        mul[*it] += pl;
    }
    printf ("%I64d\n", Tot);
}

return 0;
}