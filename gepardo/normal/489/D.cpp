#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int p[3000][3000] = {}, qin[3000][3000] = {}, qout[3000][3000] = {}, qinout[3000][3000] = {};

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        p[a][b] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        vector <int> v;
        for (int j = 0; j < n; j++)
            if (p[i][j] != 0) v.push_back(j);
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < i; j++)
                qin[v[i]][v[j]]++, qin[v[j]][v[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        vector <int> v;
        for (int j = 0; j < n; j++)
            if (p[j][i] != 0) v.push_back(j);
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < i; j++)
                qout[v[i]][v[j]]++, qout[v[j]][v[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        vector <int> v;
        for (int j = 0; j < n; j++)
            if (p[j][i] != 0 && p[i][j] != 0) v.push_back(j);
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < i; j++)
                qinout[v[i]][v[j]]++, qinout[v[j]][v[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            //cout << qin[i][j] << " " << qout[i][j] << " " << qinout[i][j] << endl;
            ans += (qin[i][j] * qout[i][j] - qinout[i][j]);
        }
    cout << ans;
}