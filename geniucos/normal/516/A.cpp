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

int N, ap[109], Ap[109];
char sir[109];

void refresh ()
{
    ap[3] += 2 * ap[9];
    ap[9] = 0;

    ap[2] += 3 * ap[8];
    ap[8] = 0;

    ap[3] += ap[6];
    ap[2] += ap[6];
    ap[6] = 0;

    ap[2] += 2 * ap[4];
    ap[4] = 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
gets (sir + 1);

for (int i=1; i<=N; i++)
{
    for (int j=sir[i]-'0'; j>=1; j--)
        ap[j] ++;
}

refresh ();

for (int i=9; i>1; i--)
    if (ap[i])
    {
        Ap[i] = ap[i];

        for (int j=i; j>=1; j--)
            ap[j] -= Ap[i];
        refresh ();

        for (int j=1; j<=Ap[i]; j++)
            printf ("%d", i);
    }
printf ("\n");

return 0;
}