#include<cstdio>
#include<cstring>

using namespace std;

int nr, sol, N, M, K, a[1009][1009], b[1009], l[1009];
char sir[2009][1009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d\n", &N, &M, &K);
for (int i=1; i<2*N; i++)
{
    gets (sir[i] + 1);
    l[i] = strlen (sir[i] + 1);
    sol += l[i];
    for (int j=1; j<=l[i]; j++)
        if (sir[i][j] == 'N')
            nr ++;
}

if ((double) (sol - nr) / sol >= (double) 3 / 4 - 0.001 && K == 1)
{
    printf ("YES\n");
    for (int i=1; i<=N; i++, printf("\n"))
        for (int j=1; j<=M; j++)
            printf ("1 ");
    return 0;
}

if (K == 1)
{
    printf ("NO\n");
    return 0;
}

printf ("YES\n");
if (N < M)
{
    a[1][1] = 1;
    for (int i=2; i<=M; i++)
        if (sir[1][i-1] == 'N') a[1][i] = 3 - a[1][i-1];
        else a[1][i] = a[1][i-1];

    for (int i=2; i<=N; i++)
    {
        b[1] = 1;
        for (int j=2; j<=M; j++)
            if (sir[2*i-1][j-1] == 'N') b[j] = 3 - b[j-1];
            else b[j] = b[j-1];

        int nr = 0;
        for (int j=1; j<=M; j ++)
            if ( (sir[2*i-2][j] == 'N' && b[j] != a[i-1][j]) || (sir[2*i-2][j] == 'E' && b[j] == a[i-1][j]) )
                nr ++;

        if (nr < M - nr)
        {
            for (int j=1; j<=M; j++)
                b[j] = 3 - b[j];
        }

        for (int j=1; j<=M; j++)
            a[i][j] = b[j];
    }
}
else
{
    a[1][1] = 1;
    for (int i=2; i<=N; i++)
        if (sir[2*i-2][1] == 'N') a[i][1] = 3 - a[i-1][1];
        else a[i][1] = a[i-1][1];

    for (int j=2; j<=M; j++)
    {
        b[1] = 1;
        for (int i=2; i<=N; i++)
            if (sir[2*i-2][j] == 'N') b[i] = 3 - b[i-1];
            else b[i] = b[i-1];

        int nr = 0;
        for (int i=1; i<=N; i++)
            if ( (sir[2*i-1][j-1] == 'N' && b[i] != a[i][j-1]) || (sir[2*i-1][j-1] == 'E' && b[i] == a[i][j-1]) )
                nr ++;

        if (nr < N - nr)
        {
            for (int i=1; i<=N; i++)
                b[i] = 3 - b[i];
        }

        for (int i=1; i<=N; i++)
            a[i][j] = b[i];
    }
}
for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=1; j<=M; j++)
        printf ("%d ", a[i][j]);

return 0;
}