#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
const int mod=19260817,base=23333;
int n,cnt[1<<18],dp[21][1<<18],a[21][21],g[1<<18],h[1<<18],ha[19260817],p[21][1<<18],num[21],ans[1<<18],tot,s[21],lst;
inline void fwt_or(int *f,int n,int x)
{
    for(register int i=2;i<=n;i<<=1)
    {
        int len=i>>1;
        for(register int j=0;j<n;j+=i)
            for(register int k=j;k<j+len;++k)
                f[k+len]+=f[k]*x;
    }
}
inline void fwt_and(int *f,int n,int x)
{
    for(register int i=2;i<=n;i<<=1)
    {
        int len=i>>1;
        for(register int j=0;j<n;j+=i)
            for(register int k=j;k<j+len;++k)
                f[k]+=f[k+len]*x;
    }
}
void dfs(int k,int sum,int now)
{
    if(sum==n)
    {
        int res=0,pos=0;
        for(register int i=1;i<=now;++i)
            pos=(pos*base%mod+num[i])%mod;
        for(register int i=1;i<1<<n;++i)
        {
            h[i]=1;
            for(register int j=1;j<=now;++j)
                h[i]*=p[num[j]][i];
        }
        for(register int i=1;i<1<<n;++i)
            res+=(n-cnt[i])&1? -h[i]:h[i];
        ha[pos]=res;
        return;
    }
    for(register int i=k;i<=n-sum;++i)
    {
        num[now+1]=i;
        dfs(i,sum+i,now+1);
    }
}
signed main()
{
    scanf("%lld",&n);
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=n;++j)
        {
            char ch=getchar();
            while(ch!='0'&&ch!='1')
                ch=getchar();
            a[i][j]=ch-'0';
        }
    for(register int i=1;i<1<<n;++i)
        cnt[i]=cnt[i>>1]+(i&1);
    for(register int i=1;i<(1<<n);++i)
        for(register int j=1;j<=n;++j)
            if(i&(1<<(j-1)))
            {
                if(cnt[i]==1)
                {
                    dp[j][i]=1;
                    break;
                }
                for(register int k=1;k<=n;++k)
                    if(i&(1<<(k-1)))
                        dp[j][i]+=dp[k][i^(1<<(j-1))]*a[j][k];
            }
    for(register int i=1;i<1<<n;++i)
        for(register int j=1;j<=n;++j)
            g[i]+=dp[j][i];
    for(register int i=1;i<=n;++i)
    {
        for(register int j=0;j<1<<n;++j)
            if(cnt[j]==i)
                p[i][j]=g[j];
        fwt_or(p[i],1<<n,1);
    }
    dfs(1,0,0);
    for(register int i=0;i<1<<(n-1);++i)
    {
        tot=lst=0;
        for(register int j=1;j<n;++j)
            if(!(i&(1<<(j-1))))
            {
                s[++tot]=j-lst;
                lst=j;
            }
        s[++tot]=n-lst;
        sort(s+1,s+tot+1);
        int pos=0;
        for(register int j=1;j<=tot;++j)
            pos=(pos*base%mod+s[j])%mod;
        ans[i]=ha[pos];
    }
    fwt_and(ans,1<<(n-1),-1);
    for(register int i=0;i<1<<(n-1);++i)
        printf("%lld ",ans[i]);
    puts("");
    return 0;
}