#include<bits/stdc++.h>

using namespace std;

int N, K, S, T, mini, x[200009];
pair < int, int > a[200009];

int Cost (int V)
{
    int ans = 2 * S;
    for (int i=0; i<=K; i++)
    {
        int d = x[i + 1] - x[i], q = 0;
        if (V >= 2 * d) q = d;
        else q = V - d;
        ans -= q;
    }
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &N, &K, &S, &T);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i].first, &a[i].second);
for (int i=1; i<=K; i++)
    scanf ("%d", &x[i]);
sort (x + 1, x + K + 1);
x[0] = 0, x[K + 1] = S, mini = -1;
int p = 0, u = 2 * S, ras = -1;
for (int i=0; i<=K; i++)
    if (x[i + 1] - x[i] > p) p = x[i + 1] - x[i];
//for (int i=p; i<=u; i++)
  //  printf ("%d -> %d\n", i, Cost (i));
while (p <= u)
{
    int mij = p + (u - p) / 2;
    if (Cost (mij) <= T) ras = mij, u = mij - 1;
    else p = mij + 1;
}
if (ras == -1)
{
    printf ("-1\n");
    return 0;
}
for (int i=1; i<=N; i++)
    if (a[i].second >= ras && (a[i].first < mini || mini == -1))
        mini = a[i].first;
printf ("%d\n", mini);
return 0;
}