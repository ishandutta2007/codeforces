//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
struct data
{
    int x,y;
}a[111];
int n;
bool vis[111];
vector<int> v[7];
vector<pair<int,int> > ans;
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int g=(v[x][i]+1)/2;
        if(!vis[g])
        {
            vis[g]=1;
            if(v[x][i]%2)dfs(a[g].y);
            else dfs(a[g].x);
            ans.push_back(make_pair(g,v[x][i]%2));
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        v[a[i].x].push_back(i*2-1);
        v[a[i].y].push_back(i*2);
    }
    int cnt=0,st=-1;
    for(int i=0;i<=6;i++)
    {
        if(v[i].size()>0&&st==-1)st=i;
        if(v[i].size()&1)cnt++,st=i;
    }
    if(cnt>2)
    {
        cout<<"No solution"<<endl;
        return 0;
    }
    dfs(st);
    if(ans.size()<n)
    {
        cout<<"No solution"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i].ff<<" "<<(ans[i].ss%2?'-':'+')<<endl;
    }
    return 0;
}
/*
5
1 2
2 4
2 4
6 4
2 1
*/