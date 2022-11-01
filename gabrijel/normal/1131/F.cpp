#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 150100;

int n;

int koji[maxn];

vector <vector <int> > svi;
vector <int> vi;

int zadnji;

int main()
{
    memset(koji, -1, sizeof koji);
    scanf("%d", &n);
    int a, b;
    REP(i, 0, n - 1)
    {
        scanf("%d%d", &a, &b);
        a--; b--;
        if(koji[a] == -1 && koji[b] == -1)
        {
            svi.push_back(vi);
            koji[a] = svi.size() - 1;
            koji[b] = svi.size() - 1;
            svi.back().push_back(a);
            svi.back().push_back(b);
            zadnji = koji[a];
        }
        else if(koji[a] == -1 || koji[b] == -1)
        {
            if(koji[a] == -1) swap(a, b);
            svi[koji[a]].push_back(b);
            koji[b] = koji[a];
            zadnji = koji[a];
        }
        else
        {
            int sa = svi[koji[a]].size();
            int sb = svi[koji[b]].size();
            if(sa >= sb) swap(a, b);
            int c = koji[a];
            REP(j, 0, (int)svi[c].size())
            {
                svi[koji[b]].push_back(svi[c][j]);
                koji[svi[c][j]] = koji[b];
            }
            zadnji = koji[a];
        }
    }
    /*REP(i, 0, n)
    {
        if(svi[i].size() == n)
        {
            REP(j, 0, (int)svi[i].size())
            {
                printf("%d ", svi[i][j] + 1);
            }
            return 0;
        }
    }*/
    REP(i, 0, (int)svi[zadnji].size())
    {
        printf("%d ", svi[zadnji][i] + 1);
    }
    return 0;
}