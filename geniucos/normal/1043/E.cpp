#include<bits/stdc++.h>

using namespace std;

int N, M, x[300009], y[300009];
long long ans[300009], sumX[300009], sumY[300009];
pair < int , int > v[300009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &x[i], &y[i]),
    v[i] = {x[i] - y[i], i};
for (int i=1; i<=M; i++)
{
    int a, b;
    scanf ("%d %d", &a, &b);
    int fxy = min (x[a] + y[b], x[b] + y[a]);
    ans[a] -= fxy, ans[b] -= fxy;
}
sort (v + 1, v + N + 1);
for (int i=1; i<=N; i++)
    sumX[i] = sumX[i - 1] + x[v[i].second],
    sumY[i] = sumY[i - 1] + y[v[i].second];
for (int i=1; i<=N; i++)
{
    int pos = v[i].second;
    ans[pos] += 1LL * x[pos] * (N - i) + 1LL * y[pos] * (i - 1) + sumY[N] - sumY[i] + sumX[i - 1];
}
for (int i=1; i<=N; i++)
    printf ("%I64d%c", ans[i], " \n"[i == N]);
return 0;
}