#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int sol, n, m, ap[1009];
char a[1009][1009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d%d\n", &n, &m);
for (int i=1; i<=n; i++)
    gets (a[i] + 1);
for (int j=1; j<=m; j++)
{
    bool ok = 0;
    for (int i=1; i<n; i++)
        if (ap[i] == 0 && a[i][j] > a[i+1][j])
        {
            ok = 1;
            break;
        }
    if (ok == 1)
        sol ++;
    else
    {
        for (int i=1; i<n; i++)
            if (ap[i] == 0 && a[i][j] < a[i+1][j])
                ap[i] = 1;
    }
}
printf ("%d\n", sol);

return 0;
}