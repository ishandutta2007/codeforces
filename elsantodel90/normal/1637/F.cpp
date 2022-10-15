#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define all(c) begin(c),end(c)
#define SIZE(c) int((c).size())

typedef long long tint;

struct Node
{
    int index;
    int height;
    
    bool operator<(const Node &o) const { return height < o.height; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<Node> nodes(n);
    vector<int> height(n);
    forn(i,n)
    {
        cin >> height[i];
        nodes[i] = {i, height[i]};
    }
    sort(all(nodes));
    forn(edge, n-1)
    {
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> deg(n);
    forn(i,n)
        deg[i] = SIZE(g[i]);
    tint totalLeaves = 0;
    forn(i,n)
        totalLeaves += deg[i] == 1;
    int previousHeight = 0;
    tint ret = 0; 
    for (int i=0; i<n;)
    {
        int currentHeight = nodes[i].height;
        assert(i == n-1 || totalLeaves >= 2); // Every non trivial tree has at least 2 leaves
        ret += max(2LL, totalLeaves) * (currentHeight - previousHeight);
        vector<int> leavesToPrune;
        while (i < n && nodes[i].height == currentHeight)
        {
            if (deg[nodes[i].index] == 1)
                leavesToPrune.push_back(nodes[i].index);
            i++;
        }
        while (!leavesToPrune.empty())
        {
            int x = leavesToPrune.back();
            leavesToPrune.pop_back();
            totalLeaves--;
            for (int y : g[x])
            if (--deg[y] == 1)
            {
                totalLeaves++;
                if (height[y] <= currentHeight)
                    leavesToPrune.push_back(y);
            }
        }
        previousHeight = currentHeight;
    }
    cout << ret << "\n";
    return 0;
}