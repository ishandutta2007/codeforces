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

int N;
long long maxi, a[109][109];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
    {
        if (i == 1 || j == 1) a[i][j] = 1LL;
        else a[i][j] = a[i-1][j] + a[i][j-1];
        if (a[i][j] > maxi)
            maxi = a[i][j];
    }
printf ("%I64d\n", maxi);
return 0;
}