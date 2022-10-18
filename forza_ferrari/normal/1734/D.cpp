#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long
int t,n,m,a[200001],ans,sum,minn,l,r,now;
vector<pair<int,int> > vl,vr;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
signed main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        vl.clear();
        vr.clear();
        minn=sum=0;
        for(int i=m-1;i>=1;--i)
        {
            sum+=a[i];
            minn=min(minn,sum);
            if(sum>0)
            {
                vl.emplace_back(sum,-minn);
                minn=sum=0;
            }
        }
        vl.emplace_back(sum,-minn);
        sum=minn=0;
        for(int i=m+1;i<=n;++i)
        {
            sum+=a[i];
            minn=min(minn,sum);
            if(sum>0)
            {
                vr.emplace_back(sum,-minn);
                minn=sum=0;
            }
        }
        vr.emplace_back(sum,-minn);
        ans=0;
        l=0,r=0;
        now=a[m];
        bool flag=1;
        while(l<(int)vl.size()&&r<(int)vr.size())
        {
            if(now>=vl[l].second&&now>=vr[r].second)
            {
                if(vl[l].first>vl[r].first)
                    now+=vl[l++].first;
                else
                    now+=vr[r++].first;
                continue;
            }
            if(now>=vl[l].second)
            {
                now+=vl[l++].first;
                continue;
            }
            if(now>=vr[r].second)
            {
                now+=vr[r++].first;
                continue;
            }
            flag=0;
            break;
        }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}