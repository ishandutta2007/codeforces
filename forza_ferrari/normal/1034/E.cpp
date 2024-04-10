#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,a[1<<21],b[1<<21],cnt[1<<21];
inline void init()
{
    for(register int i=0;i<n;++i)
        a[i]*=b[i];
}
inline void fwt(int *a,int x)
{
    for(register int i=2;i<=n;i<<=1)
    {
        int len=i>>1;
        for(register int j=0;j<n;j+=i)
            for(register int k=j;k<j+len;++k)
                a[k+len]=(a[k+len]+a[k]*x);
    }
}
signed main()
{
    scanf("%lld",&n);
    n=1<<n;
    for(register int i=0;i<n;++i)
    {
        char ch=getchar();
        while(ch<'0'||ch>'9')
            ch=getchar();
        a[i]=ch-'0';
    }
    for(register int i=0;i<n;++i)
    {
        char ch=getchar();
        while(ch<'0'||ch>'9')
            ch=getchar();
        b[i]=ch-'0';
    }
    for(register int i=0;i<n;++i)
    {
        if(i)
            cnt[i]=cnt[i>>1]+(i&1);
        a[i]=(a[i]*(1ll<<(cnt[i]<<1ll)));
        b[i]=(b[i]*(1ll<<(cnt[i]<<1ll)));
    }
    fwt(a,1);
    fwt(b,1);
    init();
    fwt(a,-1);
    for(register int i=0;i<n;++i)
        printf("%lld",(a[i]/(1ll<<(cnt[i]<<1ll)))&3);
    puts("");
    return 0;
}