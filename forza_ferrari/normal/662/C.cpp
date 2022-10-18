#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,a[1<<21],b[1<<21],c[1<<21],num[100001],ans;
inline void FWT(int *f,double tag)
{
    for(int p=2;p<=1<<n;p<<=1)
    {
        int len=p>>1;
        for(int i=0;i<1<<n;i+=p)
            for(int j=i;j<i+len;++j)
            {
                int x=f[j],y=f[j+len];
                f[j]=(x+y)*tag;
                f[j+len]=(x-y)*tag;
            }
    }
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            int val=getchar()-'0';
            while(val<0||val>1)
                val=getchar()-'0';
            num[j]|=val<<(i-1);
        }
    for(int i=0;i<1<<n;++i)
    {
        a[i]=__builtin_popcount(i);
        a[i]=min(a[i],n-a[i]);
    }
    for(int i=1;i<=m;++i)
        ++b[num[i]];
    FWT(a,1);
    FWT(b,1);
    for(int i=0;i<1<<n;++i)
        c[i]=a[i]*b[i];
    FWT(c,0.5);
    ans=n*m;
    for(int i=0;i<1<<n;++i)
        ans=min(ans,c[i]);
    cout<<ans<<endl;
    return 0;
}