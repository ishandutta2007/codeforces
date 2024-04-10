#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int N = 500500;

struct segmentTree
{
    int low, high, mid, val;
    segmentTree *L, *R;
    
    segmentTree() {}
    segmentTree(int _low, int _high)
    {
        low = _low; high = _high; mid = (low + high) / 2;
        val = 0;
        if (low < high)
        {
            L = new segmentTree(low, mid);
            R = new segmentTree(mid + 1, high);
        }
    }
    
    void update(int x, int v)
    {
        val = max(val, v);
        if (low < high)
        {
            if (x <= mid) L -> update(x, v);
            else R -> update(x, v);
        }
    }
    
    int get(int x, int y)
    {
        if (low == x && high == y) return val;
        int u = 0, v = 0;
        if (x <= mid) u = L -> get(x, min(y, mid));
        if (mid < y) v = R -> get(max(x, mid + 1), y);
        return max(u, v);
    }
};

int n, s[N], par[N], heavyDown[N], heavyUp[N], step, inTime[N], outTime[N];
int sizeChain[N], idChain[N], posChain[N], numChain, firstOnChain[N];
vector <int> a[N];
vector <segmentTree> tree;
segmentTree dfsTree;

void visit(int x)
{
    inTime[x] = ++step;
    s[x] = 1;
    for (int i = 0; i < int(a[x].size()); i++) 
    {
        int y = a[x][i];
        if (y != par[x]) 
        {
            par[y] = x; 
            visit(y); 
            s[x] += s[y];
        }
    }
    
    for (int i = 0; i < int(a[x].size()); i++) 
    {
        int y = a[x][i];
        if (y != par[x] && s[y] * 2 >= s[x]) heavyDown[x] = y, heavyUp[y] = 1;
    }
    outTime[x] = step;
}

void initHeavyLight()
{
    visit(1);
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        if (heavyUp[x]) continue;
        firstOnChain[numChain] = x;
        while (x)
        {
            idChain[x] = numChain;
            posChain[x] = sizeChain[numChain]++;
            x = heavyDown[x];
        }
        tree.push_back(segmentTree(0, sizeChain[numChain++] - 1));
    }
}

int main()
{
    //freopen("d.in", "r", stdin);
    int x, y, t, Q;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    initHeavyLight();
    
    dfsTree = segmentTree(1, n);
    
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        scanf("%d%d", &t, &x);
        
        if (t == 1) tree[idChain[x]].update(posChain[x], i);
        if (t == 2) dfsTree.update(inTime[x], i);
        if (t == 3)
        {
            int down = dfsTree.get(inTime[x], outTime[x]);
            int up = 0;
            while (x)
            {
                int u = tree[idChain[x]].get(0, posChain[x]);
                up = max(up, u);
                x = par[firstOnChain[idChain[x]]];
            }
            printf("%d\n", (up > down));            
        }
    }
}