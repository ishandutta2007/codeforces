#include<bits/stdc++.h>

using namespace std;

int N, M;
char sir[1000009];
string s[100009];
pair < int, int > lzy[8000009];

void split (int nod, int f1, int f2)
{
    if (lzy[nod].first == 0 && lzy[nod].second == 0) return ;
    lzy[f1] = lzy[f2] = lzy[nod];
    lzy[nod] = {0, 0};
}

void UpdateSegm (int nod, int st, int dr, int x, int y, pair < int, int > val)
{
    if (x <= st && dr <= y)
    {
        lzy[nod] = val;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, f1, f2);
    if (x <= mij) UpdateSegm (f1, st, mij, x, y, val);
    if (mij < y) UpdateSegm (f2, mij + 1, dr, x, y, val);
}

void printAns (int nod, int st, int dr)
{
    if (st == dr)
    {
        if (lzy[nod].first == 0 && lzy[nod].second == 0) printf ("a");
        else printf ("%c", s[lzy[nod].first][st - lzy[nod].second]);
        if (st == N)
        {
            printf ("\n");
            exit (0);
        }
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, f1, f2);
    printAns (f1, st, mij);
    printAns (f2, mij + 1, dr);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int Tests, id = 0;
scanf ("%d\n", &Tests), M = 2000000;
while (Tests --)
{
    int L, nn;
    scanf ("%s", sir), s[++id] = sir, L = s[id].length ();
    scanf ("%d", &nn);
    while (nn --)
    {
        int P;
        scanf ("%d", &P);
        if (P + L - 1 > N)
            N = P + L - 1;
        UpdateSegm (1, 1, M, P, P + L - 1, {id, P});
    }
    scanf ("\n");
}
printAns (1, 1, M);

return 0;
}