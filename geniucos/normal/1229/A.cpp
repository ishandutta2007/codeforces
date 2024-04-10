#include<bits/stdc++.h>

using namespace std;

int N, cnt[7009], ap[7009], b[7009];
long long ans, a[7009];
bool isBetter (int i, int j)
{
    return ((a[j] & a[i]) != a[i]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%I64d", &a[i]), ap[i] = 1;
for (int i=1; i<=N; i++)
    scanf ("%d", &b[i]), ans += b[i];
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        if (i != j)
            cnt[i] += isBetter (i, j);
int currN = N;
while (1)
{
    bool ok = 1;
    for (int i=1; i<=N; i++)
        if (cnt[i] == currN - 1 && ap[i] == 1)
        {
            ok = 0, ap[i] = 0, currN --, ans -= b[i];
            for (int j=1; j<=N; j++)
                if (ap[j] == 1)
                    cnt[j] -= isBetter (j, i);
            break;
        }
    if (ok)
        break;
}
printf ("%I64d\n", ans);
return 0;
}