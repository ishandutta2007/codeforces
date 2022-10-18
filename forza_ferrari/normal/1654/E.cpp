#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long
const int m=sqrt(100000);
int n,a[100001],ans,w[1000001],cnt;
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
    n=read();
    ans=2;
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
    }
    for(int i=-m;i<=m;++i)
    {
        cnt=0;
        for(int j=1;j<=n;++j)
            w[++cnt]=a[j]-j*i;
        sort(w+1,w+cnt+1);
        int len=1;
        for(int j=2;j<=cnt;++j)
            if(w[j]!=w[j-1])
            {
                ans=max(ans,len);
                len=1;
            }
            else
                ++len;
        ans=max(ans,len);
    }
    for(int i=1;i<=n;++i)
    {
        cnt=0;
        for(int j=max(1ll,i-100000/m-10);j<i;++j)
            if((a[i]-a[j])%(i-j)==0)
                w[++cnt]=(a[i]-a[j])/(i-j);
        for(int j=i+1;j<=min(n,i+100000/m+10);++j)
            if((a[j]-a[i])%(j-i)==0)
                w[++cnt]=(a[j]-a[i])/(j-i);
        sort(w+1,w+cnt+1);
        int len=1;
        for(int j=2;j<=cnt;++j)
            if(w[j]!=w[j-1])
            {
                ans=max(ans,len+1);
                len=1;
            }
            else
                ++len;
        ans=max(ans,len+1);
    }
    cout<<max(n-ans,0ll)<<'\n';
    return 0;
}