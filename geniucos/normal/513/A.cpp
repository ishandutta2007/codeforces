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

int n1, n2, k1, k2;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &n1, &n2, &k1, &k2);
if (n1 <= n2)
    printf ("Second\n");
else
    printf ("First");

return 0;
}