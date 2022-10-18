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
#include <bitset>
using namespace std;

int n,m,a,b,u[30005];
vector<vector<int> > g(30005);
vector<int> ans;
map<pair<int,int>,int> mp;

void fail() {
    printf("-1");
    exit(0);
}

void dfs(int v) {
    u[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!u[to]) dfs(to);
    }
    ans.push_back(v+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    while (m--) {
        scanf("%d%d",&a,&b);
        --a; --b;
        g[b].push_back(a);
        if (mp[make_pair(a,b)]) fail();
        mp[make_pair(b,a)] = 1;
    }
    for (int i = 0; i < n; ++i)
        if (!u[i]) dfs(i);
    if (ans.size() != n) fail();
    else {
        for (int i = n-1; i >= 0; --i)
            printf("%d ",ans[i]);
    }

    return 0;
}