#include <bits/stdc++.h>
using namespace std;

const int maxn = 200100;
const int maks = 100100;
const int logn = 18;

int n, m, a, b, q;
int tajm = 0, trid = 0, noid, cnt;

vector <vector <int> > orig;
vector <vector <int> > graf;
vector <vector <int> > ngraf;
vector <int> vi;

int id [maxn];
int distime [maxn];

vector <int> mostovi;
bool necik [maxn];
bool cik [maxn];
bool most [maxn];

int lca [logn] [maks];
int sum [logn] [maks];
int dub [maks];

int pot2 [maxn];

int rek (int cvor, int rod)
{
    int brpoziva = 0;
    distime [cvor] = tajm;
    tajm++;
    int najmdis = distime [cvor];
    for (int i = 0; i < (int) graf [cvor].size(); i++)
    {
        int novi = graf [cvor] [i];
        if (distime [novi] != -1)
        {
            if (novi != rod) najmdis = min(najmdis, distime [novi]);
        }
        else
        {
            brpoziva++;
            najmdis = min(najmdis, rek(novi, cvor));
        }
    }
    if (brpoziva == 0) return najmdis;
    if (cvor >= n && najmdis >= distime [cvor]) mostovi.push_back(cvor);
    return najmdis;
}

void ff (int cv)
{
    id [cv] = trid;
    for (int j = 0; j < orig [cv].size(); j++)
    {
        if (id [orig [cv] [j]] == -1 && !necik [orig [cv] [j]])
        {
            ff(orig [cv] [j]);
        }
    }
    return;
}

void napravi (int trcv)
{
    for (int i = 0; i < (int) ngraf [trcv].size(); i++)
    {
        int novi = ngraf [trcv] [i];
        if (dub [novi] == -1)
        {
            dub [novi] = dub [trcv] + 1;
            lca [0] [novi] = trcv;
            if (cik [trcv])
            {
                sum [0] [novi] = 1;
            }
            else
            {
                sum [0] [novi] = 0;
            }
            napravi(novi);
        }
    }
}

void ff2 (int tre)
{
    cnt++;
    id [tre] = trid;
    for (int j = 0; j < (int) graf [tre].size(); j++)
    {
        int novi = graf [tre] [j];
        if (id [novi] == -1 && !most [novi]) ff2(novi);
    }
    return;
}

int main()
{
    memset(distime, -1, sizeof distime);
    memset(necik, 0, sizeof necik);
    memset(id, -1, sizeof id);
    memset(lca, -1, sizeof lca);
    memset(sum, 0, sizeof sum);
    memset(dub, -1, sizeof dub);
    memset(most, 0, sizeof most);
    scanf("%d%d", &n, &m);
    graf.insert(graf.begin(), n + m + 10, vi);
    orig.insert(orig.begin(), n, vi);
    ngraf.insert(ngraf.begin(), n, vi);
    pot2 [0] = 1;
    for (int i = 1; i < maxn; i++) pot2 [i] = ((long long) pot2 [i - 1] * 2) % 1000000007;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        a--; b--;
        graf [a].push_back(n + i);
        graf [b].push_back(n + i);
        graf [n + i].push_back(a);
        graf [n + i].push_back(b);
        orig [a].push_back(b);
        orig [b].push_back(a);
    }

    rek(0, -1);
    /*
    for (int i = 0; i < mostovi.size(); i++)
    {
        necik [mostovi [i]] = 1;
    }
    bool z;
    for (int i = 0; i < n; i++)
    {
        z = 1;
        for (int j = 0; j < (int) graf [i].size(); j++)
        {
            if (!necik [graf [i] [j]])
            {
                z = 0;
                break;
            }
        }
        necik [i] = z;
    }
    */
    for (int i = 0; i < mostovi.size(); i++) most [mostovi [i]] = 1;
    for (int i = 0; i < n; i++)
    {
        if (id [i] != -1) continue;
        cnt = 0;
        ff2(i);
        if (cnt > 1) cik [trid] = 1;
        trid++;
    }

    for (int i = 0; i < n; i++)
    {
        trid = id [i];
        for (int j = 0; j < (int) orig [i].size(); j++)
        {
            noid = id [orig [i] [j]];
            if (noid != trid)
            {
                ngraf [noid].push_back(trid);
                //ngraf [trid].push_back(noid);
            }
        }
    }

    dub [0] = 0;
    napravi(0);

    for (int i = 1; i < logn; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (lca [i - 1] [j] != -1)
            {
                int gore = lca [i - 1] [j];
                lca [i] [j] = lca [i - 1] [gore];
                sum [i] [j] = sum [i - 1] [j] + sum [i - 1] [gore];
            }
        }
    }

    /*for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", i + 1, id [i]);
    }*/

    scanf("%d", &q);
    for (int qq = 0; qq < q; qq++)
    {
        scanf("%d%d", &a, &b);
        a--; b--;
        a = id [a];
        b = id [b];
        if (dub [a] < dub [b]) swap(a, b);
        int raz = dub[a] - dub[b];
        int ukpot = 0;
        if (cik [a]) ukpot++;
        if (cik [b]) ukpot++;
        if (raz)
        {
            int pot = 0;
            while (raz)
            {
                if (raz & 1)
                {
                    ukpot += sum [pot] [a];
                    a = lca [pot] [a];
                }
                pot++;
                raz >>= 1;
            }
        }
        if (a != b)
        {
            for (int i = logn - 1; i >= 0; i--)
            {
                if (lca [i] [a] != lca [i] [b])
                {
                    ukpot += sum [i] [a] + sum [i] [b];
                    a = lca [i] [a];
                    b = lca [i] [b];
                }
            }
            ukpot += sum [0] [a];
        }
        else if (cik [a])
        {
            ukpot--;
        }
        printf("%d\n", pot2 [ukpot]);
    }
    return 0;
}