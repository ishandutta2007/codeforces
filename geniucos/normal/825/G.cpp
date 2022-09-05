#include<bits/stdc++.h>

using namespace std;

int N, Q, dp[1000009];
vector < int > v[1000009];

void dfs (int nod, int tata)
{
    if (tata != -1) dp[nod] = min (dp[tata], nod);
    else dp[nod] = nod;
    for (auto it : v[nod])
        if (it != tata)
            dfs (it, nod);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &Q);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
int last = 0, type, x, updatedAns = N +  1;
scanf ("%d %d", &type, &x), x = (x + last) % N + 1;
dfs (x, -1), Q --;
while (Q --)
{
    scanf ("%d %d", &type, &x), x = (x + last) % N + 1;
    if (type == 2)
        last = min (dp[x], updatedAns), printf ("%d\n", last);
    else
        updatedAns = min (updatedAns, dp[x]);
}

return 0;
}