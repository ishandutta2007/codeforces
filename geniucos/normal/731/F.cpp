#include<bits/stdc++.h>

using namespace std;

int N, M, s[200009], a[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]), s[a[i]] ++;
    if (a[i] > M) M = a[i];
}
for (int i=1; i<=M; i++)
    s[i] += s[i - 1];
long long maxi = M;
for (int i=1; i<=M; i++)
if (s[i] != s[i - 1])
{
    if (i <= M / i)
    {
        long long sum = 0;
        for (int j=1; j<=N; j++)
            sum += a[j] - a[j] % i;
        if (sum > maxi) maxi = sum;
        continue;
    }
    long long sum = 0;
    for (int j=i; j<=M; j+=i)
    {
        int dr = j + i - 1;
        if (dr > M) dr = M;
        sum += 1LL * j * (s[dr] - s[j - 1]);
    }
    if (sum > maxi) maxi = sum;
}
printf ("%I64d\n", maxi);

return 0;
}