#include<cstdio>
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

int N, M, a[109][109];
char sir[109][109];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    gets (sir[i] + 1);
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
    {
        int sg;
        if (sir[i][j] == 'W')
            sg = 1;
        else
            sg = -1;
        a[i][j] += sg, a[i-1][j] -= sg, a[i][j-1] -= sg, a[i-1][j-1] += sg;
    }
int sol = 0;
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (a[i][j] != 0)
            sol ++;
printf ("%d\n", sol);

return 0;
}