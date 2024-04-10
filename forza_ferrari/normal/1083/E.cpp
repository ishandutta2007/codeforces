#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;
#define int long long
int n,dp[1000001],ans;
struct element
{
    int x,y,w;
    bool operator <(const element &other) const
    {
        return x<other.x;
    }
}node[1000001];
deque<int> q;
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
inline double slope(int x,int y)
{
    return 1.0*(dp[x]-dp[y])/(node[x].x-node[y].x);
}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i)
        node[i].x=read(),node[i].y=read(),node[i].w=read();
    sort(node+1,node+n+1);
    q.emplace_back(0);
    for(int i=1;i<=n;++i)
    {
        while(q.size()>1&&slope(q[0],q[1])>=node[i].y)
            q.pop_front();
        dp[i]=dp[q[0]]+node[i].x*node[i].y-node[q[0]].x*node[i].y-node[i].w;
        ans=max(ans,dp[i]);
        while(q.size()>1&&slope(q[q.size()-2],q[q.size()-1])<=slope(q[q.size()-1],i))
            q.pop_back();
        q.emplace_back(i);
    }
    cout<<ans<<'\n';
    return 0;
}