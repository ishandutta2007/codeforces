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

int N, K, P, mod, ans, ap[1000009];

int pow (int a, int b, int pm)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % pm;
        a = (1LL * a * a) % pm;
    }
    return p;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &P, &K), mod = 1e9 + 7;
if (K == 0)
{
    printf ("%d\n", pow (P, P - 1, mod));
    return 0;
}
///K > 0 e practic permutare ca exitsa invers modular
ans = 1;
for (int i=0; i<P; i++)
    if (ap[i] == 0)
    {
        int j = i, L = 0;
        while (1)
        {
            ap[j] = 1, L ++;
            j = (1LL * j * K) % P;
            if (ap[j]) break;
        }
//        printf ("%d\n", L);
        if (pow (K, L, P) == 1) ans = (1LL * ans * P) % mod;
    }
printf ("%d\n", ans);

return 0;
}