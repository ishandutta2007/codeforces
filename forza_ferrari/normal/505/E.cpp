#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
int n,m,cnt,p,h[100001],a[100001],b[100001],ans;
inline bool check(int mid)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    for(int i=1;i<=n;++i)
    {
        b[i]=mid;
        if(mid-a[i]*m<h[i])
            q.emplace(mid/a[i],i);
    }
    for(int i=1;i<=m;++i)
        for(int j=1;j<=cnt;++j)
        {
            if(q.empty())
                return 1;
            pair<int,int> k=q.top();
            q.pop();
            if(k.first<i)
                return 0;
            b[k.second]+=p;
            if(b[k.second]-a[k.second]*m<h[k.second])
                q.emplace(b[k.second]/a[k.second],k.second);
        }
    return q.empty();
}
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
signed main()
{
    n=read(),m=read(),cnt=read(),p=read();
    for(int i=1;i<=n;++i)
        h[i]=read(),a[i]=read();
    int l=0,r=1e13,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<'\n';
    return 0;
}