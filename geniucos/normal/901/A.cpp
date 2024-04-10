#include<bits/stdc++.h>

using namespace std;

int N, h, pos = -1, cnt[200009], a[200009], b[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &h);
for (int i=0; i<=h; i++)
{
    scanf ("%d", &cnt[i]), N += cnt[i];
    if (i >= 1 && cnt[i] > 1 && cnt[i - 1] > 1) pos = i;
}
if (pos == -1)
{
    printf ("perfect\n");
    return 0;
}
printf ("ambiguous\n");
int lstA = 1, lstB = 1, NA = 1, NB = 1;
for (int i=1; i<=h; i++)
{
    for (int j=1; j<=cnt[i]; j++)
        a[++NA] = lstA, b[++NB] = lstB;
    if (i == pos)
        b[NB] = lstB - 1;
    lstA = NA, lstB = NB;
}
for (int i=1; i<=N; i++)
    printf ("%d%c", a[i], " \n"[i == N]);
for (int i=1; i<=N; i++)
    printf ("%d%c", b[i], " \n"[i == N]);
return 0;
}