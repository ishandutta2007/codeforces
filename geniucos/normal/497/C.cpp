#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<algorithm>

using namespace std;

int N, M, nr, events[200009], a[100009], b[100009], c[100009], d[100009], K[100009], ans[100009];
set < pair < int, int > > s;

bool cmp (int x, int y)
{
    int a1, a2;
    if (x > 0) a1 = c[x];
    else a1 = a[-x];
    if (y > 0) a2 = c[y];
    else a2 = a[-y];
    if (a1 == a2)
        return x > y;
    return a1 < a2;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d %d", &a[i], &b[i]);
    events[++nr] = -i;
}
scanf ("%d", &M);
for (int i=1; i<=M; i++)
{
    scanf ("%d %d %d", &c[i], &d[i], &K[i]);
    events[++nr] = i;
}

sort (events + 1, events + nr + 1, cmp);
for (int i=1; i<=nr; i++)
{
    if (events[i] > 0)
    {
        s.insert (make_pair (d[events[i]], events[i]));
        continue;
    }
    set < pair < int , int > > :: iterator it = s.lower_bound (make_pair (b[-events[i]], -1));
    if (it == s.end ())
    {
        printf ("NO\n");
        return 0;
    }
    ans[-events[i]] = it->second;
    if (--K[it->second] == 0)
        s.erase (it);
}

printf ("YES\n");
for (int i=1; i<=N; i++)
    printf ("%d ", ans[i]);
printf ("\n");

return 0;
}