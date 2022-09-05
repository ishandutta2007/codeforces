#include<bits/stdc++.h>

using namespace std;

int nr, root, N, t[200009], cc[200009], df[200009];
vector < int > v[200009], h[200009];
pair < int, int > per[200009];

void doMatch (int i, int j, int cntr)
{
    //printf ("%d %d %d\n", i, j, cntr);
    per[i] = {j, cntr};
    per[j] = {i, cntr};
}

int jos (int x, int y)
{
    if (t[x] == y) return x;
    return y;
}

int pairEdges (int nod)
{
    vector < int > curr;
    for (auto it : v[nod])
    {
        int val = pairEdges (it);
        if (val != 0)
            curr.push_back (val);
    }
    curr.push_back (nod);
    for (int i=0; i+1 < curr.size (); i+=2)
        doMatch (curr[i], curr[i + 1], nod);
    ///returneaza ce mai trebuie matchuit
    if (curr.size () & 1) return nod;
    return 0;
}

bool deleted[200009];

void delNode (int i)
{
    deleted[i] = 1;
    for (auto it : h[i])
        if (!deleted[it])
        {
            df[it] --;
            if (df[it] == 0)
                cc[++nr] = it;
        }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &t[i]);
    if (t[i] == 0) root = i;
    else
    {
        v[t[i]].push_back (i);
        h[i].push_back (t[i]);
        h[t[i]].push_back (i);
    }
}
int curr = pairEdges (root);
if (curr == 0)
{
    printf ("NO\n");
    return 0;
}
for (int i=1; i<=N; i++)
    for (auto it : h[i])
        df[i] += (per[jos (i, it)].second != i);
for (int i=1; i<=N; i++)
    if (df[i] == 0)
        cc[++nr] = i;
for (int i=1; i<=nr; i++)
    delNode (cc[i]);
if (nr != N)
{
    printf ("NO\n");
    return 0;
}
printf ("YES\n");
for (int i=1; i<=nr; i++)
    printf ("%d\n", cc[i]);
return 0;
}