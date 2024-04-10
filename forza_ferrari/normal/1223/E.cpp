#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
struct edge
{
    int nxt,to,weight;
}e[500001<<1];
int t,n,m,tot,h[500001],dp[500001][2];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
inline bool cmp(pair<int,int> x,pair<int,int> y)
{
    return x.first-x.second>y.first-y.second;
}
void dfs(int k,int f,int val)
{
    dp[k][0]=val;
    dp[k][1]=0;
    vector<pair<int,int> > v;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k,e[i].weight);
        if(dp[e[i].to][0]>dp[e[i].to][1])
            v.push_back({dp[e[i].to][0],dp[e[i].to][1]});
        else
        {
            dp[k][0]+=dp[e[i].to][1];
            dp[k][1]+=dp[e[i].to][1];
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<(int)v.size();++i)
    {
        //cout<<"? "<<v[i].first<<" "<<v[i].second<<endl;
        if(i+1<=m)
            dp[k][1]+=v[i].first;
        else
            dp[k][1]+=v[i].second;
        if(i+1<m)
            dp[k][0]+=v[i].first;
        else
            dp[k][0]+=v[i].second;
    }
    //cout<<k<<" "<<dp[k][0]<<" "<<dp[k][1]<<endl;
}
signed main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        tot=0;
        for(int i=1;i<=n;++i)
            h[i]=0;
        for(int i=1;i<n;++i)
        {
            int x=read(),y=read(),w=read();
            add(x,y,w);
            add(y,x,w);
        }
        //cout<<endl;
        dfs(1,0,0);
        cout<<max(dp[1][0],dp[1][1])<<endl;
    }
    return 0;
}