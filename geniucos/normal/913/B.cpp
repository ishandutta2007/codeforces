#include<bits/stdc++.h>

using namespace std;

int N, t[1009], leaf[1009];
vector < int > v[1009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=2; i<=N; i++)
    leaf[i] = 1;
for (int i=2; i<=N; i++)
    scanf ("%d", &t[i]), leaf[t[i]] = 0, v[t[i]].push_back (i);
for (int i=1; i<=N; i++)
if (!leaf[i])
{
    int cnt = 0;
    for (auto j : v[i])
        cnt += leaf[j];
    if (cnt < 3)
    {
        printf ("No\n");
        return 0;
    }
}
printf ("Yes\n");
return 0;
}