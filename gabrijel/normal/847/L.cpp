#include <bits/stdc++.h>
using namespace std;

//#define __ << " " <<

const int maxn = 1100;

int n;

bool moze = 1;

bool obraden [maxn];

bool prov [maxn];

int bro, kotr, trbr, tr, trpoz, br, brve = 0;

vector <vector <vector <int> > > lis;
vector <vector <int> > vvi;
vector <int> trv;

vector <int> brlis;
vector <vector <int> > brele;

queue <int> listovi;

vector <pair <int, int> > rj;

vector <vector <int> > graf;
vector <int> vi;

int mat [maxn] [maxn];

void dfs(int cvor)
{
    br++;
    prov [cvor] = 1;
    for (int j = 0; j < graf [cvor].size(); j++)
    {
        if (!prov [graf [cvor] [j]]) dfs(graf [cvor] [j]);
    }
    return;
}

int main()
{
    scanf("%d", &n);

    graf.insert(graf.begin(), n, vi);
    brlis.insert(brlis.begin(), n, 0);
    brele.insert(brele.begin(), n, trv);

    for (int i = 0; i < n; i++)
    {
        lis.push_back(vvi);
        bro = 0;
        while (bro < n - 1)
        {
            trv.clear();
            scanf("%d:", &kotr);
            for (int j = 0; j < kotr - 1; j++)
            {
                scanf("%d,", &trbr);
                trbr--;
                mat [trbr] [i] = lis [i].size();
                bro++;
                trv.push_back(trbr);
            }
            scanf("%d", &trbr);
            trbr--;
            mat [trbr] [i] = lis [i].size();
            bro++;
            trv.push_back(trbr);
            if (bro < n - 1) scanf("-");
            lis [i].push_back(trv);
            brele [i].push_back(lis [i].back().size());
            brlis [i]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (lis [i].size() == 1) listovi.push(i);
    }
    while (!listovi.empty())
    {
        tr = listovi.front();
        listovi.pop();
        obraden [tr] = 1;
        for (int i = 0; i < n; i++)
        {
            if (obraden [i]) continue;
            trpoz = mat [tr] [i];
            //cout __ tr __ i __ trpoz << endl;
            brele [i] [trpoz]--;
            if (brele [i] [trpoz] == 0)
            {
                brlis [i]--;
                if (brlis [i] == 1) listovi.push(i);
                rj.push_back(make_pair(tr, i));
                graf [tr].push_back(i);
                graf [i].push_back(tr);
                brve++;
                memset(prov, 0, sizeof prov);
                prov [i] = 1;
                br = 0;
                dfs(tr);
                if (br != lis [i] [trpoz].size()) moze = 0;
                else
                {
                    for (int j = 0; j < lis [i] [trpoz].size(); j++)
                    {
                        if (!prov [lis [i] [trpoz] [j]]) {moze = 0; break;}
                    }
                }
            }
        }
    }
    if (!moze || brve != n - 1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", n - 1);
        for (int i = 0; i < rj.size(); i++)
        {
            printf("%d %d\n", rj [i].first + 1, rj [i].second + 1);
        }
    }
    /*for (int i = 0; i < lis.size(); i++)
    {
        for (int j = 0; j < lis [i].size(); j++)
        {
            for (int k = 0; k < lis [i] [j].size(); k++)
            {
                printf("%d", lis [i] [j] [k]);
            }
            printf(" ");
        }
        printf("\n");
    }*/
    return 0;
}