#include<bits/stdc++.h>

using namespace std;

int N, u, d;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    if (x == 1) u ++;
    else d ++;
}
if (u == 0 || d == 0)
{
    int value = (u == 0 ? 2 : 1);
    for (int i=1; i<=N; i++)
        printf ("%d%c", value, " \n"[i == d]);
    return 0;
}
///I can achieve all primes till u+2d by 212..211..1
printf ("2 1"), u --, d --;
while (d > 0)
    printf (" 2"), d --;
while (u > 0)
    printf (" 1"), u --;
printf ("\n");
return 0;
}