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

int N, M, K, init, fin, coef[100109], ans[100109], how[100109], ap[100109];
int Aint_Ans, Aint_A, Aint_B;
vector < pair < int , int > > v[100009];

struct nod
{
    long long hsh;
    int sum;
    nod *l, *r;

    nod ()
    {
        sum = 0, hsh = 0;
        l = r = 0;
    }

    nod (int sum, long long hsh, nod *l, nod *r)
    {
        this->sum = sum;
        this->hsh = hsh;
        this->l = l;
        this->r = r;
    }
}*full0;

void ReUp (nod *&q)
{
    q->sum = q->l->sum + q->r->sum;
    q->hsh = q->l->hsh + q->r->hsh;
}

void clone (nod *&n)
{
    nod *vechi = n;
    n = new nod (vechi->sum, vechi->hsh, vechi->l, vechi->r);
}

void QSum (nod *&q, int st, int dr, int pos)
{
    if (dr <= pos)
    {
        Aint_Ans += q->sum;
        return ;
    }
    int mij = (st + dr) >> 1;
    QSum (q->l, st, mij, pos);
    if (pos > mij) QSum (q->r, mij + 1, dr, pos);
}

void First_Equal (nod *&q, int st, int dr, int wanted)
{
    if (st == dr)
    {
        Aint_Ans = st;
        return ;
    }
    int mij = (st + dr) >> 1;
    if (q->l->sum >= wanted) First_Equal (q->l, st, mij, wanted);
    else First_Equal (q->r, mij + 1, dr, wanted - q->l->sum);
}

void Build (nod *&q0, int st, int dr)
{
    if (st == dr)
    {
        q0->sum = 1, q0->hsh = 0;
        return;
    }
    q0->l = new nod, q0->r = new nod;
    int mij = (st + dr) >> 1;
    Build (q0->l, st, mij);
    Build (q0->r, mij + 1, dr);
    ReUp (q0);
}

void Update (nod *&nou, nod *&vechi, nod *&q, int st, int dr, int x, int y)
{
    ///[x, y] = 0
    nou->l = vechi->l, nou->r = vechi->r;
    if (x <= st && dr <= y)
    {
        nou = q;
        return ;
    }
    clone (nou->l), clone (nou->r);
    int mij = (st + dr) >> 1;
    if (x <= mij) Update (nou->l, vechi->l, q->l, st, mij, x, y);
    if (y > mij) Update (nou->r, vechi->r, q->r, mij + 1, dr, x, y);
    ReUp (nou);
}

void Update_2 (nod *&nou, nod *&vechi, int st, int dr, int pos)
{
    ///pos = 1
    nou->l = vechi->l, nou->r = vechi->r;
    if (st == dr)
    {
        nou->sum = 0, nou->hsh = coef[st];
        return ;
    }
    clone (nou->l), clone (nou->r);
    int mij = (st + dr) >> 1;
    if (pos <= mij) Update_2 (nou->l, vechi->l, st, mij, pos);
    else Update_2 (nou->r, vechi->r, mij + 1, dr, pos);
    ReUp (nou);
}

void Acces (nod *&n, int st, int dr, int pos)
{
    if (st == dr)
    {
        Aint_Ans = 1 - n->sum;
        return ;
    }
    int mij = (st + dr) >> 1;
    if (pos <= mij) Acces (n->l, st, mij, pos);
    else Acces (n->r, mij + 1, dr, pos);
}

void Get_Com (nod *&a, nod *&b, int st, int dr)
{
    if (st == dr)
    {
        Aint_Ans = st;
        Aint_A = 1 - a->sum;
        Aint_B = 1 - b->sum;
        return ;
    }
    int mij = (st + dr) >> 1;
    if (a->l->hsh == b->l->hsh) Get_Com (a->r, b->r, mij + 1, dr);
    else Get_Com (a->l, b->l, st, mij);
}

struct numar
{
    nod *rad;

