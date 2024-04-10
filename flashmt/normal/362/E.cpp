#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct edge
{
    int x, y, cap, flow, cost;
};

struct MinCostMaxFlow
{
    int n, S, T;
    vector < vector <int> > a;
    vector <int> dist, prev, done, pot;
    vector <edge> e;
    
    MinCostMaxFlow() 
    {
    }
    
    MinCostMaxFlow(int n, int S, int T)
    {
        this -> n = n;
        this -> S = S;
        this -> T = T;
        a = vector < vector <int> >(n + 1);
        dist = vector <int>(n + 1);
        prev = vector <int>(n + 1);
        done = vector <int>(n + 1);
        pot = vector <int>(n + 1, 0);
    }
    
    void addEdge(int x, int y, int _cap, int _cost)
    {
        edge e1 = {x, y, _cap, 0, _cost};
        edge e2 = {y, x, 0, 0, -_cost};
        a[x].push_back(e.size()); e.push_back(e1);
        a[y].push_back(e.size()); e.push_back(e2);
    }
    
    pair <int,int> dijkstra()
    {
        int flow = 0, cost = 0;
        for (int i = 1; i <= n; i++) done[i] = 0, dist[i] = oo;
        priority_queue < pair<int,int> > q;
        dist[S] = 0; prev[S] = -1;
        q.push(make_pair(0, S));
        while (!q.empty())
        {
            int x = q.top().second; q.pop();
            if (done[x]) continue;
            done[x] = 1;
            for (int i = 0; i < int(a[x].size()); i++)
            {
                int id = a[x][i], y = e[id].y;
                if (e[id].flow < e[id].cap)
                {
                    int D = dist[x] + e[id].cost + pot[x] - pot[y];
                    if (!done[y] && D < dist[y])
                    {
                        dist[y] = D; prev[y] = id;
                        q.push(make_pair(-dist[y], y));
                    }
                }
            }
        }
        
        for (int i = 1; i <= n; i++) pot[i] += dist[i];
        
        if (done[T])
        {
            flow = oo;
            for (int id = prev[T]; id >= 0; id = prev[e[id].x]) 
                flow = min(flow, e[id].cap - e[id].flow);
            for (int id = prev[T]; id >= 0; id = prev[e[id].x]) 
            {
                cost += e[id].cost * flow;
                e[id].flow += flow;
                e[id ^ 1].flow -= flow;
            }
        }
        
        return make_pair(flow, cost);
    }
    
    pair <int,int> minCostMaxFlow()
    {
        int totalFlow = 0, totalCost = 0;
        while (1)
        {
            pair <int,int> u = dijkstra();
            if (!done[T]) break;
            totalFlow += u.first; totalCost += u.second;
        }
        return make_pair(totalFlow, totalCost);
    }
};

int n, k, a[55][55];

int getMinCost(int flow)
{
    int S = 1, T = n;
    MinCostMaxFlow f(n + 2, n + 1, n + 2);
    f.addEdge(n + 1, S, flow, 0);
    f.addEdge(T, n + 2, flow, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j])
            {
                f.addEdge(i, j, a[i][j], 0);
                f.addEdge(i, j, oo, 1);
            }
    
    pair <int,int> res = f.minCostMaxFlow();
    if (res.first < flow) return oo;
    return res.second;
}

int main()
{
    int maxOutgoing = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
    {
        int sumOutgoing = 0;
        for (int j = 1; j <= n; j++)
            cin >> a[i][j], sumOutgoing += a[i][j];
        maxOutgoing = max(maxOutgoing, sumOutgoing);
    }
            
    int low = 1, high = maxOutgoing + k, ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (getMinCost(mid) <= k) ans = mid, low = mid + 1;
        else high = mid - 1;
    }
    
    cout << ans << endl;
}