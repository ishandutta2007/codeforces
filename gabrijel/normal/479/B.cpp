#include <bits/stdc++.h>
using namespace std;

set <pair <int, int> > najm;
set <pair <int, int> > najv;
vector <pair <int, int> > rj;

int n, k, trmin, maks = 0, mini = 1e9, ind, neki;

int main()
{
    int x, a, b, inda, indb;
    scanf("%d%d", &n, &k);
    ind = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        najm.insert(make_pair(x, i));
        najv.insert(make_pair(-x, i));
        if (x < mini) mini = x;
        if (x > maks) maks = x;
    }
    trmin = maks - mini;
    for (int i = 0; i < k; i++)
    {
        a = najm.begin() -> first;
        b = najv.begin() -> first;
        //cout << a << " " << -b << endl;
        inda = najm.begin() -> second;
        indb = najv.begin() -> second;
        if (a + b == 0) break;
        najm.erase(make_pair(a, inda));
        najm.erase(make_pair(-b, indb));
        najv.erase(make_pair(b, indb));
        najv.erase(make_pair(-a, inda));
        najm.insert(make_pair(a + 1, inda));
        najm.insert(make_pair(-b - 1, indb));
        najv.insert(make_pair(b + 1, indb));
        najv.insert(make_pair(-a - 1, inda));
        neki = (najv.begin() -> first) * (-1) - (najm.begin() -> first);
        if (neki < trmin) {trmin = neki; ind = i + 1;}
        rj.push_back(make_pair(indb + 1, inda + 1));
    }
    printf("%d %d\n", trmin, ind);
    for (int i = 0; i < ind; i++)
    {
        printf("%d %d\n", rj [i].first, rj [i].second);
    }
    return 0;
}