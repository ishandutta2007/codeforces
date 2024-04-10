#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>

using namespace std;

int lg, N, aib[400009], sol[200009], A[200009], a[200009], b[200009];

void U (int poz)
{
    while (poz <= N)
    {
        aib[poz] ++;
        poz += poz - (poz & (poz - 1));
    }
}

int Q (int poz)
{
    int s = 0;
    while (poz)
    {
        s += aib[poz];
        poz &= poz - 1;
    }
    return s;
}

void Clear ()
{
    for (int i=1; i<=N; i++)
        aib[i] = 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    a[i] ++;
}

for (int i=1; i<=N; i++)
{
    scanf ("%d", &b[i]);
    b[i] ++;
}

for (int i=1; i<=N; i ++)
{
    A[N-i] += a[i] - Q (a[i]) - 1;
    U (a[i]);
}

Clear();

for (int i=1; i<=N; i ++)
{
    A[N-i] += b[i] - Q (b[i]) - 1;
    U (b[i]);
}

for (int i=0; i<N; i++)
    if (A[i] >= i+1)
    {
        int cat = A[i] / (i+1);
        A[i] %= (i+1);
        A[i+1] += cat;
    }

for (int i=0; (1<<i) <= N; i++)
    lg = i;

Clear();
for (int i=1; i<=N; i++)
{
    int v = A[N-i];
    v ++;

    int ras = 0, act = 0;
    /*p = 1;
    u = N;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        int P = mij - Q(mij);
        if (P >= v)
        {
            ras = mij;
            u = mij - 1;
        }
        else p = mij + 1;
    }*/
    for (int j=lg; j>=0; j--)
        if ((1<<j) - aib[(1<<j) + ras] + act < v)
        {
            act += (1<<j) - aib[(1<<j) + ras];
            ras|=1<<j;
        }

    ras ++;
    sol[i] = ras;
    U (ras);
}

for (int i=1; i<=N; i++)
    printf ("%d ", sol[i] - 1);
printf ("\n");

return 0;
}