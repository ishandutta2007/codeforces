#include<bits/stdc++.h>

using namespace std;

int N, nr, M;
char ans[109][109];

void add (int i, int j) {ans[i][j] = ans[j][i] = '1';}

void Print ()
{
    for (int i=1; i<=nr; i++)
        for (int j=1; j<=nr; j++)
            if (ans[i][j] == 0) ans[i][j] = '0';
    printf ("%d\n", nr);
    for (int i=1; i<=nr; i++)
        printf ("%s\n", ans[i] + 1);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i * (i - 1) * (i - 2) / 6 <= N; i++)
    M = i;

nr = M;
for (int i=1; i<=M; i++)
    for (int j=i + 1; j<=M; j++)
        add (i, j);

N -= M * (M - 1) * (M - 2) / 6;
while (N)
{
    int p = 0;
    while (p * (p - 1) / 2 <= N) p ++;
    p --, nr ++;
    for (int i=1; i<=p; i++)
        add (i, nr);
    N -= (p - 1) * p / 2;
}
Print ();
return 0;
}