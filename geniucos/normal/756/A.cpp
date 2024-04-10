#include<bits/stdc++.h>

using namespace std;

int ans, N, nr_c, cnt, b[200009], ap[200009], p[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &b[i]);
    cnt += (b[i] == 1);
}
ans = (cnt % 2 == 0);
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
    {
        int j = i;
        while (ap[j] == 0) ap[j] = 1, j = p[j];
        nr_c ++;
    }
if (nr_c != 1) ans += nr_c;
printf ("%d\n", ans);

return 0;
}