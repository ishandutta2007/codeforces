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

int N, M, K, nr, ans[100009], aint[1600009];

struct event
{
    int st, dr, from, time;

    event ()
    {
        st = dr = 0;
        from = time = 0;
    }

    event (int st, int dr, int from, int time)
    {
        this->time = time;
        this->from = from;
        this->st = st;
        this->dr = dr;
    }

    bool operator < (const event &other) const
    {
        if (time == other.time) return (from < other.from);
        return (time < other.time);
    }
}ev[200009];

map < int , int > mp;
vector < int > values;

void Push (int val)
{
    values.push_back (val);
}

void Read (int &x);

void Read_All ()
{
    Read (N), Read (M);
    for (int i=1; i<=N; i++)
    {
        int x, y, t;
        Read (x), Read (y), Read (t), Push (x), Push (y);
        ev[++nr] = event (x, y, i, t);
    }

    for (int i=1; i<=M; i++)
    {
        int x, y, t;
        Read (x), Read (y), Read (t), Push (x), Push (y);
        ev[++nr] = event (x, y, -i, t);
    }
}

void Normalize ()
{
    sort (values.begin (), values.end ());
    values.erase (unique (values.begin (), values.end ()), values.end ());
    for (vector < int > :: iterator it = values.begin (); it != values.end (); it ++)
        mp[*it] = ++K;
    for (int i=1; i<=nr; i++)
        ev[i].st = mp[ev[i].st], ev[i].dr = mp[ev[i].dr];
}

void Print ()
{
    for (int i=1; i<=M; i++)
    {
        if (ans[i]) printf ("%d ", ans[i]);
        else printf ("-1 ");
    }
    printf ("\n");
}

priority_queue < pair < int , int > > PQ[400009];///cel mai mare L

void Update (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        aint[nod] = val;
        return ;
    }
    int mij = (st + dr) >> 1;
    if (pos <= mij) Update (nod << 1, st, mij, pos, val);
    else Update ((nod << 1) + 1, mij + 1, dr, pos, val);
    aint[nod] = max (aint[nod << 1], aint[(nod << 1) + 1]);
}

void Query (int nod, int st, int dr, int L, int R, int v_ans)
{
    if (aint[nod] < L) return ;
    if (st == dr)
    {
        while (!PQ[st].empty ())
        {
            pair < int , int > curr = PQ[st].top ();
            if (curr.first < L) break;
            PQ[st].pop ();
            ans[curr.second] = v_ans;
        }
        if (PQ[st].empty ()) aint[nod] = 0;
        else aint[nod] = ((PQ[st].top ()).first);
        return ;
    }
    int mij = (st + dr) >> 1;
    if (L <= mij) Query (nod << 1, st, mij, L, R, v_ans);
    if (R > mij) Query ((nod << 1) + 1, mij + 1, dr, L, R, v_ans);
    aint[nod] = max (aint[nod << 1], aint[(nod << 1) + 1]);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read_All ();
Normalize ();
sort (ev + 1, ev + nr + 1);
for (int i=1; i<=nr; i++)
{
    if (ev[i].from < 0)
    {
        if ( PQ[ ev[i].dr ].empty () || (PQ[ ev[i].dr ].top ()).first < ev[i].st ) Update (1, 1, K, ev[i].dr, ev[i].st);
        PQ[ev[i].dr].push (make_pair (ev[i].st, -ev[i].from));
        continue;
    }
    Query (1, 1, K, ev[i].st, ev[i].dr, ev[i].from);
}
Print ();

return 0;
}

#define maxl 100000
int pos = maxl - 1;
char sir[maxl];

void Next ()
{
    if (++pos == maxl)
        fread (sir, 1, maxl, stdin), pos = 0;
}

void Read (int &x)
{
    for (;sir[pos] < '0' || sir[pos] > '9'; Next ()) ;
    for (x = 0; sir[pos] >= '0' && sir[pos] <= '9'; Next ()) x = x * 10 + sir[pos] - '0';
}