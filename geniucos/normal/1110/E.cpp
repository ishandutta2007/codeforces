#include<bits/stdc++.h>

using namespace std;

int N, a[100009], b[100009], c[100009], d[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<=N; i++)
    scanf ("%d", &b[i]);
if (a[1] != b[1] || a[N] != b[N])
{
    printf ("No\n");
    return 0;
}
for (int i=1; i<N; i++)
    c[i] = a[i + 1] - a[i],
    d[i] = b[i + 1] - b[i];
sort (c + 1, c + N);
sort (d + 1, d + N);
for (int i=1; i<N; i++)
    if (c[i] != d[i])
    {
        printf ("No\n");
        return 0;
    }
printf ("Yes\n");
return 0;
}