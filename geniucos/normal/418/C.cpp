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

int N, M, lin[109], col[109];

void solve (int v[], int N)
{
    if (N == 1)
    {
        v[1] = 1;
        return ;
    }
    if (N == 2)
    {
        v[1] = 3, v[2] = 4;
        return ;
    }
    if (N % 2 == 0)
    {
        for (int i=1; i<N; i++)
            v[i] = 1;
        v[N] = (N - 2) / 2;
        return ;
    }
    for (int i=2; i<N; i++)
        v[i] = 1;
    v[1] = 2, v[N] = (N + 1) / 2;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
solve (lin, N), solve (col, M);
for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=1; j<=M; j++)
        printf ("%d ", lin[i] * col[j]);

return 0;
}