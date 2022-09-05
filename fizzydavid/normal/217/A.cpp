#include<utility>
#include<iostream>
#include<cstdlib>
using namespace std;
pair<int,int>a[105];
int n,s;
bool u[105];
int dfs(int z)
{
    u[z]=1;
    for(int i=1;i<=n;i++)if(i!=z&&!u[i]&&(a[i].first==a[z].first||a[i].second==a[z].second))dfs(i);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    for(int i=1;i<=n;i++)if(!u[i])dfs(i),s++;
    cout<<s-1<<endl;return 0;
}