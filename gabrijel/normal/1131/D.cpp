#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 1100;
const int inf = 1e9 + 100;

int n, m;

char mat[maxn][maxn];

int rod[2 * maxn];

vector <vector <int> > graf;
vector <int> vi;

bool bio[2 * maxn];
bool urek[2 * maxn];

int rj[2 * maxn];

int dajrod(int x)
{
    if(rod[x] == x) return x;
    return rod[x] = dajrod(rod[x]);
}

void spoji(int a, int b)
{
    int roda = dajrod(a);
    int rodb = dajrod(b);
    rod[roda] = rodb;
    return;
}

void rek(int cvor)
{
    int mojerj = 0;
    urek[cvor] = 1;
    if(!graf[cvor].size())
    {
        rj[cvor] = 1;
    }
    else
    {
        REP(i, 0, (int)graf[cvor].size())
        {
            int novi = dajrod(graf[cvor][i]);
            if(urek[novi])
            {
                cout << "No" << endl;
                exit(0);
            }
            if(!bio[novi])
            {
                rek(novi);
            }
            mojerj = max(mojerj, rj[novi]);
        }
    }
    rj[cvor] = mojerj + 1;
    urek[cvor] = 0;
    bio[cvor] = 1;
    return;
}

int main()
{
    cin >> n >> m;
    graf.insert(graf.begin(), n + m, vi);
    REP(i, 0, n + m) rod[i] = i;
    REP(i, 0, n)
    {
        scanf("%s", mat[i]);
        REP(j, 0, m)
        {
            if(mat[i][j] == '=')
            {
                spoji(i, j + n);
            }
        }
    }
    int a, b;
    REP(i, 0, n)
    {
        REP(j, 0, m)
        {
            a = dajrod(i);
            b = dajrod(j + n);
            if(a == b && mat[i][j] != '=')
            {
                cout << "No" << endl;
                exit(0);
            }
            else if(a == b) continue;
            if(mat[i][j] == '<')
            {
                graf[b].push_back(a);
            }
            else
            {
                graf[a].push_back(b);
            }
        }
    }
    REP(i, 0, n + m)
    {
        a = dajrod(i);
        if(bio[a]) continue;
        rek(a);
    }
    cout << "Yes" << endl;
    REP(i, 0, n)
    {
        cout << rj[dajrod(i)] << " ";
    }
    cout << endl;
    REP(i, n, n + m)
    {
        cout << rj[dajrod(i)] << " ";
    }
    return 0;
}