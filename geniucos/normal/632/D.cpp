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

int N, M, maxi, hw, a[1000009], ap[1000009], cnt[1000009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    if (a[i] <= M) ap[a[i]] ++;
}
for (int i=1; i<=M; i++)
    for (int j=i; j<=M; j+=i)
        cnt[j] += ap[i];
for (int i=1; i<=M; i++)
    if (cnt[i] > maxi) maxi = cnt[i], hw = i;
if (maxi == 0)
{
    printf ("1 0\n");
    return 0;
}
printf ("%d %d\n", hw, maxi);
for (int i=1; i<=N; i++)
    if (hw % a[i] == 0) printf ("%d ", i);
printf ("\n");
return 0;
}