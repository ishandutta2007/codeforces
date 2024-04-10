#include<bits/stdc++.h>

using namespace std;

int N, b[200009], c[200009], cnt[50];
long long S, a[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &b[i]);
for (int i=1; i<=N; i++)
    scanf ("%d", &c[i]), S += b[i] + c[i];
if (S % (2 * N) != 0)
{
    printf ("-1\n");
    return 0;
}
S /= (2 * N);
for (int i=1; i<=N; i++)
    a[i] = (b[i] + c[i] - S) / N;
for (int i=1; i<=N; i++)
    for (int j=0; j<=40; j++)
        cnt[j] += ((a[i] & (1LL << j)) > 0);
for (int i=1; i<=N; i++)
{
    long long an = 0, sa = 0;
    for (int j=0; j<=40; j++)
    {
        if (a[i] & (1LL << j)) an += (1LL << j) * cnt[j], sa += (1LL << j) * N;
        else sa += (1LL << j) * cnt[j];
    }
    if (an != b[i] || sa != c[i])
    {
        printf ("-1\n");
        return 0;
    }
}
for (int i=1; i<=N; i++)
    printf ("%I64d ", a[i]);
printf ("\n");
return 0;
}