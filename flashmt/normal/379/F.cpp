#include <bits/stdc++.h>
using namespace std;

int p[1000100][22], n = 4, depth[1000100], maxLog = 0;

void add(int par, int x)
{
    p[x][0] = par;
    depth[x] = depth[par] + 1;
    if ((1 << maxLog) < depth[x]) maxLog++;
    for (int i = 0; i < 20; i++) p[x][i + 1] = p[p[x][i]][i];
}

int lca(int x, int y)
{
    if (depth[x] < depth[y]) swap(x, y);
    
    for (int i = maxLog; i >= 0; i--)
        if (depth[x] - (1 << i) >= depth[y])
            x = p[x][i];
            
    if (x == y) return x;
    
    for (int i = maxLog; i >= 0; i--)
        if (p[x][i] != p[y][i])
            x = p[x][i], y = p[y][i];
            
    return p[x][0];
}

int dist(int x, int y)
{
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

int main()
{
    ios::sync_with_stdio(0);
    
    for (int i = 2; i <= 4; i++) p[i][0] = 1, depth[i] = 1;
    
    int u = 2, v = 3, diameter = 2, x, q;
    cin >> q;
    while (q--)
    {
        cin >> x;
        add(x, ++n);
        add(x, ++n);
        
        int distU = dist(u, n), distV = dist(v, n);
        if (distU > diameter) diameter = distU, v = n;
        if (distV > diameter) diameter = distV, u = n;
        
        cout << diameter << endl;
    }
}