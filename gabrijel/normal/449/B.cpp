#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;

const long long int inf = 1e15;
int n, m, k;
vector <vector <pair <int, int> > > graf;
vector <pair <int, int> > vpii;
set <pair <long long int, int> > najb;
vector <long long int> dist;
vector <bool> bio;
vector <int> pruge;
vector <int> biosus;

int main()
{
    int u, v, x, s, y, rj = 0;
    cin >> n >> m >> k;
    dist.insert(dist.begin(), n, inf);
    bio.insert(bio.begin(), n, 0);
    graf.insert(graf.begin(), n, vpii);
    pruge.insert(pruge.begin(), n, 0);
    biosus.insert(biosus.begin(), n, 0);
    for (int postavi = 0; postavi < n; postavi++) najb.insert(make_pair(inf, postavi));
    for (int upis1 = 0; upis1 < m; upis1++)
    {
        scanf("%d%d%d", &u, &v, &x);
        u--; v--;
        graf [u].push_back(make_pair(v, x));
        graf [v].push_back(make_pair(u, x));
    }
    for (int upis2 = 0; upis2 < k; upis2++)
    {
        scanf("%d%d", &s, &y);
        s--;
        graf [0].push_back(make_pair(s, y));
        pruge [s]++;
    }
    dist [0] = 0;
    najb.erase(make_pair(inf, 0));
    najb.insert(make_pair(0, 0));
    for (int i = 0; i < n - 1; i++)
    {
        int cvor = (najb.begin()) -> second;
        int udaljenost = (najb.begin()) -> first;
        najb.erase(najb.begin());
        bio [cvor] = 1;
        for (int j = 0; j < graf [cvor].size(); j++)
        {
            if (!bio [graf [cvor] [j].first])
            {
                int potcvor = graf [cvor] [j].first;
                int potudaljenost = graf [cvor] [j].second;
                if (dist [potcvor] > udaljenost + potudaljenost)
                {
                    najb.erase(make_pair(dist [potcvor], potcvor));
                    najb.insert(make_pair(udaljenost + potudaljenost, potcvor));
                    dist [potcvor] = udaljenost + potudaljenost;
                }
            }
        }
    }
    for (int l = 0; l < graf [0].size(); l++)
    {
        bool brisi = 0;
        int susjed = graf [0] [l].first;
        if (biosus [susjed]) continue;
        biosus [susjed] = 1;
        for (int p = 0; p < graf [susjed].size(); p++)
        {
            int susjedsusjeda = graf [susjed] [p].first;
            long long int udaljenostsusjeda = graf [susjed] [p].second;
            if (dist [susjed] == dist [susjedsusjeda] + udaljenostsusjeda)
            {
                brisi = 1;
                break;
            }
        }
        if (brisi) rj += pruge [susjed];
        else rj += pruge [susjed] - 1;
        //cout << pruge [susjed] << " " << susjed << endl;
    }
    cout << rj;
    return 0;
}