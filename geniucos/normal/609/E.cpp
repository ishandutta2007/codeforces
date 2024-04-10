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

int N, M, disjoint[200009], T[200009][19], D[200009][19], niv[200009];
long long APM = 0;
vector < pair < int , int > > v[200009];
pair < int , pair < int, int > > a[200009], b[200009];

int get_set (int x)
{
    if (disjoint[x] == x) return x;
    return disjoint[x] = get_set (disjoint[x]);
}

void unite_sets (int x, int y)
{
    x = get_set (x), y = get_set (y);
    disjoint[x] = y;
}

void add_edge (int x, int y, int c)
{
    v[x].push_back (make_pair (y, c));
    v[y].push_back (make_pair (x, c));
}

void dfs (int nod, int tata)
{
    for (int i=1; (1<<i) <= niv[nod]; i++)
        T[nod][i] = T[T[nod][i - 1]][i - 1], D[nod][i] = max (D[nod][i - 1], D[T[nod][i - 1]][i - 1]);
    for (vector < pair < int , int > > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (it->first != tata)
            niv[it->first] = niv[nod] + 1, T[it->first][0] = nod, D[it->first][0] = it->second, dfs (it->first, nod);
}

int go_up (int &x, int l)
{
    int ans = 0;
    for (int i=0; (1<<i) <= l; i++)
        if (l & (1 << i)) ans = max (ans, D[x][i]), x = T[x][i];
    return ans;
}

int max_on_path (int x, int y)
{
    if (niv[x] > niv[y]) swap (x, y);
    int curr = go_up (y, niv[y] - niv[x]);
    if (x == y) return curr;
    for (int i=17; i>=0; i--)
        if ((1 << i) <= niv[x] && T[x][i] != T[y][i])
            curr = max (curr, D[x][i]), curr = max (curr, D[y][i]), x = T[x][i], y = T[y][i];
    curr = max (curr, D[x][0]), curr = max (curr, D[y][0]);
    return curr;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    disjoint[i] = i;
for (int i=1; i<=M; i++)
    scanf ("%d %d %d", &a[i].second.first, &a[i].second.second, &a[i].first), b[i] = a[i];
sort (b + 1, b + M + 1);
for (int i=1; i<=M; i++)
{
    int x = get_set (b[i].second.first), y = get_set (b[i].second.second), c = b[i].first;
    if (x != y) disjoint[x] = y, APM += c, add_edge (b[i].second.first, b[i].second.second, c);
}
dfs (1, -1);
for (int i=1; i<=M; i++)
{
    int x = a[i].second.second, y = a[i].second.first, c = a[i].first;
    if (x == T[y][0] || y == T[x][0]) printf ("%I64d\n", APM);
    else printf ("%I64d\n", APM - max_on_path (x, y) + c);
}
return 0;
}