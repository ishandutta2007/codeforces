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
vector<int>dep[100111];
int l[100111],r[100111],deep[100111];
int n,p[50][100111];
bool vis[100111];
vector<int>son[100111];
int ti;
void dfs(int x,int gr,int d)
{
    l[x]=++ti;
    dep[d].pb(ti);deep[x]=d;
    for(int i=0;i<son[x].size();i++)
    {
        int u=son[x][i];
        if(u==p[0][x])continue;
        dfs(son[x][i],gr,d+1);
    }
    r[x]=++ti;
}
void init()
{
    for(int i=0;(1<<i)<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(p[i][j]==0)p[i+1][j]=0;
            else p[i+1][j]=p[i][p[i][j]];
        }
    }
}
int findkp(int x,int k)
{
    for(int i=0;(1<<i)<n;i++)
    {
        if((k>>i)&1)x=p[i][x];
    }
    return x;
}
int bins(int d,int x)
{
    int mid;
    int l=0,r=dep[d].size()-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(dep[d][mid]<x)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return l;
}
int cal(int d,int x)
{
    if(x==0)return 0;
//  cout<<bins(d,r[x])<<" "<<bins(d,l[x])<<endl;
    return bins(d,r[x])-bins(d,l[x])-1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[0][i];
        son[p[0][i]].pb(i);
    }init();
    int id=0;
    for(int i=1;i<=n;i++)
    {
        if(l[i]==0)dfs(i,++id,1);
    }
    /*
    for(int i=1;i<=n;i++)cout<<i<<":"<<l[i]<<","<<r[i]<<endl;
    for(int i=1;i<=2;i++)
    {
        for(int j=0;j<dep[i].size();j++)cout<<dep[i][j]<<" ";cout<<endl;
    }
    */
    int q,v,tmp;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>v>>tmp;
//      cout<<"deep[v]="<<deep[v]<<endl<<"findkp("<<v<<","<<tmp<<")="<<findkp(v,tmp)<<endl;
        cout<<cal(deep[v],findkp(v,tmp))<<" ";
    }
    return 0;
}