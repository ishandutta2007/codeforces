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

int N, mod;

int pw (int a, int b)
{
    int p = 1;
    while (b--)
        p = (1LL * p * a) % mod;
    return p;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), mod = 1e9 + 7;
int ans = pw (3, 3 * N) - pw (7, N);
if (ans < 0) ans += mod;
printf ("%d\n", ans);
return 0;
}