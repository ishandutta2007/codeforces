#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int n_split, N, M, a[100009], split[10009], split_dr[10009];
int arb[400009][61];

void refresh (int nod, int mij)
{
    for (int i=0; i<60; i++)
    {
        int t = arb[nod<<1][i] + 1 + ((arb[nod<<1][i] + i) % a[mij] == 0);
        arb[nod][i] = t  + arb[(nod<<1)+1][(t+i) % 60];
    }
}

void build (int nod, int st, int dr)
{
    if (st == dr)
        return ;
    int mij = (st + dr) >> 1;
    build (nod << 1, st, mij);
    build ((nod<<1) + 1, mij + 1, dr);
    refresh (nod, mij);
}

void U (int nod, int st, int dr, int poz)
{
    if (st == dr)
        return ;
    int mij = (st + dr) >> 1;
    if (poz <= mij) U (nod<<1, st, mij, poz);
    else U ((nod<<1) + 1, mij +1, dr, poz);
    refresh (nod, mij);
}

void make_split (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        split[++n_split] = nod;
        split_dr[n_split] = dr;
        return ;
    }
    int mij = (st + dr) >> 1;
    if (x <= mij)
        make_split (nod<<1, st, mij, x, y);
    if (y > mij)
        make_split ((nod<<1) + 1, mij +1, dr, x, y);
}
int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
build (1, 1, N);
scanf ("%d\n", &M);
while (M)
{
    M --;
    char tip;
    int x, y;
    scanf ("%c %d %d\n", &tip, &x, &y);
    if (tip == 'A')
    {
        n_split = 0;
        make_split (1, 1, N, x, y);
        int T = 0;
        for (int i=1; i<n_split; i++)
        {
            int t2 = T + arb[split[i]][T%60] + 1 + ((arb[split[i]][T%60] + T) % a[split_dr[i]] == 0);
            T = t2;
        }
        T += arb[split[n_split]][T%60];
        if (y == N + 1)
        {
            if (T % a[N] == 0) T ++;
            T ++;
        }
        printf ("%d\n", T);
    }
    else
    {
        a[x] = y;
        U (1, 1, N, x);
    }
}

return 0;
}