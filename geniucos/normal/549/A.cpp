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

int N, M, nr, ap[10009];
char sir[69][69];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    gets (sir[i] + 1);
for (int i=1; i<N; i++)
    for (int j=1; j<M; j++)
    {
        ap[sir[i][j]] ++, ap[sir[i+1][j]] ++, ap[sir[i][j+1]] ++, ap[sir[i+1][j+1]] ++;
        if (ap['f'] * ap['a'] * ap['c'] * ap['e'] == 1)
            nr ++;
        ap[sir[i][j]] --, ap[sir[i+1][j]] --, ap[sir[i][j+1]] --, ap[sir[i+1][j+1]] --;
    }
printf ("%d\n", nr);

return 0;
}