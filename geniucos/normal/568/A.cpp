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

int P, Q;
bool cr[10000009];

bool pal (int val)
{
    if (val % 10 == 0) return 0;
    int ras = 0, aux = val;
    while (val) ras = ras * 10 + val % 10, val /= 10;
    return (ras == aux);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int maxi = -1, pr = 0, pa = 0;
scanf ("%d %d", &P, &Q);
for (int i=1; i<=10000000; i++)
{
    if (i != 1 && cr[i] == 0 && 1LL * i * i <= 10000000)
    {
        for (int j=i * i; j<=10000000; j+=i)
            cr[j] = 1;
    }
    if (i != 1 && cr[i] == 0) pr ++;
    if (pal (i)) pa ++;
    if (1LL * Q * pr <= 1LL * P * pa)
        maxi = i;
}
if (maxi == -1 || maxi == 10000000) printf ("Palindromic tree is better than splay tree\n");
else printf ("%d\n", maxi);
return 0;
}