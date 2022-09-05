#include<bits/stdc++.h>

using namespace std;

int N, v[2000009], p[2000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    p[i] = i;
for (int i=2; i<=N; i++)
{
    int nr = 0;
    for (int j=i - 1; j<=N + i - 2; j+=i)
        v[++nr] = j;
    p[N + i - 1] = p[v[nr]];
    for (int i=nr; i>1; i--)
        p[v[i]] = p[v[i - 1]];
}
for (int i=1; i<=N; i++)
    printf ("%d ", p[N + i - 1]);
printf ("\n");
return 0;
}