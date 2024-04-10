#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, mat[59][59], ans[59];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        scanf ("%d", &mat[i][j]);
for (int i=1; i<=N; i++)
{
    for (int j=1; j<=N; j++)
    if (ans[j] == 0)
    {
        bool ok = 1;
        for (int k=1; k<=N; k++)
            if (mat[j][k] != 0 && mat[j][k] != i)
            {
                ok = 0;
                break;
            }
        if (ok)
        {
            ans[j] = i;
            for (int k=1; k<=N; k++)
                if (mat[j][k] != 0) mat[j][k] = mat[k][j] = 0;
            break;
        }
    }
}
for (int i=1; i<=N; i++)
    printf ("%d ", ans[i]);
printf ("\n");
return 0;
}