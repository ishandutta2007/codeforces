#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool flag;
int n, m, k, a;
bool fl[100000];
vector<int> e[100000], c[100000];
int s[100000], l[100000], g[100000], p[100000], revp[100000], prev[100000][20], d[100000];

int unite(int a, int b)
{
    flag = true;
    if (c[g[a]].size() < c[g[b]].size())
        return unite(b, a);
    int ga = g[a], gb = g[b], ret = c[gb].size();
    for (int i = 0; i < (int)c[gb].size(); ++i)
    {
        c[ga].push_back(c[gb][i]);
        g[c[gb][i]] = ga;
    }
    c[gb].clear();
    return ret;
}

int newv, oldv;

void dfs(int v, int curd)
{
    p[curd] = v;
    revp[v] = curd;
    fl[v] = false;
    for (int i = 0; i < (int)e[v].size(); ++i)
        if (!fl[e[v][i]] && ((curd == 0) || (p[curd - 1] != e[v][i])))
        {
            newv = v;
            oldv = e[v][i];
            if (g[newv] != g[oldv])
            {
                int k = unite(newv, oldv);
                for (int i = 0; i < k; ++i)
                {
                    newv = p[revp[newv] - 1];
                    if (g[newv] != g[oldv])
                        k += unite(newv, oldv);
                    if (newv == oldv)
                        break;
                    oldv = p[revp[oldv] + 1];
                    if (g[newv] != g[oldv])
                        k += unite(newv, oldv);
                    if (newv == oldv)
                        break;
                }
            }
        }
    for (int i = 0; i < (int)e[v].size(); ++i)
    {
        if (fl[e[v][i]])
            dfs(e[v][i], curd + 1);
    }
}

void dfs2(int v, int curd)
{
    p[curd] = v;
    d[v] = curd;
    int n2 = 1, k = 0;
    while (curd - n2 >= 0)
    {
        prev[v][k] = p[curd - n2];
        n2 *= 2;
        ++k;
    }
    for (int i = 0; i < (int)c[v].size(); ++i)
        for (int j = 0; j < (int)e[c[v][i]].size(); ++j)
            if (d[g[ e[ c[v][i] ][j] ]] == -1)
                dfs2(g[e[ c[v][i] ][j]], curd + 1);
}

int lca(int v1, int v2)
{
    if (v1 == v2)
        return v1;
    int n2 = 1, k = 0;
    while (n2 < d[v1])
    {
        n2 *= 2;
        ++k;
    }
    int ans = v1;
    while (n2)
    {
        if (n2 <= d[v1])
        {
            if (prev[v1][k] == prev[v2][k])
                ans = prev[v1][k];
            else
            {
                v1 = prev[v1][k];
                v2 = prev[v2][k];
            }
        }
        n2 /= 2;
        --k;
    }
    return ans;
}

int go(int v1, int v2)
{
    if (d[v1] < d[v2])
        return go(v2, v1);
    int n2 = 1, k = 0, ans = d[v1] - d[v2];
    while (d[v1] > d[v2] + n2)
    {
        n2 *= 2;
        ++k;
    }
    while (d[v1] > d[v2])
    {
        if (d[v1] >= d[v2] + n2)
            v1 = prev[v1][k];
        n2 /= 2;
        --k;
    }
    return (d[v1] - d[lca(v1, v2)]) * 2 + ans;
}

int main(void)
{
    int b;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        --a;
        --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> s[i] >> l[i];
        --s[i];
        --l[i];
    }
    for (int i = 0; i < n; ++i)
    {
        g[i] = i;
        c[i].push_back(i);
    }
    a = 0;
    for (int i = 0; i < n; ++i)
    {
        fl[i] = true;
        d[i] = -1;
    }
    dfs(a, 0);
    dfs2(g[a], 0);
    for (int i = 0; i < k; ++i)
        cout << go(g[s[i]], g[l[i]]) << endl;
    return 0;
}