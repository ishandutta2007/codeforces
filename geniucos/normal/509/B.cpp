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

int N, K, ap[1009], sol[1009][1009], unde[1009];
pair < int , int > a[1009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
scanf ("%d", &K);

for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i].first);
    a[i].second = i;
}

sort (a+1, a+N+1);

if (a[N].first - a[1].first > K)
{
    printf ("NO\n");
    return 0;
}

for (int i=1; i<=N; i++)
    unde[a[i].second] = i;

sol[1][K] = a[1].first;

for (int i=2; i<=N; i++)
{
    int dif = a[i].first - a[1].first;
    for (int j=1; j<=K; j++)
        sol[i][j] = sol[1][j] + (j <= dif);
}

printf ("YES\n");
for (int i=1; i<=N; i++)
{
    for (int j=1; j<=K; j++)
        ap[j] = sol[unde[i]][j];

    for (int j=1; j<=K; j++)
        for (int p=1; p<=ap[j]; p++)
            printf ("%d ", j);
    printf ("\n");
}

return 0;
}