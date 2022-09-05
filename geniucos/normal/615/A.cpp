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

int N, M, ap[109];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (N --)
{
    int l, x;
    scanf ("%d", &l);
    while (l --) scanf ("%d", &x), ap[x] = 1;
}
for (int i=1; i<=M; i++)
    if (ap[i] == 0)
    {
        printf ("NO\n");
        return 0;
    }
printf ("YES\n");

return 0;
}