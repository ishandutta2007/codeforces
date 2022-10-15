#include <iostream>
#include <vector>
#include <queue>

#define F first
#define S second

const int INF = 123456789;

using namespace std;

//ifstream cin("input.txt");
//ofstream cout("output.txt");

typedef pair < pair<int,int>, int> edge;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //0. Reading
    int n, m;
    cin >> n >> m;
    vector <edge> v(m);
    for (int i = 0; i < m; i++) cin >> v[i].F.F >> v[i].F.S >> v[i].S;
    vector < vector< pair<int,int> > > g(n);
    for (int i = 0; i < m; i++)
    {
        g[v[i].F.F].push_back(make_pair(v[i].F.S, v[i].S));
        g[v[i].F.S].push_back(make_pair(v[i].F.F, v[i].S));
    }

    //1. 1. Zeros
    vector <int> zr(n), zp(n);
    vector <bool> qr(n);
    queue<int> q;
    while (!q.empty()) q.pop();
    q.push(n - 1);
    for (int i = 0; i < n; i++) zr[i] = INF, zp[i] = INF;
    zr[n - 1] = n - 1, zp[n - 1] = 0;
    while (!q.empty())
    {
        int el = q.front();
        q.pop();
        for (int i = 0; i < g[el].size(); i++)
        {
            if (g[el][i].S != 0)
            {
                qr[el] = true;
                continue;
            }
            int to = g[el][i].F;
            if (zp[to] != INF) continue;
            zr[to] = el, zp[to] = zp[el] + 1;
            q.push(to);
        }
    }
/*
    cout << "-------- 1.1 -----" << endl;
    for (int i = 0; i < n; i++) cout << zr[i] << " " << zp[i] << " " << qr[i] << endl;
    cout << "------------------" << endl;
*/
    //1. 2. Length calculation
    vector <int> l(n);
    while (!q.empty()) q.pop();
    for (int i = 0; i < n; i++) l[i] = INF;
    for (int i = 0; i < n; i++) if (qr[i]) q.push(i), l[i] = 0;
    while (!q.empty())
    {
        int el = q.front();
        q.pop();
        for (int i = 0; i < g[el].size(); i++)
        {
            int to = g[el][i].F;
            if (l[to] != INF) continue;
            l[to] = l[el] + 1;
            q.push(to);
        }
    }
/*
    cout << "-------- 1.2 -----" << endl;
    for (int i = 0; i < n; i++) cout << l[i] << endl;
    cout << "------------------" << endl;
*/
    //1. 3. Length calculation (from other end)
    vector <int> l1(n);
    while (!q.empty()) q.pop();
    for (int i = 0; i < n; i++) l1[i] = INF;
    q.push(0), l1[0] = 0;
    while (!q.empty())
    {
        int el = q.front();
        q.pop();
        for (int i = 0; i < g[el].size(); i++)
        {
            int to = g[el][i].F;
            if (l1[to] != INF) continue;
            l1[to] = l1[el] + 1;
            q.push(to);
        }
    }
/*
    cout << "-------- 1.3 -----" << endl;
    for (int i = 0; i < n; i++) cout << l1[i] << endl;
    cout << "------------------" << endl;
*/
    //1. 4. Deleting unused edges
    vector < vector< pair<int,int> > > h(n);
    for (int i = 0; i < m; i++)
    {
        if (zr[v[i].F.F] != INF && zr[v[i].F.S] != INF) continue;
        if (l[v[i].F.F] + l1[v[i].F.S] + 1 == l[0]) h[v[i].F.F].push_back(make_pair(v[i].F.S, v[i].S));
        if (l[v[i].F.S] + l1[v[i].F.F] + 1 == l[0]) h[v[i].F.S].push_back(make_pair(v[i].F.F, v[i].S));
    }
/*
    cout << "-------- 1.4 -----" << endl;
    for (int i = 0; i < k; i++) cout << w[i].F.F << " " << w[i].F.S << " " << w[i].S << endl;
    cout << "------------------" << endl;
*/
    //2. Search path
    vector <int> p(n), pr(n), z(n), u(n);
    for (int i = 0; i < n; i++) p[i] = INF;
    vector < vector<int> > prq;
    prq.push_back(vector<int>());
    for (int i = 0; i < n; i++)
        if (qr[i])
        {
            prq[0].push_back(i);
            p[i] = 0;
            pr[i] = i;
            z[i] = zp[i];
        }
    for (;;)
    {
        //1. Max search
        int mv = INF, lst = prq.size() - 1, np = prq.size();
        prq.push_back(vector<int>());
        for (int i = 0; i < prq[lst].size(); i++)
        {
            int cur = prq[lst][i];
            for (int j = 0; j < h[cur].size(); j++)
                if (p[h[cur][j].F] > np) mv = min(mv, h[cur][j].S);
        }
        if (mv == INF) break;
        //2. Going next
        for (int i = 0; i < prq[lst].size(); i++)
        {
            int cur = prq[lst][i];
            for (int j = 0; j < h[cur].size(); j++)
            {
                if (h[cur][j].S != mv) continue;
                int to = h[cur][j].F;
                if (p[to] > np)
                    p[to] = np, pr[to] = cur, z[to] = z[cur], u[to] = mv, prq[np].push_back(to);
                else if (p[to] == np && z[cur] < z[to])
                    pr[to] = cur, z[to] = z[cur];
            }
        }
    }
/*
    cout << "-------- 2 -------" << endl;
    for (int i = 0; i < n; i++) cout << p[i] << " " << pr[i] << " " << z[i] << " " << u[i] << endl;
    cout << "------------------" << endl;
*/
    //3. Repairing

    if (zr[0] != INF)
    {
        cout << "0" << endl;
        vector <int> path;
        int c = 0;
        path.push_back(0);
        while (zp[c] > 0 && zp[c] != INF)
        {
            path.push_back(zr[c]);
            c = zr[c];
        }
        cout << path.size() << endl;
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
        return 0;
    }

    string ans;
    vector <int> path;
    int c = 0;
    path.push_back(0);
    while (p[c] > 0 && p[c] != INF)
    {
        path.push_back(pr[c]);
        ans = char(u[c] + '0') + ans;
        c = pr[c];
    }
    while (zp[c] > 0 && zp[c] != INF)
    {
        path.push_back(zr[c]);
        c = zr[c];
    }

    //4. Output
    if (ans == "") ans = "0";
    cout << ans << endl;
    cout << path.size() << endl;
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
}