#include<bits/stdc++.h>

using namespace std;

int Q, N, K, nr, a[5009];
pair < int, int > b[100009];

int get_cnt (int val)
{
    if (val == 0) return 0;
    int p = 1, u = nr, mij, ras = -1;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (b[mij].first >= val) ras = mij, u = mij - 1;
        else p = mij + 1;
    }
    if (ras == -1 || b[ras].first != val) return K + 1;
    return b[ras].second;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<=K; i++)
    for (int j=1; j<=N; j++)
        b[++nr] = make_pair (i * a[j], i);
sort (b + 1, b + nr + 1);
scanf ("%d", &Q);
while (Q --)
{
    int X, ans = K + 1;
    scanf ("%d", &X);
    for (int i=1; i<=K; i++)
        for (int j=1; j<=N; j++)
        if (a[j] * i <= X)
        {
            int curr = get_cnt (X - a[j] * i);
            if (curr + i < ans) ans = curr + i;
        }
    if (ans > K) ans = -1;
    printf ("%d\n", ans);
}
return 0;
}