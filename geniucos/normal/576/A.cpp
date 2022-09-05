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

int N, nr, cr[10009], v[10009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=2; i<=N; i++)
    if (cr[i] == 0)
    {
        int aux = 1;
        while (aux <= N)
        {
            aux *= i;
            if (aux > N) break;
            v[++nr] = aux;
        }
        for (int j=i + i; j<=N; j+=i)
            cr[j] = 1;
    }
printf ("%d\n", nr);
sort (v + 1, v + nr + 1);
for (int i=1; i<=nr; i++)
    printf ("%d ", v[i]);
printf ("\n");
return 0;
}