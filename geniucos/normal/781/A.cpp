#include<bits/stdc++.h>

using namespace std;

int maxi, N, ans[200009];
vector < int > v[200009];

void dfs (int nod, int tata)
{
    int val = 0;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != tata)
        {
            val ++;
            while (val == ans[nod] || (tata != -1 && val == ans[tata])) val ++;
            ans[*it] = val, dfs (*it, nod);
        }
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
    v[x].push_back (y);
    v[y].push_back (x);
}
ans[1] = 1, dfs (1, -1);
for (int i=2; i<=N; i++)
    if (ans[i] > maxi) maxi = ans[i];
printf ("%d\n", maxi);
for (int i=1; i<=N; i++)
    printf ("%d ", ans[i]);
printf ("\n");
return 0;
}