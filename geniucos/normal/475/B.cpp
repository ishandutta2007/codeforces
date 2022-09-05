#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int nr, n, m, cod[30][30], ap[409];
char A[30], B[30];

vector < int > v[409];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

void dfs (int nod)
{
    ap[nod] = 1;
    for(vector < int > :: iterator it = v[nod].begin(); it != v[nod].end(); it++)
        if (ap[*it] == 0) dfs (*it);
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d%d\n", &n, &m);
gets (A+1);
gets (B+1);
for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cod[i][j] = ++ nr;
for (int i=1; i<=n; i++)
{
    if (A[i] == '<')
    {
        for (int j=2; j<=m; j++)
            v[cod[i][j]].push_back(cod[i][j-1]);
    }
    else
    {
        for (int j=1; j<m; j++)
            v[cod[i][j]].push_back(cod[i][j+1]);
    }
}
for (int j=1; j<=m; j++)
{
    if (B[j] == '^')
    {
        for (int i=2; i<=n; i++)
            v[cod[i][j]].push_back(cod[i-1][j]);
    }
    else
    {
        for (int i=1; i<n; i++)
            v[cod[i][j]].push_back(cod[i+1][j]);
    }
}
for (int i=1; i<=nr; i++)
{
    for (int j=1; j<=nr; j++)
        ap[j] = 0;
    dfs (i);
    for (int j=1; j<=nr; j++)
        if (ap[j] == 0)
        {
            printf ("NO\n");
            return 0;
        }
}
printf ("YES\n");
return 0;
}