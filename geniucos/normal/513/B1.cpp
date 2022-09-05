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

int nr, N, M, maxi, a[109], ap[109];

void back (int poz)
{
    if (nr >= M)
        return;
    if (poz == N + 1)
    {
        int sum = 0;
        for (int i=1; i<=N; i++)
        {
            int mini;
            for (int j=i; j<=N; j++)
            {
                if (i == j) mini = a[i];
                else
                if (a[j] < mini)
                    mini = a[j];
                sum += mini;
            }
        }

        if (sum >= maxi)
        {
            maxi = sum;
            nr ++;
            //printf ("%d:\n", sum);
            if (nr == M)
            {
                for (int i=1; i<=N; i++)
                    printf ("%d ", a[i]);
                printf ("\n");
            }
        }

        return ;
    }

    for (int i=1; i<=N; i++)
        if (ap[i] == 0)
        {
            a[poz] = i;
            ap[i] = 1;
            back (poz + 1);
            ap[i] = 0;
        }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);

back (1);

return 0;
}