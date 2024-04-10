#include <iostream>
#include <vector>
#include <set>

#define vx first.first
#define vy first.second
#define sf second.first
#define sa second.second

using namespace std;

//ifstream cin("input.txt");
//ofstream cout("output.txt");

typedef pair< pair<int,int>, pair<int,int> > edge;

int main()
{
    int n, m; cin >> n >> m;
    vector <edge> v(2 * m);
    vector < vector<int> > g(n);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].vx >> v[i].vy >> v[i].sf;
        v[i].vx--; v[i].vy--;
        v[i].sa = 0;

        v[i + m].vx = v[i].vy;
        v[i + m].vy = v[i].vx;
        v[i + m].sf = v[i].sf;
        v[i + m].sa = 0;

        g[v[i].vx].push_back(i);
        g[v[i].vy].push_back(i + m);
    }

    vector <long long> d(n);
    vector <int> pre(n);
    set < pair<long long, int> > q;

    for (int i = 0; i < n; i++) pre[i] = -1;
    for (int i = 1; i < n; i++) q.insert(make_pair(123456789012345678, i)), d[i] = 123456789012345678;
    q.insert(make_pair(0, 0)), d[0] = 0;

    while (!q.empty())
    {
        int p = q.begin()->second;
        q.erase (q.begin());
        for (int i = 0; i < g[p].size(); i++)
        {
            int to = v[g[p][i]].vy;
            long long len = 1000001 - v[g[p][i]].sf;
            if (d[p] + len < d[to])
            {
                q.erase(make_pair(d[to], to));
				d[to] = d[p] + len;
				pre[to] = g[p][i];
				q.insert(make_pair(d[to], to));
            }
        }
    }
    //for (int i = 0; i < n; i++) cout << d[i] << " " << pre[i] << endl;
    int cur = n - 1;
    while (cur > 0)
    {
        int ver = pre[cur];
        v[ver % m].sa = 1;
        cur = v[ver].vx;
    }
    //for (int i = 0; i < m; i++) cout << v[i].sa << " ";
    vector <edge> ans;
    for (int i = 0; i < m; i++)
        if (v[i].sa != v[i].sf) ans.push_back(v[i]);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].vx + 1 << " " << ans[i].vy + 1 << " " << ans[i].sa << endl;
}