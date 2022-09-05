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

int a, b;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &a, &b);
if (b == 10)
{
    if (a == 1)
    {
        printf ("-1\n");
        return 0;
    }
    printf ("1");
    for (int i=1; i<a; i++)
        printf ("0");
    printf ("\n");
    return 0;
}
printf ("%d", b);
for (int i=1; i<a; i++)
        printf ("0");
    printf ("\n");

return 0;
}