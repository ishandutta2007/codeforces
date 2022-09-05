#include<bits/stdc++.h>

using namespace std;

int N, M;
char sir[200009];

int ord[] = {2, 0, 1, 7};
struct state
{
    int v[5][5];
}aint[800009], ansQ;

state operator + (state a, state b)
{
    state c;
    for (int i=0; i<5; i++)
        for (int j=i; j<5; j++)
        {
            c.v[i][j] = N + 3;
            for (int k=i; k<=j; k++)
                if (a.v[i][k] + b.v[k][j] < c.v[i][j])
                    c.v[i][j] = a.v[i][k] + b.v[k][j];
        }
    return c;
}

void Build (int nod, int st, int dr)
{
    if (st == dr)
    {
        int val = sir[st] - '0';
        for (int i=0; i<5; i++)
            for (int j=i; j<5; j++)
                aint[nod].v[i][j] = N + 3;
        for (int i=0; i<5; i++)
        {
            if (i < 4 && val == ord[i])
            {
                aint[nod].v[i][i] = 1;
                aint[nod].v[i][i + 1] = 0;
            }
            else aint[nod].v[i][i] = (i >= 3 && val == 6);
        }
        return ;
    }
    int mij = (st + dr) >> 1;
    Build (nod << 1, st, mij);
    Build (nod << 1 | 1, mij + 1, dr);
    aint[nod] = aint[nod << 1] + aint[nod << 1 | 1];
}

void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (x == st) ansQ = aint[nod];
        else ansQ = ansQ + aint[nod];
        return ;
    }
    int mij = (st + dr) >> 1;
    if (x <= mij) Query (nod << 1, st, mij, x, y);
    if (mij < y) Query (nod << 1 | 1, mij + 1, dr, x, y);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
gets (sir + 1);
Build (1, 1, N);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y), Query (1, 1, N, x, y);
    if (ansQ.v[0][4] > N) printf ("-1\n");
    else printf ("%d\n", ansQ.v[0][4]);
}
return 0;
}