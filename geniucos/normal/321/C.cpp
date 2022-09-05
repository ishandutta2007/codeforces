#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int D, centru, n, a, b, sus[100009], down[100009], up[100009], ap[100009];
char C[100009];

vector < int > Fii[100009], v[100009], h;

void dfs1 (int nod)
{
    h.push_back(nod);
    ap[nod] = 1;
    down[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin(); it != v[nod].end(); it++)
        if (ap[*it] == 0 && C[*it] == 0)
        {
            Fii [nod] . push_back (*it);
            up [*it] = up[nod] + 1;
            dfs1 (*it);
            down[nod] = max (down[*it] + 1, down[nod]);
        }
}

void dfs2 (int nod, int &Ce, int &mi)
{
    int Mx = 0;
    for (vector < int > :: iterator it = Fii[nod].begin(); it != Fii[nod].end(); it++)
    {
        if (Mx) sus[*it] = max (up[*it], Mx+2);
        else sus[*it] = up[*it];
        Mx = max (Mx, down[*it]);
    }
    Mx=0;
    for (vector < int > :: reverse_iterator it = Fii[nod].rbegin(); it != Fii[nod].rend(); it++)
    {
        if (Mx) sus[*it] = max (sus[*it], max (up[*it], Mx+2));
        else sus[*it] = max ( sus[*it], up[*it]);
        Mx = max (Mx, down[*it]);
    }
    for (vector < int > :: iterator it = Fii[nod].begin(); it != Fii[nod].end(); it++)
    {
        sus[*it] = max(sus[*it], sus[nod] + 1);
        dfs2 (*it, Ce, mi);
    }
    int V_nod = max(sus[nod], down[nod]);
    if (V_nod < mi) mi = V_nod, Ce = nod;
}

void compute (int nod, int deep)
{
    D=1000000;
    h.clear();
    up[nod] = 1;
    dfs1 (nod);
    sus[nod] = 0;
    dfs2 (nod, centru, D);

    C[centru] = 'A' + deep;

    //////sterg informatii
    for (vector < int > :: iterator it = h.begin(); it != h.end(); it++)
    {
        ap[*it] = 0;
        Fii[*it] . clear();
    }
    int Cer = centru;
    for (vector < int > :: iterator it = v[Cer].begin(); it != v[Cer].end(); it++)
        if (C[*it] == 0) compute (*it, deep+1);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &n);
for (int i=1; i<n; i++)
{
    scanf ("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
}
compute (1, 0);
for (int i=1; i<=n; i++)
    printf("%c ", C[i]);
printf("\n");
return 0;
}