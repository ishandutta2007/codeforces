#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,minn[101],bin[101],s[101],dp[101],f[101],fac[101],inv[101],ans;
pair<int,int> a[101];
vector<int> v[101],tmp;
bool vis[101],flag;
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
    {
        bin[y]=x;
        s[x]+=s[y];
    }
}
inline int dis(int x,int y)
{
    return abs(a[x].first-a[y].first)+abs(a[x].second-a[y].second);
}
inline void dfs(int k,int val)
{
    tmp.emplace_back(k);
    vis[k]=1;
    for(int i:v[k])
    {
        if(minn[i]<val)
            flag=0;
        if(vis[i])
            continue;
        for(auto j:tmp)
            if(find(v[i].begin(),v[i].end(),j)==v[i].end())
            {
                flag=0;
                break;
            }
        if(minn[i]==val)
            dfs(i,val);
    }
}
inline int c(int x,int y)
{
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    cin>>n;
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].first>>a[i].second;
        s[i]=1;
        fac[i]=1ll*fac[i-1]*i%mod;
    }
    inv[n]=pw(fac[n],mod-2);
    for(int i=n-1;i>=1;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    for(int i=1;i<=n;++i)
    {
        minn[i]=1e9;
        for(int j=1;j<=n;++j)
            if(i!=j)
            {
                int val=dis(i,j);
                if(val<minn[i])
                {
                    minn[i]=val;
                    v[i].clear();
                    v[i].emplace_back(j);
                }
                else if(val==minn[i])
                    v[i].emplace_back(j);
            }
    }
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            tmp.clear();
            flag=1;
            dfs(i,minn[i]);
            if(flag)
                for(auto j:tmp)
                    link(i,j);
        }
    dp[0]=1;
    for(int i=1;i<=n;++i)
        if(anc(i)==i)
        {
            for(int j=0;j<=n;++j)
            {
                f[j]=dp[j];
                dp[j]=0;
            }
            for(int j=n;j>=s[i];--j)
                dp[j]=(dp[j]+f[j-s[i]])%mod;
            if(s[i]^1)
                for(int j=n;j>=1;--j)
                    dp[j]=(dp[j]+f[j-1])%mod;
        }
    for(int i=1;i<=n;++i)
        ans=(ans+1ll*c(n,i)*fac[i]%mod*dp[i]%mod)%mod;
    cout<<ans<<'\n';
    return 0;
}