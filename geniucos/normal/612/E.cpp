#include<bits/stdc++.h>

using namespace std;

int N, p[1000009], ans[1000009];
bool ap[1000009];
vector < vector < vector < int > > > cyc;

void add (vector < int > &curr)
{
    for (int i=0; i<curr.size (); i++)
        ans[curr[i]] = curr[(i + 1) % curr.size ()];
}

void combine (int l, vector < int > &g, vector < int > &h)
{
    vector < int > curr;
    for (int i=0; i<l; i++)
        curr.push_back (g[i]), curr.push_back (h[i]);
    add (curr);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), cyc.resize (N + 1);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
    {
        int j = i;
        vector < int > curr;
        while (ap[j] == 0)
            curr.push_back (j), ap[j] = 1, j = p[j];
        cyc[curr.size ()].push_back (curr);
    }
for (int i=2; i<=N; i+=2)
    if (cyc[i].size () % 2 == 1)
    {
        printf ("-1\n");
        return 0;
    }
for (int i=1; i<=N; i++)
{
    if (i & 1)
    {
        for (auto v : cyc[i])
        {
            vector < int > curr (i);
            int pos = 0;
            for (auto it : v)
                curr[pos] = it, pos = (pos + 2) % v.size ();
            add (curr);
        }
        continue;
    }
    vector < int > g;
    for (auto v : cyc[i])
        if (g.empty ()) g = v;
        else combine (i, g, v), g.clear ();
}
for (int i=1; i<=N; i++)
    printf ("%d%c", ans[i], " \n"[i == N]);
return 0;
}