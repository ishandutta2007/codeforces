#include<bits/stdc++.h>

using namespace std;

int N, ans;
char sir[200009];
bool ap[200009];
vector < int > v[200009];

void dfs (int nod)
{
    if (ap[nod]) return ;
    ap[nod] = 1, ans ++;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0)
            dfs (*it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
gets (sir + 1);
for (int i=1; i<=N; i++)
    if (sir[i] == '>') v[i + 1].push_back (i);
    else v[i - 1].push_back (i);
dfs (0), dfs (N + 1);
printf ("%d\n", ans - 2);

return 0;
}