#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 7;
const int INF = (int) 2e9 + 7;
int n;
int x[N];
int y[N];
int t[N];
set<int> set_x;
set<int> set_y;
vector<int> xs;
vector<int> ys;
map<int, set<int>> on_x;
map<int, set<int>> on_y;
map<pair<int, int>, int> id;
vector<vector<int>> vecx;
vector<vector<int>> vecy;

int dist(int i, int j)
{
    if (x[i] == x[j])
    {
        return abs(y[i] - y[j]);
    }
    if (y[i] == y[j])
    {
        return abs(x[i] - x[j]);
    }
    return INF;
}


void build()
{
    for (int i = 1; i <= n; i++)
    {
        t[i] = i;
    }
}

int root(int i)
{
    if (t[i] == i)
    {
        return i;
    }
    else
    {
        return t[i] = root(t[i]);
    }
}

void unite(int i, int j)
{
    i = root(i);
    j = root(j);
    t[i] = j;
}

int cnt(vector<int> v)
{
    sort(v.begin(), v.end());
    int sol = 1;
    for (int i = 0; i + 1 < (int) v.size(); i++)
    {
        sol += (v[i] != v[i + 1]);
    }
    return sol;
}

bool ok(int val)
{
    build();
    for (auto &vec : vecx)
    {
        for (int i = 0; i + 1 < (int) vec.size(); i++)
        {
            int a = vec[i];
            int b = vec[i + 1];
            if (dist(a, b) <= val)
            {
                unite(a, b);
            }
        }
    }
    for (auto &vec : vecy)
    {
        for (int i = 0; i + 1 < (int) vec.size(); i++)
        {
            int a = vec[i];
            int b = vec[i + 1];
            if (dist(a, b) <= val)
            {
                unite(a, b);
            }
        }
    }
    int comps = 0;
    for (int i = 1; i <= n; i++)
    {
        comps += (t[i] == i);
    }
    if (comps > 4)
    {
        return 0;
    }
    if (comps == 1)
    {
        return 1;
    }
    if (comps == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (root(i) != root(j))
                {
                    if (dist(i, j) <= min(INF - 1LL, (ll) 2 * val))
                    {
                        return 1;
                    }
                    if (abs(x[i] - x[j]) <= val && abs(y[i] - y[j]) <= val)
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    if (comps == 3)
    {
        for (auto &vec : vecx)
        {
            for (int i = 0; i + 1 < (int) vec.size(); i++)
            {
                int a = vec[i];
                int b = vec[i + 1];
                if (root(a) != root(b) && dist(a, b) <= min(INF - 1LL, (ll) 2 * val))
                {
                    int lo = min(y[a], y[b]);
                    int hi = max(y[a], y[b]);
                    for (int j = 1; j <= n; j++)
                    {
                        if (root(j) != root(a) && root(j) != root(b) && abs(x[a] - x[j]) <= val && lo <= y[j] && y[j] <= hi && abs(y[j] - y[a]) <= val && abs(y[j] - y[b]) <= val)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
        for (auto &vec : vecy)
        {
            for (int i = 0; i + 1 < (int) vec.size(); i++)
            {
                int a = vec[i];
                int b = vec[i + 1];
                if (root(a) != root(b) && dist(a, b) <= min(INF - 1LL, (ll) 2 * val))
                {
                    int lo = min(x[a], x[b]);
                    int hi = max(x[a], x[b]);
                    for (int j = 1; j <= n; j++)
                    {
                        if (root(j) != root(a) && root(j) != root(b) && abs(y[a] - y[j]) <= val && lo <= x[j] && x[j] <= hi && abs(x[j] - x[a]) <= val && abs(x[j] - x[b]) <= val)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
    if (comps == 4)
    {
        for (auto &vec : vecx)
        {
            for (int i = 0; i + 1 < (int) vec.size(); i++)
            {
                int a = vec[i];
                int b = vec[i + 1];
                int lo = min(y[a], y[b]);
                int hi = max(y[a], y[b]);
                if (root(a) == root(b) || dist(a, b) > min(INF - 1LL, (ll) 2 * val))
                {
                    continue;
                }
                for (auto &vec2 : vecy)
                {
                    for (int j = 0; j + 1 < (int) vec2.size(); j++)
                    {
                        int a2 = vec2[j];
                        int b2 = vec2[j + 1];
                        if (root(a2) == root(b2) || dist(a, b) > min(INF - 1LL, (ll) 2 * val))
                        {
                            continue;
                        }
                        if (root(a) == root(a2) || root(a) == root(b2) || root(b) == root(a2) || root(b) == root(b2))
                        {
                            continue;
                        }
                        int xx = x[a];
                        int yy = y[a2];
                        if (abs(y[a] - yy) <= val && abs(y[b] - yy) <= val && abs(x[a2] - xx) <= val && abs(x[b2] - xx) <= val)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        id[{x[i], y[i]}] = i;
        on_x[x[i]].insert(y[i]);
        on_y[y[i]].insert(x[i]);
        set_x.insert(x[i]);
        set_y.insert(y[i]);
    }
    for (auto &x : set_x)
    {
        xs.push_back(x);
    }
    for (auto &y : set_y)
    {
        ys.push_back(y);
    }
    for (int i = 0; i + 1 < (int) xs.size(); i++)
    {
        set_x.insert((xs[i] + xs[i + 1]) / 2);
    }
    for (int i = 0; i + 1 < (int) ys.size(); i++)
    {
        set_y.insert((ys[i] + ys[i + 1]) / 2);
    }
    for (auto &it : on_x)
    {
        vector<int> cur;
        for (auto &y : it.second)
        {
            cur.push_back(id[{it.first, y}]);
        }
        vecx.push_back(cur);
    }
    for (auto &it : on_y)
    {
        vector<int> cur;
        for (auto &x : it.second)
        {
            cur.push_back(id[{x, it.first}]);
        }
        vecy.push_back(cur);
    }
    xs.clear();
    ys.clear();
    for (auto &x : set_x)
    {
        xs.push_back(x);
    }
    for (auto &y : set_y)
    {
        ys.push_back(y);
    }
    int l = 0, r = INF - 1, sol = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (ok(m))
        {
            sol = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << sol << "\n";
}