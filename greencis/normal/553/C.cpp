#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007ll;

void ans(ll ANS) {
    ANS %= MOD;
    if (ANS < 0) ANS += MOD;
    cout << ANS;
    exit(0);
}

int n,m,x,y,c,color[100005];
vector< pii > g[100005];

void dfs(int v, int curc) {
    if (color[v] != -1) {
        if (color[v] != curc)
            ans(0);
        return;
    }
    color[v] = curc;
    for (int i = 0; i < g[v].size(); ++i)
        dfs(g[v][i].first, g[v][i].second ^ curc);
}

int main()
{
    scanf("%d%d",&n,&m);
    while (m--) {
        scanf("%d%d%d",&x,&y,&c);
        c ^= 1;
        g[x].push_back(make_pair(y,c));
        g[y].push_back(make_pair(x,c));
    }

    for (int i = 0; i < 100005; ++i) color[i] = -1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            ++cnt;
            dfs(i, 0);
        }
    }

    ll curans = 1;
    while (--cnt)
        curans = (curans * 2ll) % MOD;
    ans(curans);

    return 0;
}