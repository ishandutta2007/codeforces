#include <bits/stdc++.h>
using namespace std;

long long int rj = 0;
int n, tr = 0, kolko = 0;
vector <pair <int, int> > raz;
set <pair <int, int> > najm;
vector <int> nes;

int main()
{
    int x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        nes.push_back(x);
        raz.push_back(make_pair(i - x, i));
    }
    sort(raz.begin(), raz.end());
    for (int i = 0; i < raz.size(); i++)
    {
        if (tr < raz [i].first)
        {
            najm.insert(make_pair(tr, raz [i - 1].second));
            tr = raz [i].first;
        }
    }
    najm.insert(make_pair(tr, raz [raz.size() - 1].second));
    /*while(!najm.empty())
    {
        cout << (najm.begin()) -> first << " " << (najm.begin()) -> second << endl;
        najm.erase(najm.begin());
    }*/
    for (int i = 0; i < n; i++)
    {
        while (i > (najm.begin() -> second))
        {
            najm.erase(najm.begin());
        }
        if (kolko < (najm.begin() -> first)) kolko++;
        rj += i - nes [i] - kolko;
    }
    printf("%lld", rj);
    return 0;
}