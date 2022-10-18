#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[2000001];
bool ans[2000001];
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
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    for(int len=1;len<=min(n-m,21);++len)
        for(int i=1,j=len;j<=n;++i,++j)
        {
            int sum=0;
            for(int k=i+1;k<=j;++k)
                sum+=a[k];
            if(sum>=20)
                continue;
            if(1ll*a[i]*(1ll<<sum)>=(1<<20))
                continue;
            sum=a[i]*(1<<sum);
            if(i==1&&j==n)
            {
                ans[sum]^=1;
                continue;
            }
            if(i==1||j==n)
            {
                if(n-len-1==0||(m-1>0&&((n-len-2)&(m-2))==m-2))
                    ans[sum]^=1;
                continue;
            }
            if(n-len-2==0||(m-2>0&&((n-len-3)&(m-3))==m-3))
                ans[sum]^=1;
        }
    bool flag=0;
    for(int i=(1<<20)-1;i>=0;--i)
    {
        if(ans[i])
            flag=1;
        if(flag)
            cout<<ans[i];
    }
    if(!flag)
        cout<<0;
    cout<<'\n';
    return 0;
}