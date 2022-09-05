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

long long a, b, ans[1009];
int nr;
char cr[1009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %I64d", &a, &b);
while (a != b)
{
    if (a > b)
    {
        if (a % b == 0) ans[++nr] = a / b - 1, cr[nr] = 'A', a = b;
        else ans[++nr] = a / b, cr[nr] = 'A', a %= b;
    }
    else
    {
        if (b % a == 0) ans[++nr] = b / a - 1, cr[nr] = 'B', b = a;
        else ans[++nr] = b / a, cr[nr] = 'B', b %= a;
    }
}
if (a != 1) printf ("Impossible\n");
else
{
    for (int i=1; i<=nr; i++)
        printf ("%I64d%c", ans[i], cr[i]);
    printf ("\n");
}
return 0;
}