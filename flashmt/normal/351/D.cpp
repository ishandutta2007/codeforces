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
const int oo = 27081993, MAXA = 100000;

int n, m, a[100100], next[100100], seen[100100], tree[100100], ans[100100], border[100100], head[100100], tail[100100];
vector <int> pos[100100];
pair <int,int> e[100100];
pair < pair<int,int>,int > q[100100];
int segTree[800800];
map <int,int> leaf[800800];

void add(int x)
{
    for (int i = x; i <= MAXA; i += i & -i) tree[i]++;
}

int get(int x)
{
    int res = 0;
    for (int i = x; i; i -= i & -i) res += tree[i];
    return res;
}

void addSegTree(int nd, int l, int r, int x, int v, int isAdd)
{
    if (l == r)
    {
        if (isAdd) leaf[nd][v]++;
        else 
            if (!--leaf[nd][v]) leaf[nd].erase(v);
        if (leaf[nd].empty()) segTree[nd] = oo;
        else segTree[nd] = leaf[nd].begin() -> first;
    }
    else
    {
        int m = (l + r) / 2;
        if (x <= m) addSegTree(nd * 2, l, m, x, v, isAdd);
        else addSegTree(nd * 2 + 1, m + 1, r, x, v, isAdd);
        segTree[nd] = min(segTree[nd * 2], segTree[nd * 2 + 1]);
    }
}

int getSegTree(int nd, int l, int r, int x, int y)
{
    if (l == x && r == y) return segTree[nd];
    int m = (l + r) / 2, u = oo, v = oo;
    if (x <= m) u = getSegTree(nd * 2, l, m, x, min(y, m));
    if (m < y) v = getSegTree(nd * 2 + 1, m + 1, r, max(x, m + 1), y);
    return min(u, v);
}

int main()
{
    //freopen("d.in", "r", stdin);
    
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    
    for (int i = n; i; i--)
    {
        if (!seen[a[i]]) next[a[i]] = n + 1;
        else next[a[i]] = seen[a[i]];
        seen[a[i]] = i;
        e[i] = make_pair(next[a[i]], i);
    }
    
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        q[i] = make_pair(make_pair(to, from), i);
    }
    
    // count distinct
    
    sort(e + 1, e + n + 1);
    sort(q + 1, q + m + 1);
    
    for (int i = m, j = n; i; i--)
    {
        int from = q[i].first.second, to = q[i].first.first, id = q[i].second;
        while (j && to < e[j].first) add(e[j--].second);
        ans[id] = get(to) - get(from - 1);
    }
    
    // process first step
    
    for (int i = 0; i <= MAXA; i++) seen[i] = 0, tail[i] = -1;
    for (int i = 0; i < 800000; i++) segTree[i] = oo;
    
    for (int i = 1, j = 1; i <= m; i++)
    {
        int from = q[i].first.second, to = q[i].first.first, id = q[i].second;
        
        while (j <= to)
        {
            int x = a[j], dif = j - seen[x];
            
            pos[x].push_back(j);
            tail[x]++;
            
            if (seen[x]) addSegTree(1, 1, MAXA, seen[x], border[x], 0);
            
            while (head[x] + 1 < tail[x] && pos[x][head[x] + 1] - pos[x][head[x]] != dif)
                border[x] = pos[x][head[x]++];
            
            addSegTree(1, 1, MAXA, j, border[x], 1);
            seen[x] = j++;
        }
        
        int minBorder = getSegTree(1, 1, MAXA, from, to);
        ans[id] += (minBorder >= from);
    }
    
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}