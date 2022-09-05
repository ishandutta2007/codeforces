#include<bits/stdc++.h>

using namespace std;

int N, M, **a, x[1000009], y[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
a = new int*[N + 2];
for (int i=1; i<=N; i++)
    a[i] = new int[M + 2];
int nr = 0;
for (int i1=1, i2=N; i1<=i2; i1++,i2--)
{
    if (i1 != i2)
    {
        for (int j1=1,j2=M; j1<=M; j1++, j2--)
            a[i1][j1] = ++nr, a[i2][j2] = ++nr;
    }
    else
    {
        for (int j1=1,j2=M; j1<=j2; j1++, j2--)
        {
            a[i1][j1] = ++nr;
            if (j1 != j2) a[i1][j2] = ++nr;
        }
    }
}
/*for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=1; j<=M; j++)
        printf ("%2d ", a[i][j]);*/
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        x[a[i][j]] = i, y[a[i][j]] = j;
/*set < pair < int, int > > S;
for (int i=2; i<=N * M; i++)
    S.insert ({x[i + 1]-x[i], y[i+1]-y[i]});
assert (S.size () == N * M - 1);*/
for (int i=1; i<=N * M; i++)
    printf ("%d %d\n", x[i], y[i]);
return 0;
}