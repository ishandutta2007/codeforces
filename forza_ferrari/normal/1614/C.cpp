#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct opt
{
    int l,r,val;
}q[200001];
int t,n,m,a[200001],tot,h[200001],sum[200005],ans[200005],cnt[2],res;
const int mod=1000000007;
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
void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
int main()
{
    t=read();
    while(t--)
    {
        res=0;
        n=read(),m=read();
        for(int i=1;i<=m;++i)
            q[i].l=read(),q[i].r=read(),q[i].val=read();
        for(int i=29;~i;--i)
        {
            for(int j=1;j<=n;++j)
                ans[j]=sum[j]=0;
            for(int j=1;j<=m;++j)
                if(!(q[j].val&(1<<i)))
                {
                    ++sum[q[j].l];
                    --sum[q[j].r+1];
                }
            for(int j=1;j<=n;++j)
            {
                sum[j]+=sum[j-1];
                ans[j]=ans[j-1]+(bool)sum[j];
            }
            for(int j=1;j<=n;++j)
                if(ans[j]-ans[j-1])
                    a[j]=0;
                else
                    a[j]=1;
            cnt[0]=1;
            cnt[1]=0;
            for(int j=1;j<=n;++j)
            {
                int tmp0=cnt[0],tmp1=cnt[1];
                if(a[j])
                {
                    cnt[0]+=tmp1;
                    cnt[1]+=tmp0;
                }
                else
                {
                    cnt[0]+=tmp0;
                    cnt[1]+=tmp1;
                }
                cnt[0]%=mod;
                cnt[1]%=mod;
            }
            cnt[0]=(cnt[0]-1+mod)%mod;
            res=(res+1ll*cnt[1]*(1<<i)%mod)%mod;
        }
        print(res);
        putchar('\n');
    }
    return 0;
}