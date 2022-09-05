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

int N;

bool prim (int N)
{
    if (N == 1) return 0;
    if (N == 2) return 1;
    if (N == 3) return 1;
    for (int i=2; i * i <= N; i++)
        if (N % i == 0)
            return 0;
    return 1;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (prim (N))
{
    printf ("1\n%d\n", N);
    return 0;
}
if (prim (N - 2))
{
    printf ("2\n2 %d\n", N - 2);
    return 0;
}
int aux = N - 3;
for (int i=2; i<aux; i++)
    if (prim (i) && prim (aux - i))
    {
        printf ("3\n3 %d %d\n", i, aux - i);
        return 0;
    }

return 0;
}