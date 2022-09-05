#include<bits/stdc++.h>

using namespace std;

int N, s[300009];
vector < int > v[2];

long long cnt (int n)
{
    return 1LL * n * (n - 1) / 2;
}

long long ans = 0;
void solve (vector < int > v)
{
    for (int i=0; i<v.size (); i++)
    {
        int j = i;
        while (j + 1 < v.size () && v[j + 1] == v[i])
            j ++;
        ans += cnt (j - i + 1);
        i = j;
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
v[0].push_back (0);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &s[i]), s[i] ^= s[i - 1];
    v[i & 1].push_back (s[i]);
}
for (int lin = 0; lin < 2; lin ++)
{
    sort (v[lin].begin (), v[lin].end ());
    solve (v[lin]);
}
printf ("%I64d\n", ans);
return 0;
}