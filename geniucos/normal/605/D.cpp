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

int nr, N, dis, a[100009], b[100009], c[100009], d[100009], dst[100009], how[100009], sol[100009];
multiset < pair < int , int > > aib[200009];
map < int , int > mp;
vector < int > norma;
queue < int > cc;

void Push_Er (int pos, pair < int, int > val, int tp)
{
    while (pos <= dis)
    {
        if (tp == 0) aib[pos].erase (aib[pos].find (val));
        else aib[pos].insert (val);
        pos += pos - (pos & (pos - 1));
    }
}

int Get (int pos, int y)
{
    while (pos)
    {
        if (!aib[pos].empty ())
        {
            pair < int, int > curr = *(aib[pos].begin ());
            if (curr.first <= y) return curr.second;
        }
        pos &= pos - 1;
    }
    return -1;
}

void Finish ()
{
    int i = N;
    while (i)
        sol[++nr] = i, i = how[i];
    printf ("%d\n", nr);
    for (int i=nr; i>=1; i--)
        printf ("%d ", sol[i]);
    printf ("\n");
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    if (a[i] == 0 && b[i] == 0) dst[i] = 1, cc.push (i);
}
///am operatii de genu sterge ceva sau ia ceva dintr-un dreptughi
///ar trebui normalizat rahat
for (int i=1; i<=N; i++)
    norma.push_back (a[i]), norma.push_back (c[i]);
sort (norma.begin (), norma.end ()), norma.erase (unique (norma.begin (), norma.end ()), norma.end ());
for (int i=0; i<norma.size (); i++)
    mp[norma[i]] = i + 1;
dis = norma.size ();
for (int i=1; i<=N; i++)
    a[i] = mp[a[i]], c[i] = mp[c[i]];
for (int i=1; i<=N; i++)
    if (dst[i] == 0) Push_Er (a[i], make_pair (b[i], i), 1);
if (dst[N])
{
    printf ("1\n%d\n", N);
    return 0;
}
while (!cc.empty ())
{
    int i = cc.front ();
    cc.pop ();
    while (1)
    {
        int j = Get (c[i], d[i]);
        if (j == -1) break;
        dst[j] = dst[i] + 1, how[j] = i; cc.push (j);
        if (dst[N] != 0)
        {
            Finish ();
            return 0;
        }
        Push_Er (a[j], make_pair (b[j], j), 0);
    }
}
printf ("-1\n");
return 0;
}