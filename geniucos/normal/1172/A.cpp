#include<bits/stdc++.h>

using namespace std;

int N, a[200009], ap[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    if (x > 0)
        ap[x] = 1;
}
int ans = 0;
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    if (a[i] > 0 && i - a[i] + 1 > ans)
        ans = i - a[i] + 1;
}
ans += N;
if (a[N] != 0)
{
    int j = N;
    while (a[j] != 0 && a[j - 1] != 0 && a[j - 1] == a[j] - 1)
        j --;
    if (a[j] == 1)
    {
        ///try to keep stacking
        bool ok = 1;
        for (int i=a[N] + 1; i<=N; i++)
        {
            if (ap[i] == 0)
            {
                ok = 0;
                break;
            }
            ap[a[i - a[N]]] = 1;
        }
        if (ok)
            ans = N - a[N];
    }
}
printf ("%d\n", ans);
return 0;
}