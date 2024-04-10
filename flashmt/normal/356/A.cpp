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

int n, m, l[300300], r[300300], x[300300], segTree[3000300];

void put(int nd, int l, int r, int x, int y, int v)
{
    if (l == x && r == y) segTree[nd] = v;
    else
    {
        int m = (l + r) / 2;
        if (segTree[nd]) segTree[nd * 2] = segTree[nd * 2 + 1] = segTree[nd], segTree[nd] = 0;
        if (x <= m) put(nd * 2, l, m, x, min(y, m), v);
        if (m < y) put(nd * 2 + 1, m + 1, r, max(x, m + 1), y, v);
    }
}

int get(int nd, int l, int r, int x)
{
    if (segTree[nd] || l == r) return segTree[nd];
    int m = (l + r) / 2;
    if (x <= m) return get(nd * 2, l, m, x);
    return get(nd * 2 + 1, m + 1, r, x);
}

int main()
{
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", l + i, r + i, x + i);
        
    for (int i = m - 1; i >= 0; i--)
    {
        if (l[i] < x[i]) put(1, 1, n, l[i], x[i] - 1, x[i]);
        if (x[i] < r[i]) put(1, 1, n, x[i] + 1, r[i], x[i]);
    }
        
    for (int i = 1; i <= n; i++) printf("%d ", get(1, 1, n, i));
}