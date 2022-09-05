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

int N, K;
bool ap[1009][1009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
if (K > N - 1)
{
    printf ("-1\n");
    return 0;
}

for (int i=1; i<=K; i++)
    for (int j=0; j<N; j++)
        ap[j][(j + i) % N] = 1;

for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
        if (ap[i][j] && ap[j][i])
        {
            printf ("-1\n");
            return 0;
        }

printf ("%d\n", N * K);
for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
        if (ap[i][j])
            printf ("%d %d\n", i + 1, j + 1);

return 0;
}