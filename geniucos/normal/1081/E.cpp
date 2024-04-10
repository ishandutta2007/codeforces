#include<bits/stdc++.h>

using namespace std;

int N, a[200009], b[200009], x[200009];
const int maxM = 200010;
vector < pair < int, int > > v[maxM + 10];

void fail ()
{
    printf ("No\n");
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N / 2; i++)
    scanf ("%d", &x[i]);
for (int i=1; i<=maxM; i++)
{
    int x = i;
    for (int j=i; j<=maxM; j+=i)
    {
        int y = j / i;
        if ((x & 1) ^ (y & 1)) continue;
        if (y > x) break;
        v[j].push_back ({(x - y) / 2, (x + y) / 2});
    }
}
int lastOne = 0;
for (int i=1; i<=N / 2; i++)
{
    ///I want (a, b) from v[x[i]] with a > lastOne and minimum a
    if (v[x[i]].empty ())
        fail ();
    int pos = lower_bound (v[x[i]].begin (), v[x[i]].end (), make_pair (lastOne + 1, 0)) - v[x[i]].begin ();
    if (pos == v[x[i]].size ())
        fail ();
    if (v[x[i]][pos].first > lastOne)
        a[i] = v[x[i]][pos].first, b[i] = lastOne = v[x[i]][pos].second;
}
printf ("Yes\n");
for (int i=1; i<=N / 2; i++)
{
    printf ("%lld ", 1LL * a[i] * a[i] - 1LL * b[i - 1] * b[i - 1]);
    printf ("%d ", x[i]);
}
printf ("\n");
return 0;
}