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

int nr, N, t[2509], a[2509][2509];
pair < int, pair < int, int > > v[3200009];

void Answer (bool oke)
{
    if (oke) printf ("MAGIC\n");
    else printf ("NOT MAGIC\n");
    exit (0);
}

int tata (int nod)
{
    if (t[nod] == nod) return nod;
    return t[nod] = tata (t[nod]);
}

void unite (int x, int y)
{
    x = tata (x), y = tata (y);
    if (x == y) return ;
    t[x] = y;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
    {
        scanf ("%d", &a[i][j]);
        if (i == j && a[i][j] != 0) Answer (0);
    }
for (int i=1; i<=N; i++)
    for (int j=1; j<i; j++)
    {
        if (a[i][j] != a[j][i]) Answer (0);
        v[++nr] = make_pair (a[i][j], make_pair (i, j));
    }
for (int i=1; i<=N; i++)
    t[i] = i;
sort (v + 1, v + nr + 1);
for (int i=1; i<=nr; i++)
{
    int j;
    for (j=i; j<=nr; j++)
        if (v[j].first != v[i].first) break;
    j --;
    for (int k=i; k<=j; k++)
        if (tata (v[k].second.first) == tata (v[k].second.second)) Answer (0);
    for (int k=i; k<=j; k++)
        unite (v[k].second.first, v[k].second.second);
    i = j;
}
Answer (1);
return 0;
}