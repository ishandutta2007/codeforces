#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int N, a[309];

char pot[309][309];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
scanf ("\n");

for (int i=1; i<=N; i++)
    gets (pot[i] + 1);

for (int k=1; k<=N; k++)
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if (pot[i][k] == '1' && pot[k][j] == '1')
                pot[i][j] = '1';

for (int i=1; i<=N; i++)
{
    int mini, p = i;
    mini = a[i];
    for (int j=i+1; j<=N; j++)
        if ((pot[i][j] == '1' || pot[j][i] == '1') && a[j] < mini)
        {
            mini = a[j];
            p = j;
        }
    int aux = a[i];
    a[i] = a[p];
    a[p] = aux;
}

for (int i=1; i<=N; i++)
    printf ("%d ", a[i]);
printf ("\n");

return 0;
}