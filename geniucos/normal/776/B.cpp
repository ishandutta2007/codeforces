#include<bits/stdc++.h>

using namespace std;

int N, cr[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N == 1)
{
    printf ("1\n1\n");
    return 0;
}
if (N == 2)
{
    printf ("1\n1 1\n");
    return 0;
}
printf ("2\n");
for (int i=2; i<=N + 1; i++)
{
    if (cr[i] == 0)
        for (int j=i+i; j<=N + 1; j+=i)
            cr[j] = 1;
    if (cr[i] == 0) printf ("1 ");
    else printf ("2 ");
}
printf ("\n");

return 0;
}