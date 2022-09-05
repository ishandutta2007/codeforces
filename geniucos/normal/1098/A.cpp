#include<bits/stdc++.h>

using namespace std;

int N, s[100009], t[100009], h[100009];
vector < int > v[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
h[1] = 1;
for (int i=2; i<=N; i++)
    scanf ("%d", &t[i]), v[t[i]].push_back (i),
    h[i] = h[t[i]] ^ 1;
for (int i=1; i<=N; i++)
{
    scanf ("%d", &s[i]);
    if (s[i] == -1 && h[i] == 1)
    {
        printf ("-1\n");
        return 0;
    }
}
long long ans = s[1];
for (int i=2; i<=N; i++)
{
    if (h[i] == 1) ans += s[i] - s[t[i]];
    else
    {
        int minS = 1e9 + 10;
        for (auto j : v[i])
            minS = min (minS, s[j]);
        if (v[i].empty ())
            minS = s[t[i]];
        if (minS < s[t[i]])
        {
            printf ("-1\n");
            return 0;
        }
        s[i] = minS, ans += s[i] - s[t[i]];
    }
}
printf ("%I64d\n", ans);
return 0;
}