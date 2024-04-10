#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int P, maxi, n, ap[2009], dp[2009][2009], A[2009][2009], T[2009];
vector < int > v[2009];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

void dfs (int i, int nod)
{
    ap[nod] = 1;
    for(vector < int > :: iterator it = v[nod].begin(); it!=v[nod].end(); it++)
        if (ap[*it]==0)
        {
            A[i][*it] = A[i][nod] + dp[nod][*it];
            dfs (i, *it);
        }
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
scanf ("%d", &n);

for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        scanf ("%d", &dp[i][j]);
        if (i==j&&dp[i][j]!=0)
        {
            printf ("NO\n");
            return 0;
        }
    }

for (int i=1; i<=n; i++)
    for (int j=1; j<=n;j++)
        if (dp[i][j]!=dp[j][i])
        {
            printf ("NO\n");
            return 0;
        }

for (int i=1; i<=n; i++)
{
    maxi=-1;
    for (int j=1; j<=n; j++)
        if (dp[1][i] == dp[1][j] + dp[i][j] && i!=j)
        {
            if (dp[1][j]>maxi) maxi=dp[1][j], P=j;
        }
    T[i] = P;
}
for (int i=2; i<=n; i++)
if (T[i]!=0)
{
    v[i].push_back(T[i]);
    v[T[i]].push_back(i);
    if (dp[T[i]][i]==0)
    {
        printf ("NO\n");
        return 0;
    }
}

for (int i=1; i<=n; i++)
{
    A[i][i]=0;
    ap[i]=1;
    dfs (i, i);
    for (int j=1; j<=n; j++)
    {
        if (A[i][j]!=dp[i][j]||ap[j]==0)
        {
            printf ("NO\n");
            return 0;
        }
        ap[j]=0;
    }
}
printf ("YES\n");
return 0;
}