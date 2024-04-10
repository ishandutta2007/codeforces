#include<bits/stdc++.h>

using namespace std;

char sir[300009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int N, x, y;
long long ans;
scanf ("%d %d %d\n", &N, &x, &y);
scanf ("%s", sir + 1);
if (x < y)
{
    ///reduce to only 1s
    int cnt = 0, any0 = (sir[N] == '0');
    for (int i=1; i<N; i++)
        cnt += (sir[i] != sir[i + 1]),
        any0 |= (sir[i] == '0');
    ans = 1LL * ((cnt - (sir[1] == '1')) / 2) * x;
    if (any0)
        ans += y;
}
else
{
    int cnt0 = 0;
    for (int i=1; i<=N; i++)
        cnt0 += (sir[i] == '0' && sir[i - 1] != '0');
    ans = 1LL * y * cnt0;
}
printf ("%I64d\n", ans);
return 0;
}