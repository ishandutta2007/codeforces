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

int N, x[1000009], y[1000009], a[1000009];

bool cmp (int i, int j)
{
    if (x[i] / 1000 == x[j] / 1000)
    {
        if ((x[i] / 1000) & 1) return (y[i] < y[j]);
        return (y[i] > y[j]);
    }
    return x[i] < x[j];
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &x[i], &y[i]), a[i] = i;
sort (a + 1, a + N + 1, cmp);
/*for (int i=1; i<=N; i++)
    printf ("%d %d\n", a[i].first - a[i].second, a[i].second);*/
for (int i=1; i<=N; i++)
    printf ("%d ", a[i]);

return 0;
}