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

int N, a[100009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    while (a[i] % 2 == 0) a[i] /= 2;
    while (a[i] % 3 == 0) a[i] /= 3;
}
sort (a + 1, a + N + 1);
if (a[1] == a[N]) printf ("Yes\n");
else printf ("No\n");

return 0;
}