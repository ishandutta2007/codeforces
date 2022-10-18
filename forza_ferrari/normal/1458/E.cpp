#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
struct element
{
    int opt,x,y,id;
    bool operator <(const element &other) const
    {
        return x^other.x? x<other.x:y^other.y? y<other.y:opt<other.opt;
    }
}a[200001];
int n,m,sum[100001],node[100001],cnt,lst,tot,d;
bool vis[100001],ans[100001];
map<pair<int,int>,bool> mp;
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
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x)
{
    for(;x<=cnt;x+=lowbit(x))
        ++sum[x];
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i].x=read(),node[i]=a[i].y=read();
        mp[{a[i].x,a[i].y}]=1;
    }
    sort(node+1,node+n+1);
    cnt=unique(node+1,node+n+1)-node-1;
    for(int i=1;i<=m;++i)
        a[i+n].x=read(),a[i+n].y=read(),a[i+n].opt=1,a[i+n].id=i;
    sort(a+1,a+n+m+1);
    lst=-1;
    for(int i=1;i<=n+m;++i)
    {
        if(a[i].opt)
        {
            if(mp.count({a[i].x,a[i].y}))
                continue;
            if(lst==a[i].x)
            {
                ans[a[i].id]=1;
                continue;
            }
            int pos=upper_bound(node+1,node+cnt+1,a[i].y)-node-1;
            if(pos<=cnt&&node[pos]==a[i].y&&vis[pos])
            {
                ans[a[i].id]=1;
                continue;
            }
            if(a[i].y+tot-query(pos)!=a[i].x)
                ans[a[i].id]=1;
        }
        else
        {
            int pos=lower_bound(node+1,node+cnt+1,a[i].y)-node;
            if(a[i].y+tot-query(pos)==a[i].x)
                continue;
            if(a[i].x<a[i].y+tot-query(pos))
            {
                if(!vis[pos])
                {
                    vis[pos]=1;
                    update(pos);
                }
            }
            else
                if(lst!=a[i].x)
                {
                    lst=a[i].x;
                    ++tot;
                }
        }
    }
    for(int i=1;i<=m;++i)
        cout<<(ans[i]? "WIN":"LOSE")<<'\n';
    return 0;
}