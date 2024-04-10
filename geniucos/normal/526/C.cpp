#include<bits/stdc++.h>

using namespace std;

int Hr, Hb, Wr, Wb, C;
const int K = 20000;

long long f (int x)
{
    if (1LL * x * Wr > C || x < 0) return 0LL;
    int y = (C - 1LL * x * Wr) / Wb;
    return 1LL * Hr * x + 1LL * y * Hb;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d %d", &C, &Hr, &Hb, &Wr, &Wb);
int p = 0, u = C / Wr - 1, mij;
long long ans = f (0);
while (p <= u)
{
    mij = (p + u) >> 1;
    if (f (mij) > ans) ans = f (mij);
    if (f (mij + 1) > ans) ans = f (mij);
    if (f (mij) < f (mij + 1)) p = mij + 1;
    else u = mij - 1;
}
for (int i=0; i<=K && i * Wr <= C; i++)
    ans = max (ans, f (i));
for (int i=max (0, C / Wr - K); i * Wr <= C; i++)
    ans = max (ans, f (i));
for (int i=mij - K; i<=mij + K; i++)
    ans = max (ans, f (i));
for (int i=C / Wr - K; i<=C / Wr + K; i++)
    ans = max (ans, f (i));


swap (Hr, Hb), swap (Wr, Wb);



p = 0, u = C / Wr - 1;
ans = max (ans, f (0));
while (p <= u)
{
    mij = (p + u) >> 1;
    if (f (mij) > ans) ans = f (mij);
    if (f (mij + 1) > ans) ans = f (mij);
    if (f (mij) < f (mij + 1)) p = mij + 1;
    else u = mij - 1;
}
for (int i=0; i<=K && i * Wr <= C; i++)
    ans = max (ans, f (i));
for (int i=max (0, C / Wr - K); i * Wr <= C; i++)
    ans = max (ans, f (i));
for (int i=mij - K; i<=mij + K; i++)
    ans = max (ans, f (i));
for (int i=C / Wr - K; i<=C / Wr + K; i++)
    ans = max (ans, f (i));
printf ("%I64d\n", ans);
return 0;
}