#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;
const int maxm = 100100;
const int logn = 18;

int n, m, k, brojac, tajm;
vector <vector <int> > graf;
vector <vector <int> > stablo;
vector <int> vi;
bool arttocka [maxn + maxm];
int rod [maxn];
int distajm [maxn + maxm];
int velicina [maxn];
int p [maxn];
int lca [logn] [maxn];
int dub [maxn];
int pbd [20];

int getrod(int koala)
{
    if (rod [koala] == koala) return koala;
    return rod [koala] = getrod(rod [koala]);
}

inline void spoji(int prvi, int drugi)
{
    int r1 = getrod(prvi), r2 = getrod(drugi);
    if (r1 == r2) return;
    if (velicina [r1] < velicina [r2]) rod [r1] = r2;
    else if (velicina [r1] > velicina [r2]) rod [r2] = r1;
    else {rod [r1] = r2; velicina [r2]++;}
    return;
}

int rek(int cvor, int odkud)
{
    tajm++;
    distajm [cvor] = tajm;
    int brgrananja = 0, minbr = distajm [cvor], maxdjece = 0;
    for (int i = 0; i < graf [cvor].size(); i++)
    {
        if (graf [cvor] [i] == odkud) continue;
        if (distajm [graf [cvor] [i]]) minbr = min(minbr, distajm [graf [cvor] [i]]);
        else
        {
            brgrananja++;
            int tr = rek(graf [cvor] [i], cvor);
            minbr = min(minbr, tr);
            maxdjece = max(maxdjece, tr);
        }
    }
    if (cvor == 0)
    {
        if (brgrananja > 1) arttocka [cvor] = 1;
    }
    else
    {
        if (maxdjece >= distajm [cvor]) arttocka [cvor] = 1;
    }
    return minbr;
}

void rek2(int cvor, int roditelj, int dubina)
{
    lca [0] [cvor] = roditelj;
    dub [cvor] = dubina;
    for (int i = 0; i < stablo [cvor].size(); i++)
    {
        if (stablo [cvor] [i] != roditelj) rek2(stablo [cvor] [i], cvor, dubina + 1);
    }
    return;
}

int main()
{
    memset(lca, -1, sizeof lca);
    memset(p, -1, sizeof p);
    pbd [0] = 1;
    for (int i = 1; i < 20; i++) pbd [i] = pbd [i - 1] * 2;
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {rod [i] = i; velicina [i] = 1;}
    graf.insert(graf.begin(), n + m, vi);
    stablo.insert(stablo.begin(), n, vi);
    brojac = n;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        a--; b--;
        graf [a].push_back(brojac);
        graf [brojac].push_back(a);
        graf [b].push_back(brojac);
        graf [brojac].push_back(b);
        brojac++;
    }
    tajm = 0;
    rek(0, -1);
    tajm = 0;
    for (int i = n; i < n + m; i++)
    {
        int c1 = graf [i] [0], c2 = graf [i] [1];
        if (arttocka [i])
        {
            continue;
            //stablo [c1].push_back(c2);
            //stablo [c2].push_back(c1);
        }
        else
        {
            spoji(c1, c2);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (p [getrod(i)] != -1) p [i] = p [getrod(i)];
        else
        {
            p [getrod(i)] = tajm;
            p [i] = tajm;
            tajm++;
        }
    }
    for (int i = n; i < n + m; i++)
    {
        int c1 = graf [i] [0], c2 = graf [i] [1];
        if (arttocka [i])
        {
            stablo [p [c1]].push_back(p [c2]);
            stablo [p [c2]].push_back(p [c1]);
        }
    }
    rek2(0, -1, 0);
    for (int i = 1; i < logn; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int pred = lca [i - 1] [j];
            if (pred != -1) lca [i] [j] = lca [i - 1] [lca [i - 1] [j]];
        }
    }
    scanf("%d", &k);
    for (int up = 0; up < k; up++)
    {
        scanf("%d%d", &a, &b);
        a--; b--;
        a = p [a];
        b = p [b];
        if (dub [a] < dub [b]) swap(a, b);
        int rj = 0, raz, pot = 0;
        raz = dub [a] - dub [b];
        while(raz)
        {
            if (raz & 1)
            {
                rj += pbd [pot];
                a = lca [pot] [a];
            }
            raz >>= 1;
            pot++;
        }
        if (a == b) {printf("%d\n", rj); continue;}
        for (int i = 17; i >= 0; i--)
        {
            if (lca [i] [a] != lca [i] [b])
            {
                a = lca [i] [a];
                b = lca [i] [b];
                rj += pbd [i] * 2;
            }
        }
        rj += 2;
        printf("%d\n", rj);
    }
    return 0;
}