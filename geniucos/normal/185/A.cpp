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

int mod;
long long N;

int pow (int a, long long b)
{
    int p = 1;
    for (int i=0; (1LL << i) <= b; i++)
    {
        if (b & (1LL << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d", &N), mod = 1e9 + 7;
if (N == 0)
{
    printf ("1\n");
    return 0;
}
///up - down = 2 ^ N
///up + down = 4 ^ N
///2 * up = 2 ^ N + 4 ^ N
///up = 2 ^ (N - 1) + 4 ^ (N - 1) * 2;
long long v = (long long)pow (2, N - 1) + 2LL * pow (4, N - 1);
int ans = v % mod;
printf ("%d\n", ans);

return 0;
}