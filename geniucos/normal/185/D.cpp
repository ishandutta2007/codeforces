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

int T, k, mod;
long long l, r;

int pow (int a, long long b, int mod)
{
    int p = 1;
    for (int i=0; (1LL << i) <= b; i++)
    {
        if (b & (1LL << i))
            p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

int kla2laE (int k, long long E)
{
    ///return k ^ (2 ^ E) % mod
    if (k % mod == 0) return 0;
    int ans = pow (k, pow (2, E, mod - 1), mod);
    return ans;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &T);
while (T --)
{
    scanf ("%d %I64d %I64d %d", &k, &l, &r, &mod);
    if (l == r)
    {
        printf ("%d\n", (kla2laE (k, l) + 1) % mod);
        continue;
    }

    if (k % 2 == 0)
    {
        ///gcd = 1;
        if (kla2laE (k, l) == 1)
        {
            ///k ^ (2 ^ l) == 1 mod -> k ^ (2 ^ l) + 1 == 2 mod
            ///(k ^ (2 ^ l) + 1) * (k ^ (2 ^ l) - 1) = k ^ (2 ^ (l + 1)) - 1 = 0 * 2 = 0 -> k ^ (2 ^ (l + 1)) = 2 mod
            ///inductively k ^ (2 ^ p) + 1 = 2 mod for any p >= l
            ///product = 2 ^ (r - l + 1)
            printf ("%d\n", pow (2, r - l + 1, mod));
            continue;
        }
        int sus = kla2laE (k, r + 1), jos = kla2laE (k, l);
        sus --;
        if (sus < 0) sus += mod;
        jos --;
        if (jos < 0) jos += mod;
        printf ("%d\n", (1LL * sus * pow (jos, mod - 2, mod)) % mod);
        continue;
    }
    ///gcd between any two is 2 -> LCM = product / (2 ^ (r - l))
    if (mod == 2)
    {
        ///LCM contains at least one 2
        printf ("0\n");
        continue;
    }
    if (kla2laE (k, l) == 1)
    {
        ///same thinking
        ///product = 2 ^ (r - l + 1)
        printf ("%d\n", 2 % mod);
        continue;
    }
    int sus = kla2laE (k, r + 1), jos = kla2laE (k, l);
    sus --;
    if (sus < 0) sus += mod;
    jos --;
    if (jos < 0) jos += mod;
    jos = (1LL * jos * pow (2, r - l, mod)) % mod;
    printf ("%d\n", (1LL * sus * pow (jos, mod - 2, mod)) % mod);
    continue;
}

return 0;
}