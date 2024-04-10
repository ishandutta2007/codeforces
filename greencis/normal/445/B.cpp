#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int n,m,x,y,comp[999],good[999],r,cur;
long long risk = 1ll;
vector<int> g[999];

void dfs(int q) {
    if (comp[q]) return;
    comp[q] = cur;
    for (int i = 0; i < g[q].size(); ++i)
        dfs(g[q][i]);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g[y].push_back(x);
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
        if (!comp[i]) {
            ++cur;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i)
        ++good[comp[i]];
    for (int i = 1; i <= n; ++i)
        r += max(0,good[i] - 1);
    if (r != 0) risk <<= (long long)r;
    cout << risk;

    return 0;
}