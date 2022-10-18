#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
int t,n,a[100001],b[100001],ans;
map<int,int> mp;
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
inline bool check(int d,int x)
{
    mp.clear();
    for(int i=1;i<=n;++i)
        ++mp[b[i]>>d];
    for(int i=1;i<=n;++i)
        if((--mp[x^(a[i]>>d)])<0)
            return 0;
    return 1;
}
signed main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        for(int i=1;i<=n;++i)
            b[i]=read();
        ans=0;
        for(int i=29;~i;--i)
            if(check(i,ans<<1|1))
                ans=ans<<1|1;
            else
            {
                for(int j=1;j<=n;++j)
                {
                    a[j]|=1<<i;
                    b[j]|=1<<i;
                }
                ans<<=1;
            }
        cout<<ans<<'\n';
    }
    return 0;
}