#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, k, s, t;
bool v[100000] = {false};
int d[100000];
vector<int> e[100000];

bool isok(int x)
{
    queue<int> q;
    q.push(s);
    memset(d, -1, n * sizeof(int));
    d[s] = 0;
    int z, nz;
    while (!q.empty())
    {
        z = q.front();
        q.pop();
        for (int i = 0; i < (int)e[z].size(); ++i)
        {
            nz = e[z][i];
            if ((d[nz] == -1) || (d[nz] > d[z] + 1))
            {
                v[nz] ? d[nz] = 0 : d[nz] = d[z] + 1;
                if (d[nz] != x)
                    q.push(nz);
            }
        }
        if (d[t] != -1)
            return true;
    }
    return false;
}

int main(void)
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> s;
        v[s - 1] = true;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> s; --s;
        cin >> t; --t;
        e[s].push_back(t);
        e[t].push_back(s);
    }
    cin >> s; --s;
    cin >> t; --t;
    if (!isok(n))
    {
        cout << -1 << endl;
        return 0;
    }
    int l = 1, r = n - 1, mid;
    while (r > l)
    {
        mid = (l + r) / 2;
        if (isok(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}