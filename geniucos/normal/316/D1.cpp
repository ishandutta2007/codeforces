#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<algorithm>

using namespace std;

int N, sol, mod, many[109], a[109], init[109], ap[109], P[109], Ap[109];

void back (int pos)
{
    if (pos == N + 1)
    {
        bool ok = 1;
        for (int i=1; i<=N; i++)
            ap[i] = 0;
        for (int i=1; i<=N; i++)
            if (ap[i] == 0)
            {
                int j = i, nr1 = 0;
                while (1)
                {
                    if (a[j] == 1)
                        nr1 ++;
                    ap[j] = 1;
                    j = P[j];
                    if (ap[j])
                        break;
                }
                if (nr1 > 2)
                    ok = 0;
            }
        if (ok)
        {
            sol ++;
            if (sol == mod)
                sol = 0;
        }
        return ;
    }
    for (int i=1; i<=N; i++)
        if (Ap[i] == 0)
            Ap[i] = 1, P[pos] = i, back (pos + 1), Ap[i] = 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

mod = 1e9 + 7;
int doi = 0;
scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    if (a[i] == 2)
        doi ++;
}
if (doi == N)
{
    int sol = 1;
    for (int i=1; i<=N; i++)
        sol = (1LL * sol * i) % mod;
    printf ("%d\n", sol);
    return 0;
}

back (1);
printf ("%d\n", sol);

return 0;
}