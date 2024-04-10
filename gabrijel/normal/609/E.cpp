#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int c1, c2, tez;
    edge (int _c1, int _c2, int _tez)
    {
        c1 = _c1;
        c2 = _c2;
        tez = _tez;
    }
    friend bool operator < (edge A, edge B)
    {
        return A.tez < B.tez;
    }
};

vector <vector <pair <int, int> > > graf;
vector <pair <int, int> > vpii;
vector <edge> e;
vector <edge> sp;
const int maxn = 200100;
const int logn = 18;
int n, m;
int rod [maxn];
int dub [maxn];
int lca [logn] [maxn];
int maks [logn] [maxn];
bool bio [maxn];
int dubina [maxn];
long long int mst = 0;

int nadi(int cv)
{
    if (rod [cv] == cv) return cv;
    return rod [cv] = nadi(rod [cv]);
}

void spoji(int cv1, int cv2)
{
    if (dub [nadi(cv1)] > dub [nadi(cv2)])
    {
        rod [nadi(cv2)] = nadi(cv1);
    }
    else if (dub [nadi(cv2)] > dub [nadi(cv1)])
    {
        rod [nadi(cv1)] = nadi(cv2);
    }
    else
    {
        rod [nadi(cv1)] = nadi(cv2);
        dub [nadi(cv2)]++;
    }
    return;
}

void rek(int cv, int tko)
{
    bio [cv] = 1;
    dubina [cv] = dubina [tko] + 1;
    for (int i = 0; i < graf [cv].size(); i++)
    {
        if (bio [graf [cv] [i].first]) {lca [0] [cv] = graf [cv] [i].first; maks [0] [cv] = graf [cv] [i].second;}
        else rek(graf [cv] [i].first, cv);
    }
    return;
}

int main()
{
    memset(lca, -1, sizeof lca);
    memset(maks, -1, sizeof maks);
    int u, v, w;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {rod [i] = i; dub [i] = 1;}
    graf.insert(graf.begin(), n, vpii);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        u--; v--;
        e.push_back(edge(u, v, w));
    }
    sp = e;
    sort(e.begin(), e.end());
    for (int i = 0; i < e.size(); i++)
    {
        if (nadi(e [i].c1) != nadi(e [i].c2))
        {
            graf [e [i].c1].push_back(make_pair(e [i].c2, e [i].tez));
            graf [e [i].c2].push_back(make_pair(e [i].c1, e [i].tez));
            spoji(e [i].c1, e [i].c2);
            mst += e [i].tez;
        }
    }
    dubina [0] = -1;
    rek(0, 0);
    for (int i = 1; i < logn; i++)
    {
        for (int j = 0; j < n; j++)
        {
            lca [i] [j] = lca [i - 1] [lca [i - 1] [j]];
            maks [i] [j] = max(maks [i - 1] [j], maks [i - 1] [lca [i - 1] [j]]);
        }
    }
    for (int i = 0; i < sp.size(); i++)
    {
        int trmaks = -1;
        int a = sp [i].c1;
        int b = sp [i].c2;
        if (dubina [a] < dubina [b]) swap(a, b);
        int raz = dubina [a] - dubina [b];
        int pot = 0;
        while (raz)
        {
            if (raz & 1)
            {
                trmaks = max(trmaks, maks [pot] [a]);
                a = lca [pot] [a];
            }
            raz>>=1;
            pot++;
        }
        if (a == b)
        {
            printf("%lld\n", (long long) mst + sp [i].tez - trmaks);
            continue;
        }
        for (int j = logn - 1; j >= 0; j--)
        {
            if (lca [j] [a] != lca [j] [b])
            {
                trmaks = max(max(maks [j] [a], maks [j] [b]), trmaks);
                a = lca [j] [a];
                b = lca [j] [b];
            }
        }
        trmaks = max(max(trmaks, maks [0] [a]), maks [0] [b]);
        printf("%lld\n", (long long) mst + sp [i].tez - trmaks);
    }
    return 0;
}