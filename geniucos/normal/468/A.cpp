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

int N, beg;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N <= 3)
{
    printf ("NO\n");
    return 0;
}

printf ("YES\n");
if (N & 1)
{
    printf ("5 * 2 = 10\n");
    printf ("10 - 3 = 7\n");
    printf ("7 - 1 = 6\n");
    printf ("4 * 6 = 24\n");
    beg = 6;
}
else
{
    printf ("1 * 2 = 2\n");
    printf ("2 * 3 = 6\n");
    printf ("6 * 4 = 24\n");
    beg = 5;
}

for (int i=beg; i<=N; i+=2)
{
    printf ("%d - %d = 1\n", i + 1, i);
    printf ("24 * 1 = 24\n");
}

return 0;
}