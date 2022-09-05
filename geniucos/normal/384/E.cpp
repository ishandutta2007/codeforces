#include<cstdio>
#include<vector>

using namespace std;

int tip, nr, N, M, Q[200009], arb[2][800009], sol[2], a[200009], ap[200009], st[200009], dr[200009], niv[200009];

vector < int > v[200009];

void dfs (int nod)
{
    ap[nod] = 1;
    Q[++nr] = nod;
    st[nod] = nr;
    for (vector < int > :: iterator it = v[nod].begin(); it != v[nod].end(); it++)
        if (ap[*it] == 0)
        {
            niv[*it] = niv[nod] ^ 1;
            dfs (*it);
        }
    dr[nod] = nr;
}

void split (int nod)
{
    for (int lin = 0; lin < 2; lin++)
    {
        arb[lin][nod<<1] += arb[lin][nod];
        arb[lin][(nod<<1)+1] += arb[lin][nod];
        arb[lin][nod] = 0;
    }
}

void U (int nod, int st, int dr, int x, int y, int lin, int val)
{
    if (x <= st && dr <= y)
    {
        arb[lin][nod] += val;
        return ;
    }
    split (nod);
    int mij = (st + dr) >> 1;
    if (x <= mij) U (nod<<1, st, mij, x, y, lin, val);
    if (y > mij) U ((nod<<1)+1, mij+1, dr, x, y, lin, val);
}

void Qr (int nod, int st, int dr, int poz)
{
    if (st == dr)
    {
        sol[0] = arb[0][nod];
        sol[1] = arb[1][nod];
        return ;
    }
    split (nod);
    int mij = (st + dr) >> 1;
    if (poz <= mij) Qr (nod<<1, st, mij, poz);
    else Qr ( (nod<<1)+1, mij+1, dr, poz);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
scanf ("%d", &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);

for (int i=1; i<N; i++)
{
    int X, Y;
    scanf ("%d %d", &X, &Y);
    v[X].push_back(Y);
    v[Y].push_back(X);
}

dfs (1);

while (M)
{
    M --;
    scanf ("%d", &tip);
    if (tip == 1)
    {
        int x, val;
        scanf ("%d %d", &x, &val);
        U (1, 1, nr, st[x], dr[x], niv[x], val);
    }
    else
    {
        int x;
        scanf ("%d", &x);
        Qr (1, 1, nr, st[x]);
        printf ("%d\n", a[x] + sol[niv[x]] - sol[niv[x]^1]);
    }
}
return 0;
}