    void init ()
    {
        rad = full0;
    }

    numar operator + (int pos)
    {
        numar ans;
        int W;
        Aint_Ans = 0, QSum (rad, 1, K, pos), W = Aint_Ans;
        First_Equal (rad, 1, K, W);

        nod *curr = new nod;
        if (Aint_Ans + 1 <= pos) Update (curr, rad, full0, 1, K, Aint_Ans + 1, pos);
        else curr = new nod (rad->sum, rad->hsh, rad->l, rad->r);

        ans.rad = new nod;
        Update_2 (ans.rad, curr, 1, K, Aint_Ans);
        return ans;
    }

    bool operator > (const numar &other) const
    {
        Aint_Ans = 0;
        nod *q = other.rad, *q2 = rad;
        Get_Com (q2, q, 1, K);
        if (Aint_Ans) return (Aint_A > Aint_B);
        return 0;
    }

    int Get_Val ()
    {
        int sum = 0, p = 1, mod = 1e9 + 7;
        for (int i=K; i>=1; i--)
        {
            Acces (rad, 1, K, i);
            if (Aint_Ans)
            {
                sum += p;
                if (sum >= mod) sum -= mod;
            }
            p += p;
            if (p >= mod) p -= mod;
        }
        return sum;
    }

    void Print (int L)
    {
        printf ("   cu %d  ", rad->sum);
        for (int i=K - L + 1; i <= K; i++)
        {
            Acces (rad, 1, K, i);
            printf ("%d", Aint_Ans);
        }
        printf ("\n");
    }
}dist[100009];

struct dij_pack
{
    int to;
    numar v;

    dij_pack (int to, numar v)
    {
        this->to = to;
        this->v = v;
    }

    bool operator < (const dij_pack &other) const
    {
        return (v > other.v);
    }
};

priority_queue < dij_pack > PQ;

void Pre_Hash ()
{
    srand (time (0));
    for (int i=1; i<=K; i++)
        coef[i] = ((rand () % (1<<15)) << 15) + (rand () % (1<<15));
}

void Print_State (int nod)
{
    printf ("trecand prin %d, %d ", how[nod], nod), dist[nod].Print (5);
}

void Dijkstra ()
{
    for (int i=1; i<=N; i++)
        ap[i] = -1;
    ap[init] = 1, dist[init].init (), PQ.push (dij_pack (init, dist[init]));
    //int step = 0;
    while (!PQ.empty ())
    {
        dij_pack fr = PQ.top ();
        PQ.pop ();
        int nod = fr.to;
        if (ap[nod] != 1) continue;
        ap[nod] = 2;
      //  Print_State (nod);
//        if (++step >= 1) exit (0);
        for (vector < pair < int , int > > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[it->first] != 2)
        {
            numar curr = dist[nod] + it->second;
            if (ap[it->first] == -1 || dist[it->first] > curr) dist[it->first] = curr, how[it->first] = nod, ap[it->first] = 1, PQ.push (dij_pack (it->first, curr));
        }
    }
}

void Make_Path ()
{
    if (ap[fin] != 2)
    {
        printf ("-1\n");
        return ;
    }

    int nr = 0, aux = fin;
    while (aux != init)
    {
        ans[++nr] = aux;
        aux = how[aux];
    }
    ans[++nr] = init;

    printf ("%d\n%d\n", dist[fin].Get_Val (), nr);
    for (int i=nr; i>=1; i--)
        printf ("%d ", ans[i]);
    printf ("\n");
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M), K = 100051, Pre_Hash ();
while (M --)
{
    int x, y, c;
    scanf ("%d %d %d", &x, &y, &c);
    v[x].push_back (make_pair (y, K - c));
    v[y].push_back (make_pair (x, K - c));
}
scanf ("%d %d", &init, &fin);

full0 = new nod;
Build (full0, 1, K);

Dijkstra ();
Make_Path ();

return 0;
}