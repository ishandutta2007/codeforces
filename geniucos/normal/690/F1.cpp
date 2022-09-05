#include<bits/stdc++.h>

using namespace std;

int N, sol;
vector < int > v[10009];

void dfs (int nod, int tata, int niv)
{
    sol += (niv >= 2);
    int sons = 0;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
    if (*it != tata)
        dfs (*it, nod, niv + 1), sons ++;
    sol += sons * (sons - 1) / 2;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y), v[y].push_back (x);
}
dfs (1, -1, 0);
printf ("%d\n", sol);
return 0;
}