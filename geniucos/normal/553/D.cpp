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

int how, nr, N, M, K, nod[100009], tot[100009], ap[100009], V[100009];
vector < int > v[100009];

struct fractie
{
    int a, b, x;
    fractie (int a, int b, int ce)
    {
        this->a = a;
        this->b = b;
        this->x = ce;
    }
    bool operator < (const fractie &other) const
    {
        return 1LL * a * other.b < 1LL * other.a * b;
    }
};

priority_queue < fractie > PQ;

void scot (int nod)
{
    ap[nod] = 0;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it])
        {
            tot[*it] ++;
            PQ.push (fractie (tot[*it], v[*it].size (), *it));
        }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &K);
for (int i=1; i<=K; i++)
    scanf ("%d", &nod[i]);
while (M)
{
    M --;
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}

for (int i=1; i<=N; i++)
    if (v[i].empty ())
    {
        printf ("1\n%d\n", i);
        return 0;
    }

for (int i=1; i<=N; i++)
    ap[i] = 1, tot[i] = 0, PQ.push (fractie (0, v[i].size (), i));

for (int i=1; i<=K; i++)
    scot (nod[i]), V[++nr] = nod[i];

fractie ans = fractie (-1, 0, 0);
while (!PQ.empty ())
{
    fractie xx = fractie (-1, 0, 0);
    while (!PQ.empty ())
    {
        xx = PQ.top ();
        PQ.pop ();
        if (tot[xx.x] != xx.a || ap[xx.x] == 0)
            continue;
        break;
    }
    if (xx.a == -1 || tot[xx.x] != xx.a || ap[xx.x] == 0)
        break;
    if (xx < ans || ans.a == -1)
        ans = xx, how = nr;
    scot (xx.x);
    V[++nr] = xx.x;
}

printf ("%d\n", nr - how );
for (int i=how + 1; i<=nr; i++)
    printf ("%d ", V[i]);
printf ("\n");

return 0;
}