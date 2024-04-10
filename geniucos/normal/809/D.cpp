#include<bits/stdc++.h>

using namespace std;

const int INF = (1 << 30) + 1;

struct nod
{
    int val, toAdd, sz, P;
    nod *l, *r;
    nod (int _val, int _toAdd, int _sz, int _P, nod *_l, nod *_r):
        val (_val), toAdd (_toAdd), sz (_sz), P (_P), l (_l), r (_r) {}
}*nil = new nod (0, 0, 0, 0, 0, 0), *R;

int Rand () {return ((rand () & 32767) << 15) + (rand () & 32767);}
void init () {srand (time (0)), R = new nod (0, 0, 1, Rand (), nil, nil);}

void reup (nod *&n)
{
    if (n != nil)
        n->sz = n->l->sz + n->r->sz + 1;
}

void splay (nod *&n)
{
    if (n->toAdd == 0 || n == nil) return ;
    n->l->toAdd += n->toAdd, n->r->toAdd += n->toAdd;
    n->l->val += n->toAdd, n->r->val += n->toAdd;
    n->toAdd = 0;
}

void rotLeft (nod *&n)
{
    nod *t = n->l;
    n->l = t->r, t->r = n;
    reup (n), reup (t), n = t;
}

void rotRight (nod *&n)
{
    nod *t = n->r;
    n->r = t->l, t->l = n;
    reup (n), reup (t), n = t;
}

void balance (nod *&n)
{
    if (n->l->P > n->P)
        splay (n->l), rotLeft (n);
    else
    if (n->r->P > n->P)
        splay (n->r), rotRight (n);
}

void Insert (nod *&n, int pos, int val, int P)
{
    if (n == nil)
    {
        n = new nod (val, 0, 1, P, nil, nil);
        return ;
    }
    splay (n);
    if (pos <= n->l->sz) Insert (n->l, pos, val, P);
    else Insert (n->r, pos - n->l->sz - 1, val, P);
    reup (n);
    balance (n);
}

void Erase (nod *&n, int pos)
{
    splay (n);
    if (n->l->sz >= pos) Erase (n->l, pos);
    else
    if (n->l->sz + 1 < pos) Erase (n->r, pos - n->l->sz - 1);
    else
    {
        if (n->l == nil && n->r == nil)
            delete n, n = nil;
        else
        if (n->l->P > n->r->P)
            splay (n->l), rotLeft (n), Erase (n->r, pos - n->l->sz - 1);
        else
            splay (n->r), rotRight (n), Erase (n->l, pos);
    }
    reup (n);
}

void Join (nod *&n1, nod *&n2, nod *&ans)
{
    ans = new nod (0, 0, 0, 0, n1, n2);
    reup (ans), Erase (ans, n1->sz + 1);
}

void Split (nod *&ans, int pos, nod *&n1, nod *&n2)
{
    Insert (ans, pos, 0, INF);
    n1 = ans->l, n2 = ans->r;
}

int lastPositionLess (nod *&n, int val)
{
    if (n == nil) return 0;
    splay (n);
    if (n->val < val) return n->l->sz + 1 + lastPositionLess (n->r, val);
    return lastPositionLess (n->l, val);
}

void change (nod *&n, int pos, int val)
{
    splay (n);
    if (n->l->sz + 1 == pos) n->val = val;
    else
    if (n->l->sz >= pos) change (n->l, pos, val);
    else change (n->r, pos - n->l->sz - 1, val);
}

bool ndSpace = 0;
void printT (nod *&n) {if (n == nil) return ;splay (n), printT (n->l);
if (ndSpace) printf (" ");printf ("%d", n->val), ndSpace = 1, printT (n->r);}
void printTreap (nod *&n, string s) {printf ("["), ndSpace = 0, printT (n), printf ("]%s", s.c_str ());}

void testTreap ()
{
    nod *R = nil;
    int op;
    scanf ("%d\n", &op);
    while (op --)
    {
        char c;
        scanf ("%c ", &c);
        if (c == 'I')
        {
            int pos, val;
            scanf ("%d %d\n", &pos, &val);
            Insert (R, pos, val, Rand ());
        }
        else
        if (c == 'E')
        {
            int pos;
            scanf ("%d\n", &pos);
            Erase (R, pos);
        }
        printTreap (R, " = \n");
        for (int i=0; i<=R->sz; i++)
        {
            nod *r1, *r2;
            Split (R, i, r1, r2);
            printTreap (r1, " + ");
            printTreap (r2, "\n");
            Join (r1, r2, R);
        }
        printf ("\n");
    }
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

init ();
//testTreap ();
int noIntervals;
scanf ("%d", &noIntervals);
while (noIntervals --)
{
    int st, dr, i, j;
    scanf ("%d %d", &st, &dr);
    i = lastPositionLess (R, st),
    j = lastPositionLess (R, dr);
    if (i == j)
    {
        if (i == R->sz) Insert (R, i, st, Rand ());
        else change (R, i + 1, st);
//        printTreap (R, "\n");
        continue;
    }
    nod *R12, *R1, *R2, *R3;
    Split (R, j, R12, R3);
    Split (R12, i, R1, R2);
    if (R3->sz > 0) Erase (R3, 1);
    Insert (R1, R1->sz, st, Rand ());
    R2->toAdd ++, R2->val ++;
    Join (R1, R2, R12);
    Join (R12, R3, R);
  //  printTreap (R, "\n");
}
printf ("%d\n", R->sz - 1);
return 0;
}