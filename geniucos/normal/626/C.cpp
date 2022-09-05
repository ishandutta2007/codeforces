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

int N, M;
char ap[12000009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    ap[2 * i] = 1;
for (int i=1; i<=M; i++)
    ap[3 * i] |= 2;
int val = N * 2;
if (M * 3 > val) val = M * 3;
int v1 = N * 2, v2 = M * 3;
for (int i=6; i<=val; i+=6)
    if (ap[i] > 2)
    {
        if (v1 + 2 < v2 + 3)
        {
            v1 += 2, ap[v1] |= 1;
            if (v1 > val) val = v1;
        }
        else
        {
            v2 += 3, ap[v2] |= 2;
            if (v2 > val) val = v2;
        }
    }
printf ("%d\n", val);

return 0;
}