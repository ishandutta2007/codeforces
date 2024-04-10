#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define REPN(i, a, b) for(int i = a; i >= b; i--)

const int maxn = 100100;
const int logn = 18;
const double eps = 1e-15;

int n, m;

int x;
long long int y;
int a, b;

int tko, skim;

double n1, n2;

struct plan
{
    int px = 0;
    long long int py = 0;
    int ind = -1;
    plan(int _px, long long int _py, int _ind)
    {
        px = _px;
        py = _py;
        ind = _ind;
    }
    plan(){}
};

vector <pair <int, long long int> > svi;

vector <vector <int> > graf;
vector <int> vi;

vector <plan> stek;

int dub[maxn];
int lca[logn][maxn];

bool bio[maxn];

void dfs(int cvor, int rod, int trdub)
{
    dub[cvor] = trdub;
    bio[cvor] = 1;
    lca[0][cvor] = rod;
    REP(i, 0, (int)graf[cvor].size())
    {
        int dalje = graf[cvor][i];
        if(!bio[dalje]) dfs(dalje, cvor, trdub + 1);
    }
}

void build()
{
    int an;
    REP(i, 1, logn)
    {
        REP(j, 0, n)
        {
            an = lca[i - 1][j];
            if(an == -1) lca[i][j] = -1;
            else lca[i][j] = lca[i - 1][an];
        }
    }
    return;
}

int que(int ocva, int ocvb)
{
    int cva = ocva, cvb = ocvb;
    int duba = dub[cva];
    int dubb = dub[cvb];
    if(duba < dubb)
    {
        swap(duba, dubb);
        swap(cva, cvb);
    }
    int raz = duba - dubb;
    int pot = 0;
    while(raz)
    {
        if(raz & 1)
        {
            cva = lca[pot][cva];
        }
        raz >>= 1;
        pot++;
    }
    if(cva == cvb) return n - cva;
    REPN(j, logn - 1, 0)
    {
        if(lca[j][cva] != lca[j][cvb])
        {
            cva = lca[j][cva];
            cvb = lca[j][cvb];
        }
    }
    return n - lca[0][cva];
}

double dajnagib(int nx, long long int ny)
{
    double ret;
    ret = (double) ((double) (ny - y) / ((long long) nx - x));
    return ret;
}

int main()
{
    scanf("%d", &n);
    graf.insert(graf.begin(), n, vi);
    REP(i, 0, n)
    {
        scanf("%d%lld", &x, &y);
        svi.push_back(make_pair(x, y));
    }
    stek.push_back(plan(svi.back().first, svi.back().second, 0));
    REPN(i, (int)svi.size() - 2, 0)
    {
        x = svi[i].first;
        y = svi[i].second;
        while(stek.size() > 1)
        {
            n1 = dajnagib(stek.back().px, stek.back().py);
            n2 = dajnagib(stek[stek.size() - 2].px, stek[stek.size() - 2].py);
            if(n1 + eps < n2)
            {
                stek.pop_back();
            }
            else
            {
                break;
            }
        }
        skim = stek.back().ind;
        stek.push_back(plan(x, y, svi.size() - i - 1));
        tko = stek.back().ind;
        graf[tko].push_back(skim);
        graf[skim].push_back(tko);
    }
    dfs(0, -1, 0);
    build();
    scanf("%d", &m);
    REP(i, 0, m)
    {
        scanf("%d%d", &a, &b);
        a = n - a; b = n - b;
        printf("%d ", que(a, b));
    }
    return 0;
}