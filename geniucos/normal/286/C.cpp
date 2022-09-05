#include<bits/stdc++.h>

using namespace std;

int N, M, nr, a[1000009], st[1000009];
bool cl[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
scanf ("%d", &M);
for (int i=1; i<=M; i++)
{
    int x;
    scanf ("%d", &x);
    cl[x] = 1;
}
for (int i=N; i>=1; i--)
{
    if (st[nr] == a[i] && cl[i] == 0) a[i] = -a[i], nr --;
    else st[++nr] = a[i];
}
if (nr != 0)
{
    printf ("NO\n");
    return 0;
}
printf ("YES\n");
for (int i=1; i<=N; i++)
    printf ("%d ", -a[i]);
printf ("\n");
return 0;
}