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

int N, K, dp[10009];
map < int , int > mp;

int sprg (int i)
{
    if (i <= 10) return dp[i];
    if (i & 1) return 0;
    if (mp.count (i)) return mp[i];
    ///
    int val = 1;///1 << dp[i - 1] i - 1 impar deci 0
    val |= (1 << sprg (i / 2));
    for (int k=0; k<=10; k++)
        if ((val & (1 << k)) == 0)
        {
            mp[i] = k;
            return k;
        }
}

int sg (int x)
{
    if (K % 2 == 0)
    {
        if (x == 2) return 2;
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (x & 1) return 0;
        return 1;
    }
    return sprg (x);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

///sg[0] = 0
///daca e impar, sg[x] = 1/0 in functie de x - 1
///daca e par, pot inlocui i = 2 * x cu k gramezi de x
///in primul rand, conteaza doar paritatea lui k
///daca k e par atunci

for (int i=1; i<=1; i++)
{
    dp[0] = 0;
    for (int j=1; j<=1000; j++)
    {
        if (j & 1)
        {
            if (dp[j - 1] > 0) dp[j] = 0;
            else dp[j] = 1;
        }
        else
        {
            int val = 0;
            if (i == 0) val |= 1;///K par
            else val |= (1 << dp[j / 2]);
            val |= (1 << dp[j - 1]);
            for (int k=0; k<10; k++)
                if ((val & (1 << k)) == 0)
                {
                    dp[j] = k;
                    break;
                }
        }
    }
/*    for (int j=1; j<=1000; j++)
        if (dp[j] == 2)
        {
            printf ("%d\n", j);
        }*/

/*    for (int j=1; j<=10; j++)
        printf ("%d\n", dp[j]);
    printf ("impar:\n\n\n\n");*/
}
/*K = 1;
for (int j=1; j<=1000; j++)
    if (dp[j] != sprg (j))
    {
        printf ("rahat %d\n", j);
        return 0;
    }
return 0;*/

scanf ("%d %d", &N, &K);
int sol = 0;
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    sol ^= sg (x);
}
if (sol) printf ("Kevin\n");
else printf ("Nicky\n");

return 0;
}