#include<bits/stdc++.h>

using namespace std;

int root, N, x[1009], y[1009], w[1009];
vector < pair < int, int > > v[1009];
vector < pair < pair < int, int >, int > > ans;

int dfs (int nod, int tata)
{
    int toReturn = -1;
    if (v[nod].size () == 1 && tata != -1)
        toReturn = nod;
    x[nod] = y[nod] = -1;
    for (auto it : v[nod])
        if (it.first != tata)
        {
            w[it.first] = it.second;
            int curr = dfs (it.first, nod);
            if (x[nod] == -1) x[nod] = curr;
            else y[nod] = curr;
            toReturn = curr;
        }
    return toReturn;///some random leaf
}

void perform (int u, int v, int c)
{
    ans.push_back ({{u, v}, c});
    //printf ("%d %d %d\n", u, v, c);
}

void fix (int nod, int tata)
{
    int curr = w[nod];
    for (auto it : v[nod])
        if (it.first != tata)
            fix (it.first, nod), curr -= w[it.first];
    ///so i want -curr on the path from nod to root
    if (v[nod].size () != 1)
    {
        //printf ("** %d %d %d  (%d,%d) %d   %d\n", nod, x[nod], y[nod], x[nod], y[nod], root, curr);
        perform (x[nod], root, -curr / 2);
        perform (y[nod], root, -curr / 2);
        perform (x[nod], y[nod], curr / 2);
    }
    else perform (nod, root, -curr);
}

void print ()
{
    printf ("YES\n%d\n", ans.size ());
    for (auto it : ans)
        printf ("%d %d %d\n", it.first.first, it.first.second, it.second);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y, z;
    scanf ("%d %d %d", &x, &y, &z);
    v[x].push_back ({y, -z});
    v[y].push_back ({x, -z});
}
for (int i=1; i<=N; i++)
{
    if (v[i].size () == 1)
        root = i;
    if (v[i].size () == 2)
    {
        printf ("NO\n");
        return 0;
    }
}
dfs (root, -1);
fix (v[root][0].first, root);
print ();
return 0;
}