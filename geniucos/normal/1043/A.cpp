#include<bits/stdc++.h>

using namespace std;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int N, x, s = 0, M;
scanf ("%d", &N), M = N;
int minK = 0;
while (M --)
    scanf ("%d", &x), s += x, minK = max (minK, x);
while (1LL * N * minK <= 2LL * s)
    minK ++;
printf ("%d\n", minK);
return 0;
}