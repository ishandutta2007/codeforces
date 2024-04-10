#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define someMagic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long

struct graphElement { int to, len, id; };

bool cmp(graphElement a, graphElement b) { return a.len < b.len; }

using namespace std;

const int llInf = 123456789012345678;

main()
{
    someMagic();
    int n, m; cin >> n >> m;
    vector < vector<graphElement> > g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c, i});
        g[b].push_back({a, c, i});
    }

    int u; cin >> u; u--;

    set < pair<int,int> > s;
    vector <int> path(n);

    for (int i = 0; i < n; i++)
    {
        path[i] = llInf;
        s.insert({path[i], i});
    }
    s.erase({path[u], 0});
    path[u] = 0;
    s.insert({path[u], 0});

    while (!s.empty())
    {
        int v = s.begin() -> second;
        s.erase(s.begin());
        for (auto to: g[v])
        {
            if (path[to.to] > path[v] + to.len)
            {
                s.erase({path[to.to], to.to});
                path[to.to] = path[v] + to.len;
                s.insert({path[to.to], to.to});
            }
        }
    }

    vector < vector<graphElement> > v(n);

    for (int i = 0; i < n; i++)
        for (auto q: g[i])
            if (path[q.to] + q.len == path[i]) v[i].push_back(q);

    for (int i = 0; i < n; i++)
        sort(v[i].begin(), v[i].end(), cmp);

    vector<int> ans;
    int ansl = 0;

    for (int i = 0; i < n; i++)
        if (v[i].size() != 0)
            ansl += v[i][0].len,
            ans.push_back(v[i][0].id + 1);

    cout << ansl << endl;

    for (auto i: ans) cout << i << " ";

}