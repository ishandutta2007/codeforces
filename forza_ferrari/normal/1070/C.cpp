//noip rp++!
#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define int long long
struct element
{
    int opt,t,c,p;
    bool operator <(const element &other) const
    {
        return t<other.t;
    }
}a[200001<<1];
int n,k,m,cnt[1000001],val[1000001],ans,maxn;
set<int> s;
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
inline void update(int x,int val1,int val2)
{
    for(;x<=maxn;x+=lowbit(x))
    {
        cnt[x]+=val1;
        val[x]+=val2;
    }
}
inline int query1(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=cnt[x];
    return res;
}
inline int query2(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=val[x];
    return res;
}
signed main()
{
    n=read(),k=read(),m=read();
    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read(),c=read(),p=read();
        maxn=max(maxn,p);
        a[(i<<1)-1]={1,l,c,p};
        a[i<<1]={-1,r+1,c,p};
    }
    m<<=1;
    sort(a+1,a+m+1);
    int p=1;
    for(int i=1;i<=n;++i)
    {
        while(p<=m&&a[p].t<=i)
        {
            update(a[p].p,a[p].c*a[p].opt,a[p].p*a[p].c*a[p].opt);
            if(query1(a[p].p)-query1(a[p].p-1))
                s.insert(a[p].p);
            else
                if(s.find(a[p].p)!=s.end())
                    s.erase(s.find(a[p].p));
            ++p;
        }
        if(query1(maxn)<=k)
        {
            ans+=query2(maxn);
            continue;
        }
        int pos=0,tmp=0,val=0,v=0;
        for(int j=20;~j;--j)
        {
            tmp=pos|(1<<j);
            if(tmp>maxn)
                continue;
            v=val+cnt[tmp];
            if(v>k)
                continue;
            val=v;
            pos=tmp;
        }
        ans+=query2(pos);
        if(val==k)
            continue;
        int num=*s.upper_bound(pos);
        ans+=num*(k-val);
    }
    printf("%lld\n",ans);
    return 0;
}