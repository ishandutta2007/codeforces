#include<bits/stdc++.h>

using namespace std;

int N, p[100009], ap[100009];
pair < int, int > v[100009];
vector < vector < int > > ans;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &v[i].first), v[i].second = i;
sort (v + 1, v + N + 1);
for (int i=1; i<=N; i++)
    p[i] = v[i].second;
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
    {
        vector < int > curr;
        int j = i;
        while (ap[j] == 0)
            curr.push_back (j), ap[j] = 1, j = p[j];
        ans.push_back (curr);
    }
printf ("%d\n", ans.size ());
for (auto v : ans)
{
    printf ("%d ", v.size ());
    for (auto it : v)
        printf ("%d ", it);
    printf ("\n");
}
return 0;
}