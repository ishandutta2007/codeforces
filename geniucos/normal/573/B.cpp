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

int N, sol, a[100009], b[100009], c[100009], aux[100009];

deque < int > dq;

int mod (int x)
{
    if (x < 0) return -x;
    return x;
}

void Clear_dq ()
{
    while (!dq.empty ()) dq.pop_back ();
}

void afis ()
{
    for (int i=N; i>=1; i--)
        if (c[i] > 0) printf ("%d ", c[i]);
        else printf ("0 ");
    printf ("\n");
}

bool ok (int K)
{
    if (K == 1)
    {
        for (int i=1; i<=N; i++)
            if (min (min (a[i] - 1, a[i-1]), a[i+1]) > 0)
                return 0;
        return 1;
    }
    for (int i=1; i<=N; i++)
        b[i] = a[i] - i, c[i] = a[i] - K;
    int L = K + 1;
    for (int i=1; i<=N; i++)
    {
        while (!dq.empty () && b[dq.back ()] >= b[i]) dq.pop_back ();
        dq.push_back (i);
        if (dq.front () <= i - L) dq.pop_front ();
        if (i >= L)
            c[i] = min (c[i], i - K + b[dq.front ()]);
        else c[i] = 0;
    }
    Clear_dq ();

    reverse (c + 1, c + N + 1);
    reverse (a + 1, a + N + 1);
    for (int i=1; i<=N; i++)
        b[i] = a[i] - i;
    for (int i=1; i<=N; i++)
    {
        while (!dq.empty () && b[dq.back ()] >= b[i]) dq.pop_back ();
        dq.push_back (i);
        if (dq.front () <= i - L) dq.pop_front ();
        if (i >= L) c[i] = min (c[i], i - K + b[dq.front ()]);
        else c[i] = 0;
    }
    reverse (a + 1, a + N + 1);
    Clear_dq ();
    for (int i=1; i<=N; i++)
        if (c[i] > 0)
            return 0;
    return 1;
}

void brut ()
{
    for (int i=1; i<=N; i++)
        aux[i] = a[i];
    bool ok = 1;
    while (ok)
    {
        ok = 0;
        for (int i=1; i<=N; i++)
        {
            if (a[i] > 0) ok = 1;
            b[i] = min (min (a[i] - 1, a[i-1]), a[i+1]);
        }
        if (ok == 0) break;
        for (int i=1; i<=N; i++)
            if (b[i] > 0) a[i] = b[i];
            else a[i] = 0;
        sol ++;
        for (int i=1; i<=N; i++)
            printf ("%d ", a[i]);
        printf ("\n");
    }
    printf ("%d\n", sol);
    for (int i=1; i<=N; i++)
        a[i] = aux[i];
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=2; i<=N + 1; i++)
    scanf ("%d", &a[i]);
N += 2;
//ok (2);
//afis ();
//return 0;
//brut ();
int p, u, mij, ras;
p = 1;
u = min (1000000000, N);
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
/*for (int i=1; i<=ras; i++)
{
    ok (i);
    afis ();
}*/
printf ("%d\n", ras);

return 0;
}