#include<bits/stdc++.h>

using namespace std;

int N, ans;
vector < int > v[500009], h;

void dfs (int nod, int tata, int lv)
{
    if (v[nod].size () == 1) h.push_back (lv);
    for (auto it : v[nod])
        if (it != tata)
            dfs (it, nod, lv + 1);
}

int main ()
{
scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
for (auto it : v[1])
{
    h.clear (), dfs (it, 1, 1);
    sort (h.begin (), h.end ());
    for (int i=1; i<h.size (); i++)
        h[i] = max (h[i - 1] + 1, h[i]);
    ans = max (ans, h[h.size () - 1]);
}
printf ("%d\n", ans);
return 0;
}