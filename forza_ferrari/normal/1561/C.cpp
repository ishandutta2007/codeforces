#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct element1
{
    int minn,val;
    bool operator <(const element1 &other) const
    {
        return minn<other.minn;
    }
}a[100001];
struct element2
{
    int minn,val;
    element2(int minn_,int val_):
        minn(minn_),val(val_){}
    bool operator <(const element2 &other) const
    {
        return val<other.val;
    }
};
int t,n,ans;
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
inline bool check(int x)
{
    priority_queue<element2> q;
    int cnt=0,p=1;
    while(p<=n&&a[p].minn<=x)
    {
        q.push(element2(a[p].minn,a[p].val));
        ++p;
    }
    while(!q.empty())
    {
        element2 k=q.top();
        q.pop();
        ++cnt;
        if(cnt==n)
            return 1;
        x+=k.val;
        while(p<=n&&a[p].minn<=x)
        {
            q.push(element2(a[p].minn,a[p].val));
            ++p;
        }
    }
    return 0;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(register int i=1;i<=n;++i)
        {
            a[i].val=read();
            a[i].minn=0;
            for(register int j=1;j<=a[i].val;++j)
            {
                int x=read();
                a[i].minn=max(a[i].minn,x-j+2);
            }
        }
        sort(a+1,a+n+1);
        ans=0;
        int l=0,r=1e9+1,mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(mid))
            {
                r=mid-1;
                ans=mid;
            }
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}