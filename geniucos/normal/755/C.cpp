#include<bits/stdc++.h>

using namespace std;

int cnt, N, sol, p[10009], ap[10009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &p[i]);
    if (p[i] == i) sol ++;
    else ap[p[i]] ++;
}
for (int i=1; i<=N; i++)
    cnt += (ap[i] > 0);
sol += cnt / 2;
//if (cnt % 2 != 0) printf ("fuck\n");
printf ("%d\n", sol);
return 0;
}