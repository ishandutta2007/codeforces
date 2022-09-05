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

int N, P[100009], ap[100009], Nr, nr, v[100009], pos[100009], L[100009];
pair < int, int > sz[100009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &P[i]);
/*for (int i=1; i<=100; i++)
{
    for (int j=1; j<=N; j++)
        printf ("%2d ", a[j]);
    printf ("\n");
    for (int j=1; j<=N; j++)
        a[j] = P[a[j]];
}*/
/*ciclu de cel mult 2*/

for (int i=1; i<=N; i++)
    if (ap[i] == 0)
    {
        int j = i, nr = 1;
        v[1] = j;
        ap[j] = 1;
        while (1)
        {
            j = P[j];
            if (ap[j]) break;
            ap[j] = 1;
            v[++nr] = j;
        }
        Nr ++;
        for (int j=1; j<=nr; j++)
            ap[v[j]] = Nr, pos[v[j]] = j;
        L[Nr] = nr;
        sz[Nr].first = nr, sz[Nr].second = Nr;
    }
sort (sz + 1, sz + Nr + 1);
if (sz[1].first > 2)
{
    printf ("NO\n");
    return 0;
}
for (int i=2; i<=Nr; i++)
    if (sz[i].first % sz[1].first != 0)
    {
        printf ("NO\n");
        return 0;
    }
printf ("YES\n");
if (sz[1].first == 1)
{
    int nod;
    for (int i=1; i<=N; i++)
        if (ap[i] == sz[1].second) nod = i;
    for (int i=1; i<=N; i++)
        if (ap[i] != sz[1].second)
            printf ("%d %d\n", nod, i);
    return 0;
}
int nod1 = -1, nod2 = -1;
for (int i=1; i<=N; i++)
    if (ap[i] == sz[1].second)
    {
        if (nod1 == -1) nod1 = i;
        else nod2 = i;
    }
printf ("%d %d\n", nod1, nod2);
for (int i=1; i<=N; i++)
{
    if (ap[i] != sz[1].second && pos[i] % 2 == 1)
        printf ("%d %d\n", i, nod1);
    else
    if (ap[i] != sz[1].second)
        printf ("%d %d\n", i, nod2);
}
return 0;
}