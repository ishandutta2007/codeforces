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

int tot, N, t[3009], mx[3009], L[3009];
bool ok = 1;
pair < int , pair < int , int > > edge[3009];

int tata (int x)
{
    if (t[x] == x) return x;
    return t[x] = tata (t[x]);
}

void unite (int x, int y)
{
    x = tata (x), y = tata (y);
    L[x] += L[y];
    mx[x] += mx[y];
    if (tot - mx[x] < L[x]) ok = 0;
    t[y] = x;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N == 1)
{
    printf ("0\n");
    return 0;
}
for (int i=1; i<N; i++)
    scanf ("%d %d %d", &edge[i].second.first, &edge[i].second.second, &edge[i].first);
sort (edge + 1, edge + N);

for (int i=1; i<=N; i++)
{
    scanf ("%d", &mx[i]);
    t[i] = i;
    L[i] = 1;
    tot += mx[i];
}
ok = 1;
int ans = edge[1].first;
for (int i=1; i<N;)
{
    int j = i;
    while (edge[j].first == edge[i].first && j < N)
        unite (edge[j].second.first, edge[j].second.second), j++;
    if (ok) ans = edge[j].first;
    i = j;
}
printf ("%d\n", ans);
return 0;
}