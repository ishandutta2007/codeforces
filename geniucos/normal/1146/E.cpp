#include<bits/stdc++.h>

using namespace std;

int N, M, a[100009];
const bool DBG = 0;

pair < bool, bool > compose (pair < bool, bool > aa, pair < bool, bool > bb)
{
    ///first apply a (all i go to a(i))
    ///then apply b (all b(i) go to a(i))
    int a[2], b[2];
    a[0] = aa.first, a[1] = aa.second, b[0] = bb.first, b[1] = bb.second;
    return {b[a[0]], b[a[1]]};
}

const int MX = 100000;
pair < bool, bool > aint[280009];
const pair < bool, bool > id = {0, 1};
void build (int nod, int st, int dr)
{
    aint[nod] = id;
    if (st == dr)
        return ;
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    build (f1, st, mij);
    build (f2, mij + 1, dr);
}

void lazy (int nod, int f1, int f2)
{
    if (aint[nod].first != id.first || aint[nod].second != id.second)
    {
        aint[f1] = compose (aint[f1], aint[nod]);
        aint[f2] = compose (aint[f2], aint[nod]);
        aint[nod] = id;
    }
}

void update (int nod, int st, int dr, int x, int y, pair < bool, bool > curr)
{
    if (DBG && nod == 1)
        printf ("[%d, %d] with [%d, %d]\n", x, y, curr.first, curr.second);
    if (x <= st && dr <= y)
    {
        aint[nod] = compose (aint[nod], curr);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    lazy (nod, f1, f2);
    if (x <= mij) update (f1, st, mij, x, y, curr);
    if (mij < y) update (f2, mij + 1, dr, x, y, curr);
}
pair < bool, bool > fin[100009];

void push (int nod, int st, int dr)
{
    if (st == dr)
    {
        fin[st] = aint[nod];
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    lazy (nod, f1, f2);
    push (f1, st, mij);
    push (f2, mij + 1, dr);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
scanf ("\n");
build (1, 1, MX);///aint refers to +i (1 refers to -, 0 refers to staying the same)
while (M --)
{
    char c;
    int x;
    scanf ("%c %d\n", &c, &x);
    if (DBG)
        printf ("%c %d\n", c, x);
    if (c == '>')
        x ++;
    ///now we want to update y < x
    if (x == 0) aint[1] = compose (aint[1], {0, 0});///negative turns to positive and that's all
    else
    if (x > 0)
    {
        if (x >= 2)
            update (1, 1, MX, 1, x - 1, {1, 0}); ///positives to negative, and negative to positive
        update (1, 1, MX, x, MX, {0, 0});///negative turns to positive and that's all
    }
    else
    if (x < 0)
    {
        int y = -x;
        ///-z < -y <=> z > y
        if (y < MX)
            update (1, 1, MX, y + 1, MX, {0, 0});///negative to positive
    }
    if (c == '>')
    {
        if (DBG)
            printf ("all [%d, %d]\n", 1, 0);
        aint[1] = compose (aint[1], {1, 0});///change sign to everyone after updating the complement
    }
}
push (1, 1, MX);
for (int i=1; i<=N; i++)
{
    if (a[i] > 0)
    {
        if (fin[a[i]].first)
            a[i] = -a[i];
    }
    else
    if (a[i] < 0)
    {
        if (!fin[-a[i]].second)
            a[i] = -a[i];
    }
    printf ("%d%c", a[i], " \n"[i == N]);
}
return 0;
}