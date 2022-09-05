#include<cstdio>

using namespace std;

int T, N, P, ap[109][109];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &T);
while (T --)
{
    scanf ("%d %d", &N, &P), P += 2 * N;
    for (int df = 1; df < N && P; df++)
        for (int i=0; i<N && P; i++)
            ap[i][(i + df) % N] = 1, P --;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (ap[i][j])
                printf ("%d %d\n", i + 1, j + 1);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            ap[i][j] = 0;
}

return 0;
}