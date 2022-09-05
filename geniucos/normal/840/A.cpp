#include<bits/stdc++.h>

using namespace std;

int N, a[200009], ans[200009];
pair < int, int > v[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<=N; i++)
    scanf ("%d", &v[i].first), v[i].second = i;
sort (v + 1, v + N + 1), reverse (v + 1, v + N + 1);
sort (a + 1, a + N + 1);
int j = 1;
for (int i=1; i<=N; i++)
    ans[v[i].second] = a[j ++];
for (int i=1; i<=N; i++)
    printf ("%d%c", ans[i], " \n"[i == N]);

return 0;
}