#include<bits/stdc++.h>

using namespace std;

int N, M, squareFree[7009], h[7009], nr;
bitset < 7002 > dp[100009], init[7009], mob[7009], aux;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=1; i<=7000; i++)
    for (int j=i; j<=7000; j+=i)
        init[j][i] = 1;
for (int i=1; i<=7000; i++)
    squareFree[i] = 1;
for (int i=2; i<=7000; i++)
    for (int j=i * i; j<=7000; j+=i * i)
        squareFree[j] = 0;
for (int i=1; i<=7000; i++)
    if (squareFree[i])
        h[++nr] = i;
for (int i=1; i<=7000; i++)
    for (int j=1; j<=nr && h[j] * i <= 7000; j++)
        mob[i][h[j] * i] = 1;
scanf ("%d %d", &N, &M);
while (M --)
{
    int type, x, y, z, v;
    scanf ("%d", &type);
    if (type == 1)
    {
        scanf ("%d %d", &x, &v);
        dp[x] = init[v];
        continue;
    }
    if (type == 2)
    {
        scanf ("%d %d %d", &x, &y, &z);
        aux = dp[y] ^ dp[z];
        dp[x] = aux;
        continue;
    }
    if (type == 3)
    {
        scanf ("%d %d %d", &x, &y, &z);
        aux = dp[y] & dp[z];
        dp[x] = aux;
        continue;
    }
    scanf ("%d %d", &x, &v);
    printf ("%d", (dp[x] & mob[v]).count () & 1);
}
printf ("\n");
return 0;
}