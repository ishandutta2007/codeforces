#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

vector < vector <int> > g;
vector <int> step,leave;
bool used[100005]={0};
ll ans[100005]={0};
vector <ll> v[100005];
int s,curv=0;

void dfs(int cur)
{
    used[cur]=true; ans[cur]=0;
    v[curv].clear();
    ll free=0,may=step[cur]-1;
    if (cur==s) may++;
    for(int i=0;i<g[cur].size();i++)
        if (!used[g[cur][i]])
        {
            curv++;
            dfs(g[cur][i]);
            curv--;
            if (step[g[cur][i]]>=1) v[curv].push_back(ans[g[cur][i]]);
            free+=step[g[cur][i]];
//          if (step[g[cur][i]]==1||ans[g[cur][i]]==0) free+=step[g[cur][i]];
//          else free+=step[g[cur][i]];
        }
    sort(v[curv].rbegin(),v[curv].rend());
    for(int i=0;i<v[curv].size();i++)
    {
        if (may==0) break;
        ans[cur]+=v[curv][i]+2; free--; may--;
    }
    ans[cur]+=2LL*min(free,may);
    may-=free;
    if (may<0) may=0;
    step[cur]=may+1;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int n,a,b;
    scanf("%d",&n);
    g.resize(n);
    step.resize(n); leave.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&step[i]);
        leave[i]=step[i];
    }
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    scanf("%d",&s); s--;
    for(int i=0;i<n;i++)
    {
        used[i]=false;
        ans[i]=-1;
    }
    dfs(s);
    cout << ans[s] << endl;
    return 0;
}