#include<bits/stdc++.h>

using namespace std;

int nr, N, pr[109];
bool cr[109];
int kn[109];

bool query (int val)
{
    if (kn[val] > 0)
    {
        if (kn[val] == 1) return 1;
        return 0;
    }
    printf ("%d\n", val);
    fflush (stdout);
    char ans[10];
    gets (ans + 1);
    if (ans[1] == 'y') kn[val] = 1;
    else kn[val] = 2;
    if (kn[val] == 1) return 1;
    return 0;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

//scanf ("%d", &N);
for (int i=2; i<=100; i++)
    if (cr[i] == 0)
    {
        pr[++nr] = i;
        for (int j=i + i; j<=100; j+=i)
            cr[j] = 1;
    }
for (int i=1; i<=4; i++)
    if (query (pr[i]))
    {
        for (int j=i; j<=nr && pr[j] * pr[i] <= 100; j++)
        {
            int val = pr[j] * pr[i];
            if (query (val))
            {
                printf ("composite\n");
                return 0;
            }
        }
        break;
    }
printf ("prime\n");
return 0;
}