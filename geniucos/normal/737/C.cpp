#include<bits/stdc++.h>

using namespace std;

int N, S, ans, ap[200009], a[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &S);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
ans = (a[S] != 0), a[S] = 0;
if (N == 1)
{
    printf ("%d\n", ans);
    return 0;
}
for (int i=1; i<=N; i++)
    ap[a[i]] ++;
int cnt0 = 0, tot = 1, mini = N + 2;
for (int K=1; K<=N; K++)
{
    cnt0 += (ap[K] == 0), tot += ap[K];
    int curr = max (cnt0, (N - tot));
    if (curr < mini) mini = curr;
}
printf ("%d\n", mini + ans);
return 0;
}