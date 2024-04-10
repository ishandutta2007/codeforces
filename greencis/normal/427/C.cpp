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
#define MOD 1000000007
using namespace std;

int n,a[100005],m,x,y,u[100005],u2[100005],mx,mxc;
vector<int> g[100005],gr[100005];
vector<int> ans,comp;
long long res_cost,res_ways=1ll;

void dfs1(int v) {
    u[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (!u[g[v][i]])
            dfs1(g[v][i]);
    }
    ans.push_back(v);
}

void dfs2(int v) {
    u2[v] = 1;
    comp.push_back(v);
    if (mx > a[v]) {
        mx = a[v];
        mxc = 1;
    } else if (mx == a[v]) ++mxc;
    for (int i = 0; i < gr[v].size(); ++i) {
        if (!u2[gr[v][i]])
            dfs2(gr[v][i]);
    }
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    while (m--) {
        scanf("%d%d",&x,&y);
        --x; --y;
        g[x].push_back(y);
        gr[y].push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        if (!u[i])
            dfs1(i);
    }
    for (int i = 0; i < n; ++i) {
        int v = ans[n-i-1];
        if (!u2[v]) {
            mx = 2e9;
            mxc = 1;
            dfs2(v);
            res_cost += mx;
            res_ways = (res_ways * mxc) % MOD;
            comp.clear();
        }
    }

    cout << res_cost << " " << res_ways;

    return 0;
}