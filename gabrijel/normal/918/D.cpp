#include <bits/stdc++.h>
using namespace std;

vector <vector <pair <int, int> > > graf;
int n, m;
bool bio [105] [105] [30] [2];
bool pob [105] [105] [30] [2];

bool rek (int x, int y, int slovo, int potez)
{
    if (bio [x] [y] [slovo] [potez]) return pob [x] [y] [slovo] [potez];
    bio [x] [y] [slovo] [potez] = 1;
    if (potez)
    {
        for (int k = 0; k < graf [y].size(); k++)
        {
            if (slovo <= graf [y] [k].second)
                if (!rek (x, graf [y] [k].first, graf [y] [k].second, potez ^ 1))
                    return pob [x] [y] [slovo] [potez] = 1;
        }
        return pob [x] [y] [slovo] [potez] = 0;
    }
    else
    {
        for (int k = 0; k < graf [x].size(); k++)
        {
            if (slovo <= graf [x] [k].second)
                if (!rek (graf [x] [k].first, y, graf [x] [k].second, potez ^ 1))
                    return pob [x] [y] [slovo] [potez] = 1;
        }
        return pob [x] [y] [slovo] [potez] = 0;
    }
}

int main()
{
    int a, b;
    char c;
    scanf("%d%d", &n, &m);

    vector <pair <int, int> > vpii;
    graf.insert(graf.begin(), n, vpii);

    for (int up = 0; up < m; up++)
    {
        scanf("%d %d %c", &a, &b, &c);
        a--; b--;
        graf [a].push_back(make_pair(b, c - 'a' + 1));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rek (i, j, 0, 0);
            if (pob [i] [j] [0] [0]) printf("A");
            else printf("B");
        }
        printf("\n");
    }
    /*rek (1, 2, 0, 0);
    cout << pob [2] [2] [1] [1] << endl;
    cout << pob [1] [2] [0] [0] << endl;*/
    return 0;
}