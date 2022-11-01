#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define REPN(i, a, b) for(int i = a; i >= b; i--)

const int maxn = 100100;
const int inf = 1e9 + 100;

int n;

long long int rj = 0;

int par;

vector <vector <int> > graf;
vector <int> vi;

int suma[maxn];

bool bio[maxn];

int mini[maxn];

void provjeri(int cvor, int maxi, bool nep)
{
    bio[cvor] = 1;
    if(nep)
    {
        if(suma[cvor] != -1)
        {
            cout << -1 << endl;
            exit(0);
        }
        REP(i, 0, (int)graf[cvor].size())
        {
            int dalje = graf[cvor][i];
            if(!bio[dalje])
            {
                provjeri(dalje, maxi, !nep);
            }
        }
        return;
    }
    if(suma[cvor] < maxi)
    {
        cout << -1 << endl;
        exit(0);
    }
    REP(i, 0, (int)graf[cvor].size())
    {
        int salji = graf[cvor][i];
        if(!bio[salji])
        {
            provjeri(salji, suma[cvor], !nep);
        }
    }
    return;
}

void rek(int cvor, int trsuma)
{
    bio[cvor] = 1;
    if(suma[cvor] != -1)
    {
        rj += suma[cvor] - trsuma;
        REP(i, 0, (int)graf[cvor].size())
        {
            int dalje = graf[cvor][i];
            if(!bio[dalje])
            {
                rek(dalje, max(suma[cvor], trsuma));
            }
        }
    }
    else
    {
        if(mini[cvor] != inf)
        {
            rj += mini[cvor] - trsuma;
            REP(i, 0, (int)graf[cvor].size())
            {
                int dalje = graf[cvor][i];
                if(!bio[dalje])
                {
                    rek(dalje, max(suma[cvor], mini[cvor]));
                }
            }
        }
        else
        {
            REP(i, 0, (int)graf[cvor].size())
            {
                int dalje = graf[cvor][i];
                if(!bio[dalje])
                {
                    rek(dalje, max(suma[cvor], trsuma));
                }
            }
        }
    }
    return;
}

int dajmini(int cvor)
{
    bio[cvor] = 1;
    if(suma[cvor] != -1) mini[cvor] = suma[cvor];
    REP(i, 0, (int)graf[cvor].size())
    {
        int dalje = graf[cvor][i];
        if(!bio[dalje])
        {
            mini[cvor] = min(mini[cvor], dajmini(dalje));
        }
    }
    return mini[cvor];
}

int main()
{
    cin >> n;
    REP(i, 0, n) mini[i] = inf;
    graf.insert(graf.begin(), n, vi);
    REP(i, 1, n)
    {
        cin >> par;
        par--;
        graf[i].push_back(par);
        graf[par].push_back(i);
    }
    REP(i, 0, n)
    {
        scanf("%d", &suma[i]);
    }
    provjeri(0, 0, 0);
    memset(bio, 0, sizeof bio);
    dajmini(0);
    memset(bio, 0, sizeof bio);
    rek(0, 0);
    cout << rj << endl;
    //REP(i, 0, n) cout << mini[i] << endl;
    return 0;
}