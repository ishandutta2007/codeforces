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

int N, l, A, B, nr, v[101];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
while (N --)
{
    scanf ("%d", &l);
    for (int i=1; i<=l; i++)
    {
        int ai;
        scanf ("%d", &ai);
        if (i <= l / 2) A += ai;
        else
        if (i >= l - l / 2 + 1) B += ai;
        else v[++nr] = ai;
    }
}
sort (v + 1, v + nr + 1), reverse (v + 1, v + nr + 1);
for (int i=1; i<=nr; i++)
    if (i & 1) A += v[i];
    else B += v[i];
printf ("%d %d\n", A, B);

return 0;
}