#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#define N 100020
#define M 5
#pragma GCC optimize("O3")
using namespace std;

string a[N];
vector<int> f[N][M];
vector<pair<int, int> > g[2];
vector<int> t;

inline int Convert(char c)
{
    return c == 'a' ? 0 : c == 'e' ? 1 : c == 'i' ? 2 : c == 'o' ? 3 : c == 'u' ? 4 : -1;
}

int main(void)
{
    int n;
    int i, j, k, c, p;

    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < n; i ++)
    {
        cin >> a[i];
        for(j = c = p = 0; j < (signed)a[i].size(); j ++)
        {
            c += Convert(a[i][j]) != -1;
            if(Convert(a[i][j]) != -1)
                p = Convert(a[i][j]);
        }
        // cout<<c<<' '<<p<<endl;
        f[c][p].push_back(i);
    }

    for(i = 0; i < N; i ++)
    {
        t.clear();
        for(j = 0; j < M; j ++)
        {
            if(f[i][j].size() & 1)
            {
                for(k = 0; k + 1 < (signed)f[i][j].size(); k += 2)
                    g[0].push_back(make_pair(f[i][j].at(k), f[i][j].at(k + 1)));
                t.push_back(f[i][j].back());
            }
            else
            {
                for(k = 0; k < (signed)f[i][j].size(); k += 2)
                    g[0].push_back(make_pair(f[i][j].at(k), f[i][j].at(k + 1)));
            }
        }

        for(j = 0; j + 1 < (signed)t.size(); j += 2)
            g[1].push_back(make_pair(t.at(j), t.at(j + 1)));
    }

    if(g[1].size() >= g[0].size())
    {
        cout << g[0].size() << endl;
        for(i = 0; i < (signed)g[0].size(); i ++)
            cout << a[g[1].at(i).first] << ' ' << a[g[0].at(i).first] << endl << a[g[1].at(i).second] << ' ' << a[g[0].at(i).second] << endl;
    }
    else
    {
        p = (g[1].size() + g[0].size()) / 2;
        cout << p << endl;
        for(i = 0; i < (signed)g[1].size(); i ++)
            g[0].push_back(g[1].at(i));
        for(i = 0, j = (signed)g[0].size() - 1; i < j; i ++, j --)
            cout << a[g[0].at(j).first] << ' ' << a[g[0].at(i).first] << endl << a[g[0].at(j).second] << ' ' << a[g[0].at(i).second] << endl;
    }

    return 0;
}