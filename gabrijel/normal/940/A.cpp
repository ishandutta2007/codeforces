#include <bits/stdc++.h>
using namespace std;

int n, m, x, rj = 1e9, tr, potrj = 0;
int suma [150];
vector <int> tocke;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        tocke.push_back(x);
    }
    sort(tocke.begin(), tocke.end());
    for (int i = 0; i < tocke.size() - 1; i++)
    {
        suma [i] = tocke [i + 1] - tocke [i];
    }
    suma [tocke.size() - 1] = 0;
    for (int i = 0; i < tocke.size(); i++)
    {
        tr = 0;
        potrj = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (tr + suma [j] <= m)
            {
                tr += suma [j];
                potrj++;
            }
            else break;
        }
        if (n - potrj < rj) rj = n - potrj;
    }
    cout << rj;
    return 0;
}