#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
using namespace std;
vector<int>a[222];
int n,m,cnt,s;
bool u[222],q;
int dfs(int x)
{
    u[x]=1;cnt++;
    for(int i=0;i<a[x].size();i++)if(!u[a[x][i]])dfs(a[x][i]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int num;cin>>num;
        if(num>0)q=1;
        for(int j=1;j<=num;j++)
        {
            int z;cin>>z;a[i].push_back(z+n);a[z+n].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!u[i])
        {
            s++;dfs(i);
        }
    }
    cout<<s-int(q)<<endl;
    return 0;
}