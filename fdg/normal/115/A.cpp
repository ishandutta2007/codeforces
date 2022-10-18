#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <memory.h>
#include <ctime>

#define ll long long

using namespace std;

int n,r[2002];
bool used[2002];
vector < vector <int> > g;


int dfs(int cur = 0)
{
    used[cur]=true;
    int ans=0;
    for(int i=0;i<g[cur].size();i++)
    {
        if (!used[g[cur][i]]) ans=max(dfs(g[cur][i]),ans);
    }
    return ans+1;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin >> n;
    g.resize(n);
    memset(r,-1,sizeof(r));
    for(int i=0;i<n;i++)
    {
        cin >> r[i];
        if (r[i]>0)
        {
            r[i]--;
            g[r[i]].push_back(i);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        if (r[i]==-1)
        {
            ans=max(ans,dfs(i));
        }
    cout << ans << endl;
    return 0;
}