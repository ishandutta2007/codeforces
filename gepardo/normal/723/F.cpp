#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::min;
using std::max;
using std::ios_base;

int n, m, s, t, ds, dt;
vector < vector <int> > g;
vector < pair<int, int> > ans;
vector < pair<int, int> > stc;
vector <char> to_s, to_t;
vector <char> used;

pair <int, int> dfs(int v)
{
    used[v] = true;
    int hs = to_s[v] ? v : -1,
        ht = to_t[v] ? v : -1;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
        {
            ans.push_back({v+1, g[v][i]+1});
            pair <int, int> tmp = dfs(g[v][i]);
            hs = max(hs, tmp.first);
            ht = max(ht, tmp.second);
        }
    return {hs, ht};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    g.resize(n);
    used.assign(n, false);
    to_s.assign(n, false);
    to_t.assign(n, false);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> s >> t >> ds >> dt; s--, t--;
    used[s] = used[t] = true;
    for (int i = 0; i < g[s].size(); i++)
        to_s[g[s][i]] = true;
    for (int i = 0; i < g[t].size(); i++)
        to_t[g[t][i]] = true;
    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            pair <int, int> q = dfs(i);
            if (q.first >= 0 && q.second < 0)
                ans.push_back({s+1, q.first+1}), ds--;
            if (q.first < 0 && q.second >= 0)
                ans.push_back({t+1, q.second+1}), dt--;
            if (q.first >= 0 && q.second >= 0)
                stc.push_back(q);
        }
    ds--, dt--;
    if (stc.empty())
        ans.push_back({s+1, t+1});
    else
    {
        pair<int, int> el = *stc.rbegin();
        ans.push_back({el.second+1, t+1});
        ans.push_back({el.first+1, s+1});
        stc.pop_back();
    }
    while (!stc.empty() && ds > 0)
    {
        int el = stc.rbegin()->first;
        ans.push_back({el+1, s+1});
        stc.pop_back();
        ds--;
    }
    while (!stc.empty())
    {
        int el = stc.rbegin()->second;
        ans.push_back({el+1, t+1});
        stc.pop_back();
        dt--;
    }
    if (ds < 0 || dt < 0)
        cout << "No" << '\n';
    else
    {
        cout << "Yes" << '\n';
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first << " " << ans[i].second << '\n';
    }
    return 0;
}