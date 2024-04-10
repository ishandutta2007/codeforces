#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int aintn, Answer, N, M, n_q, tot, nr, l[400009], L[400009], R[400009], st[400009], dr[400009], Q[400009], T[400009], A[400009];
char sir[400009], curr[400009];

vector < int > fii[400009];

struct nod
{
    int cod;
    nod *phi, *urm[27];
    nod ()
    {
        memset (urm, 0, sizeof (urm));
        phi = 0;
        cod = 0;
    }
}*Rad, *q[200009], *lst[200009];

void dfs (nod *&R)
{
    R->cod = ++tot;
    for (int i=0; i<27; i++)
        if (R->urm[i] != 0)
            dfs (R->urm[i]);
}

void df2 (nod *&R)
{
    T[R->cod] = R->phi->cod;
    for (int i=0; i<27; i++)
        if (R->urm[i] != 0)
            df2 (R->urm[i]);
}

void dfs3 (int nod)
{
    Q[++n_q] = nod, st[nod] = n_q;
    for (vector < int > :: iterator it = fii[nod].begin (); it != fii[nod].end (); it ++)
        dfs3 (*it);
    dr[nod] = n_q;
}

struct nod2
{
    int sum, l, r;

    nod2 (int sum, int l, int r)
    {
        this->sum = sum;
        this->l = l;
        this->r = r;
    }

    nod2()
    {
        sum = 0;
        l = r = 0;
    }
} Arb[8000009];
int arb[400009], gol;

int newnod2 ()
{
    return ++aintn;
}

void build (int R, int st, int dr)
{
    if (st == dr)
    {
        Arb[R].l = Arb[R].r = 0;
        Arb[R].sum = 0;
        return ;
    }
    int mij = (st + dr) >> 1;
    Arb[R].l = newnod2 ();
    Arb[R].r = newnod2 ();
    build (Arb[R].l, st, mij);
    build (Arb[R].r, mij + 1, dr);
    Arb[R].sum = Arb[Arb[R].l].sum + Arb[Arb[R].r].sum;
}

void U (int nod_nou, int nod_vechi, int st, int dr, int poz, int val)
{
    if (st == dr)
    {
        Arb[nod_nou].l = Arb[nod_nou].r = 0;
        Arb[nod_nou].sum = Arb[nod_vechi].sum + val;
        return ;
    }

    int mij = (st + dr) >> 1;

    if (poz <= mij)
    {
        Arb[nod_nou].r = Arb[nod_vechi].r;
        Arb[nod_nou].l = newnod2 ();
        U (Arb[nod_nou].l, Arb[nod_vechi].l, st, mij, poz, val);
    }
    else
    {
        Arb[nod_nou].l = Arb[nod_vechi].l;
        Arb[nod_nou].r = newnod2 ();
        U (Arb[nod_nou].r, Arb[nod_vechi].r, mij + 1, dr, poz, val);
    }

    Arb[nod_nou].sum = Arb[Arb[nod_nou].l].sum + Arb[Arb[nod_nou].r].sum;
}

void Query (int nod_left, int nod_right, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        Answer += Arb[nod_right].sum - Arb[nod_left].sum;
        return ;
    }

    int mij = (st + dr) >> 1;
    if (mij >= x)
        Query (Arb[nod_left].l, Arb[nod_right].l, st, mij, x, y);
    if (mij < y)
        Query (Arb[nod_left].r, Arb[nod_right].r, mij + 1, dr, x, y);
}

void cit (int &x);

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
Rad = new nod;
for (int i=1; i<=N; i++)
{
    gets (curr + 1), l[i] = strlen (curr + 1);
    if (i != 1)
        sir[++nr] = 26;
    L[i] = nr;
    nod *q = Rad;
    for (int j=1; j<=l[i]; j++)
    {
        sir[++nr] = curr[j] - 'a';
        if (q->urm[sir[nr]] == 0)
            q->urm[sir[nr]] = new nod;
        q = q->urm[sir[nr]];
    }
    lst[i] = q;
    R[i] = nr;
}

dfs (Rad);
n_q = 0;
Rad->phi = Rad;
for (int i=0; i<27; i++)
    if (Rad->urm[i] != 0)
        q[++n_q] = Rad->urm[i], Rad->urm[i]->phi = Rad;

for (int i=1; i<=n_q; i++)
    for (int j=0; j<27; j++)
        if (q[i]->urm[j] != 0)
        {
            q[++n_q] = q[i]->urm[j];
            nod *aux = q[i]->phi;
            while (aux != Rad && aux->urm[j] == 0)
                aux = aux->phi;
            if (aux->urm[j] != 0)
                aux = aux->urm[j];
            q[n_q]->phi = aux;
        }

nod *aux = Rad;
for (int i=1; i<=nr; i++)
{
    while (aux != Rad && aux->urm[sir[i]] == 0)
        aux = aux->phi;
    if (aux->urm[sir[i]] != 0)
        aux = aux->urm[sir[i]];
    A[i] = aux->cod;
}

df2 (Rad);
for (int i=2; i<=tot; i++)
    fii[T[i]].push_back (i);
n_q = 0;
dfs3 (1);

/*for (int i=1; i<=n_q; i++)
    printf ("%d ", Q[i]);
printf ("\n");
for (int i=1; i<=N; i++)
    printf ("%d %d\n", st[lst[i]->cod], dr[lst[i]->cod]);
for (int i=1; i<=nr; i++)
    printf ("%d ", A[i]);
printf ("\n");*/

gol = newnod2();
build (gol, 1, n_q);
arb[0] = gol;
for (int i=1; i<=nr; i++)
{
    arb[i] = newnod2 ();
    U (arb[i], arb[i-1], 1, n_q, st[A[i]], 1);
}

while (M)
{
    M --;
    int St, Dr, K;
    //scanf ("%d %d %d", &St, &Dr, &K);
    cit (St), cit (Dr), cit (K);
    Answer = 0;
    if (L[St] + l[K] - 1 <= R[Dr])
        Query (arb[L[St] + l[K] - 1], arb[R[Dr]], 1, n_q, st[lst[K]->cod], dr[lst[K]->cod]);
    printf ("%d\n", Answer);
}
return 0;
}

#define Maxl 1000000
int pos = Maxl - 1;
char sr[Maxl];

void Next ()
{
    if (++pos == Maxl)
        fread (sr, 1, Maxl, stdin), pos = 0;
}

void cit (int &x)
{
    for (; sr[pos] < '0' || sr[pos] > '9'; Next ())
        ;
    for (x = 0; sr[pos] >= '0' && sr[pos] <= '9'; Next ())
        x = x * 10 + sr[pos] - '0';
}