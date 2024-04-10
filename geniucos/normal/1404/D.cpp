#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, x[maxN], y[maxN], ans[maxN], p[maxN], ap[maxN], taken[maxN];
vector < int > v[maxN];

void giveSolution ()
{
    int mod2 = 0;
    for (int i=1; i<=N; i++)
        mod2 ^= ans[i];
    if (mod2 & 1)
        for (int i=1; i<=N; i++)
            ans[i] = x[i] ^ y[i] ^ ans[i];
    for (int i=1; i<=N; i++)
        printf ("%d%c", ans[i], " \n"[i == N]);
    fflush (stdout);
}

void takeResidum (int r)
{
    ap[r] = 1;
    for (auto label : v[r])
        if (!taken[label])
        {
            if (x[label] % N != r)
                swap (x[label], y[label]);
            ans[p[x[label]]] = x[label]; ///took it
            taken[label] = 1;
            takeResidum (y[label] % N);
        }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N % 2 == 0)
{
    printf ("First\n");
    for (int i=1; i<=2 * N; i++)
        printf ("%d%c", (i > N ? i - N : i), " \n"[i == 2 * N]);
    fflush (stdout);
    return 0;
}
printf ("Second\n");
fflush (stdout);
for (int i=1; i<=2 * N; i++)
{
    int pos;
    scanf ("%d", &pos), p[i] = pos;
    v[i % N].push_back (pos);
    if (x[pos] == 0) x[pos] = i;
    else y[pos] = i;
}
for (int i=0; i<N; i++)
    if (ap[i] == 0)
        takeResidum (i);
giveSolution ();
return 0;
}