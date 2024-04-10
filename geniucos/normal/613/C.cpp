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

int N, sigma, ap[109], ap2[109], ans[100009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &sigma);
for (int i=0; i<sigma; i++)
    scanf ("%d", &ap[i]), N += ap[i];
for (int i=N; i>=1; i--)
    if (N % i == 0)
    {
        int ok = 1;
        for (int j=0; j<sigma; j++)
            if (ap[j] % i != 0)
            {
                ok = 0;
                break;
            }
        if (ok == 0) continue;
        int L = N / i;
        for (int j=0; j<sigma; j++)
            ap2[j] = ap[j] / i;
        if (i & 1)
        {
            int cnt_imp = 0, imp = 0;
            for (int j=0; j<sigma; j++)
                if (ap2[j] & 1) cnt_imp ++, imp = j;
            if (cnt_imp > 1) continue;
            ans[L / 2 + 1] = imp, ap2[imp] --;
            int k = 0;
            for (int j=1; j<=L / 2; j++)
            {
                while (ap2[k] == 0) k ++;
                ap2[k] -= 2, ans[j] = ans[L - j + 1] = k;
            }
        }
        else
        {
            L = 0;
            for (int j=0; j<sigma; j++)
                while (ap2[j] --)
                    ans[++L] = j;
        }
        printf ("%d\n", i);
        while (i --)
        {
            if (i & 1)
                for (int j=1; j<=L; j++)
                    printf ("%c", (char) ans[j] + 'a');
            else
                for (int j=L; j>=1; j--)
                    printf ("%c", (char) ans[j] + 'a');
        }
        printf ("\n");
        return 0;
    }
printf ("0\n");
for (int i=0; i<sigma; i++)
    while (ap[i] --) printf ("%c", (char) 'a' + i);
printf ("\n");

return 0;
}