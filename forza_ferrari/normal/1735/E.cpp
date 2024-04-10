#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int t,n,a[1001],b[1001],h[1001];
bool vis[1001];
struct element
{
    int dis,id,tag;
    element(int dis_,int id_,int tag_):
        dis(dis_),id(id_),tag(tag_){}
    bool operator <(const element &other) const
    {
        return dis^other.dis? dis<other.dis:tag<other.tag;
    }
};
inline bool check(int x)
{
    for(int i=1;i<=n;++i)
        h[i]=a[i],vis[i]=0;
    sort(h+1,h+n+1);
    priority_queue<element> q;
    for(int i=1;i<=n;++i)
        if(abs(h[i]-x)>abs(x+h[i]))
        {
            q.emplace(abs(h[i]-x),i,1);
            q.emplace(abs(x+h[i]),i,2);
        }
        else
        {
            q.emplace(abs(h[i]-x),i,2);
            q.emplace(abs(x+h[i]),i,1);
        }
    for(int i=n;i>=1;--i)
    {
        while(!q.empty()&&(q.top().dis>b[i]||vis[q.top().id]))
            q.pop();
        if(q.empty()||q.top().dis!=b[i])
            return 0;
        vis[q.top().id]=1;
        if(abs(h[q.top().id]-x)!=q.top().dis)
            h[q.top().id]*=-1;
        q.pop();
    }
    for(int i=1;i<=n;++i)
        if(!vis[i])
            return 0;
    return 1;
}
inline void print(int x,int y)
{
    cout<<"YES\n";
    int minn=min(x,y);
    for(int i=1;i<=n;++i)
        minn=min(minn,h[i]);
    x-=minn;
    y-=minn;
    for(int i=1;i<=n;++i)
        h[i]-=minn;
    for(int i=1;i<=n;++i)
        cout<<h[i]<<" ";
    cout<<'\n'<<x<<" "<<y<<'\n';
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<=n;++i)
            cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        bool flag=0;
        for(int i=1;i<=n;++i)
        {
            if(check(a[i]-b[n]))
            {
                flag=1;
                print(0,a[i]-b[n]);
                break;
            }
            if(check(a[i]+b[n]))
            {
                flag=1;
                print(0,a[i]+b[n]);
                break;
            }
            a[i]=-a[i];
            if(check(a[i]-b[n]))
            {
                flag=1;
                print(0,a[i]-b[n]);
                break;
            }
            if(check(a[i]+b[n]))
            {
                flag=1;
                print(0,a[i]+b[n]);
                break;
            }
            a[i]=-a[i];
        }
        if(!flag)
            cout<<"NO\n";
    }
    return 0;
}