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

int sol, A[109], N, ap[109];
char sir[109][109];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);

for (int i=1; i<=N; i++)
    gets (sir[i] + 1);

for (int i=1; i<=N; i++)
    scanf ("%d", &A[i]);

bool ok = 1;
while (ok)
{
    ok = 0;
    for (int i=1; i<=N; i++)
        if (A[i] == 0)
        {
            ok = 1;
            sol ++;
            ap[i] = 1;
            for (int j=1; j<=N; j++)
                if (sir[i][j] == '1')
                    A[j] --;
            break;
        }
}

printf ("%d\n", sol);
for (int i=1; i<=N; i++)
    if (ap[i])
        printf ("%d ", i);
printf ("\n");

return 0;
}