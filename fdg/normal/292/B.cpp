#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector < vector <int> > g;
int deg[100005];
bool used[100005];

int dfs(int v) {
    used[v]=true;
    int cnt=1;
    for(int i=0;i<g[v].size();++i)
        if (!used[g[v][i]]) cnt+=dfs(g[v][i]);
    return cnt;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b;
    scanf("%d%d",&n,&m); g.resize(n);
    if (n!=m+1&&n!=m) {
        puts("unknown topology");
        return 0;
    }
    for(int i=0;i<m;++i) {
        scanf("%d%d",&a,&b); --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++; deg[b]++;
    }
    if (dfs(0)!=n) {
        puts("unknown topology");
        return 0;
    }
    int cnt[5]={0},mx=0;
    for(int i=0;i<n;++i) {
        if (deg[i]>mx) mx=deg[i];
        if (deg[i]<3) cnt[deg[i]]++;
    }
    if (cnt[2]==n) {
        puts("ring topology");
    } else if (cnt[1]==2&&cnt[2]==n-2) {
        puts("bus topology");
    } else if (cnt[1]==n-1&&mx==n-1) {
        puts("star topology");
    } else {
        puts("unknown topology");
    }
    return 0;
}