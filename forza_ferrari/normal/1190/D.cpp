#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
struct element
{
    int x,y;
    bool operator <(const element &other) const
    {
        return y^other.y? y>other.y:x<other.x;
    }
}a[200001];
int n,node[200001],cnt,sum[200001];
long long ans;
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
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].x>>a[i].y;
        node[i]=a[i].x;
    }
    sort(node+1,node+n+1);
    cnt=unique(node+1,node+n+1)-node-1;
    sort(a+1,a+n+1);
    int pos=1;
    while(pos<=n)
    {
        int tmp=a[pos].y,lst=0,qwq=pos;
        while(pos<=n&&a[pos].y==tmp)
        {
            a[pos].x=lower_bound(node+1,node+cnt+1,a[pos].x)-node;
            if(query(a[pos].x)==query(a[pos].x-1))
                update(a[pos].x);
            ++pos;
        }
        pos=qwq;
        while(pos<=n&&a[pos].y==tmp)
        {
            ans+=1ll*(query(a[pos].x)-query(lst))*(query(cnt)-query(a[pos].x-1));
            lst=a[pos++].x;
        }
    }
    cout<<ans<<'\n';
    return 0;
}