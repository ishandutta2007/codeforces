#include<bits/stdc++.h>

using namespace std;

int N, ap[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int K;
scanf ("%d", &N), K = 1;
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    if (ap[x]) K ++;
    ap[x] = 1;
}
printf ("%d\n", K);

return 0;
}