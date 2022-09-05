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

int a, b, c, S;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n%d %d %d", &S, &a, &b, &c);
if (a + b + c == 0)
{
    printf ("0.0 0.0 0.0\n");
    return 0;
}
double k = (double)S / ((double)a + b + c);
printf ("%.15lf %.15lf %.15lf", (double)k * a, (double)k * b, (double)k * c);

return 0;
}