#include<bits/stdc++.h>

using namespace std;

int N, a[100009], b[100009];
pair < int, int > pr[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=0; i<N; i++)
    scanf ("%d", &pr[i].first), pr[i].second = i;
sort (pr, pr + N);
for (int I=0; I<N; I++)
{
    int i = pr[I].second, si = pr[I].first;
    if (I < N / 3) a[i] = I, b[i] = si - I;
    else
    if (I < 2 * N / 3 ) b[i] = I, a[i] = si - I;
    else b[i] = N - I - 1, a[i] = si - b[i];
}
printf ("YES\n");
for (int i=0; i<N; i++)
    printf ("%d ", a[i]);
printf ("\n");
for (int i=0; i<N; i++)
    printf ("%d ", b[i]);
printf ("\n");
return 0;
}