#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory.h>
#include <string>

using namespace std;

int n;
vector < vector <int> > g;
vector <bool> used;

pair <int,int> dfs(int cur)
{
    used[cur]=true;
    pair <int,int> ret=make_pair(0,cur),p;
    for(int i=0;i<g[cur].size();i++)
        if (!used[g[cur][i]])
        {
            p=dfs(g[cur][i]);
            p.first++;
            if (p>ret) ret=p;
        }
    return ret;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int k,ans=0,a,b;
    cin >> k;
    for(int i=0;i<k;i++)
    {
        cin >> n;
        g.clear();
        g.resize(n);
        used.clear();
        used.resize(n,false);
        for(int j=0;j<n-1;j++)
        {
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        pair <int,int> p=dfs(0);
        used.clear(); used.resize(n,false);
        p=dfs(p.second);
        ans+=p.first;
    }
    cout << ans << endl;
    return 0;
}