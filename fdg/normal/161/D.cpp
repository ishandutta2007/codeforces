#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#pragma comment(linker,"/STACK:128000000")

using namespace std;

long long ans=0;
vector <vector <int> > g;
int k,dp[50002][502];

void dfs(int v,int par = -1) {
    dp[v][0]=1;
    for(int i=0;i<g[v].size();++i)
        if (g[v][i]!=par) dfs(g[v][i],v);
    for(int i=0;i<g[v].size();++i) {
        int top=g[v][i];
        if (top!=par)
            for(int j=0;j<=k;++j)
                dp[v][j+1]+=dp[top][j];
    }
    for(int i=0;i<g[v].size();++i) {
        int top=g[v][i];
        if (top!=par)
            for(int j=0;j<k;++j)
                ans+=1LL*dp[top][j]*(dp[v][k-1-j]-(k-2-j>=0 ? dp[top][k-2-j] : 0));
    }
    ans+=dp[v][k];
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,b;
    scanf("%d%d",&n,&k);
    g.resize(n);
    for(int i=0;i<n-1;++i) {
        scanf("%d%d",&a,&b); --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    cout << (ans/2) << endl;
    return 0;
}