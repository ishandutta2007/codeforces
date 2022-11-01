#include <bits/stdc++.h>
using namespace std;

int n, m, rj = 0;
int fen [100100];
int niz [100100];
int rast [100100];
int pad [100100];
int kojirast [100100];
int kojipad [100100];
vector <int> najmanji;
vector <int>::iterator it;

void ubaci(int poz, int sta)
{
    for (int j = poz; j < 100050; j += j&-j)
    {
        fen [j] += sta;
    }
    return;
}

int get(int poz)
{
    int ret = 0;
    for (int j = poz; j > 0; j -= j&-j)
    {
        ret += fen [j];
    }
    return ret;
}

int main()
{
    int l, r;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &l, &r);
        ubaci(l, 1);
        ubaci(r + 1, -1);
    }
    for (int i = 0; i < m; i++)
    {
        niz [i] = get(i + 1);
    }
    najmanji.clear();
    for (int i = 0; i < m; i++)
    {
        it = upper_bound(najmanji.begin(), najmanji.end(), niz [i]);
        if (it == najmanji.end())
        {
            najmanji.push_back(niz [i]);
        }
        else *it = niz [i];
        rast [i] = najmanji.size();
    }
    najmanji.clear();
    for (int i = m - 1; i >= 0; i--)
    {
        it = upper_bound(najmanji.begin(), najmanji.end(), niz [i]);
        if (it == najmanji.end())
        {
            najmanji.push_back(niz [i]);
        }
        else *it = niz [i];
        pad [i] = najmanji.size();
    }
    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)
        {
            rj = max(rj, rast [i]);
        }
        else rj = max(rj, rast [i] + pad [i + 1]);
    }
    printf("%d", rj);
    return 0;
}