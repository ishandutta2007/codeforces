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

int nr, p, u, N, M, a[200009], b[200009], R[200009], T[200009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), b[i] = a[i];
while (M --)
{
    int t, r;
    scanf ("%d %d", &t, &r);
    while (nr && R[nr] <= r) nr --;
    T[++nr] = t, R[nr] = r;
}
sort (a + 1, a + R[1] + 1), p = 1, u = R[1], R[nr + 1] = 0;
for (int i=1; i<=nr; i++)
{
    int pos = R[i];
    while (pos > R[i + 1])
    {
        if (T[i] == 1) b[pos --] = a[u --];
        else b[pos --] = a[p ++];
    }
}
for (int i=1; i<=N; i++)
    printf ("%d ", b[i]);
printf ("\n");
return 0;
}