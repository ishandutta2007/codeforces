#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007,base=1145141,hashmod=998244853;
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%hashmod;
        b>>=1;
        a=1ll*a*a%hashmod;
    }
    return res;
}
const int inv=pw(base,hashmod-2);
string s[2],t;
int n,m,val1[2][2005],val2[2][2005],val3[2005],p[2005],invp[2005],ans,sum,dp1[2][2005][2005],dp2[2][2005][2005];
inline int calc1(int l,int r,int id)
{
    return 1ll*(val1[id][r]-val1[id][l-1]+hashmod)%hashmod*invp[l]%hashmod;
}
inline int calc2(int l,int r,int id)
{
    return 1ll*(val2[id][l]-val2[id][r+1]+hashmod)%hashmod*invp[n-r+1]%hashmod;
}
inline void solve()
{
    memset(dp1,0,sizeof dp1);
    memset(dp2,0,sizeof dp2);
    memset(val3,0,sizeof val3);
    for(int i=1;i<=m;++i)
        val3[i]=(val3[i-1]+1ll*(t[i]-'a'+1)*p[i]%hashmod)%hashmod;
    for(int i=0;i<2;++i)
        for(int j=1;j<=n;++j)
        {
            dp2[i][j][1]=s[i][j]==t[1];
            for(int k=j;k>=1;--k)
            {
                int len=(j-k+1)<<1;
                if(len>m)
                    break;
                if((calc2(k,j,i^1)+1ll*calc1(k,j,i)*p[j-k+1]%hashmod)%hashmod==1ll*val3[len]*inv%hashmod)
                    if(len==m)
                        ++sum;
                    else
                        dp2[i][j][len]=1;
            }
        }
    for(int k=1;k<m;++k)
        for(int j=1;j<=n;++j)
            for(int i=0;i<2;++i)
            {
                if(j<n&&s[i][j+1]==t[k+1])
                    dp1[i][j+1][k+1]=(dp1[i][j+1][k+1]+(dp1[i][j][k]+dp2[i][j][k])%mod)%mod;
                if(s[i^1][j]==t[k+1])
                    dp2[i^1][j][k+1]=(dp2[i^1][j][k+1]+dp1[i][j][k])%mod;
            }
    for(int i=m;i>=1;--i)
        val3[i]=(val3[i+1]+1ll*(t[i]-'a'+1)*p[m-i+1]%hashmod)%hashmod;
    for(int i=0;i<2;++i)
        for(int j=1;j<=n;++j)
        {
            if(s[i][j]==t[m])
                if(m==1)
                    ans=(ans+1)%mod;
                else
                    ans=(ans+(dp1[i][j-1][m-1]+dp2[i][j-1][m-1])%mod)%mod;
            for(int k=j;k<=n;++k)
            {
                int len=(k-j+1)<<1;
                if(len>m)
                    break;
                if((calc1(j,k,i^1)+1ll*calc2(j,k,i)*p[k-j+1]%hashmod)%hashmod==1ll*val3[m-len+1]*inv%hashmod)
                    if(len==m&&m!=2)
                        ++sum;
                    else
                        ans=(ans+(dp1[i][j-1][m-len]+dp2[i][j-1][m-len])%mod)%mod;
            }
        }
}
int main()
{
    cin>>s[0]>>s[1]>>t;
    n=s[0].length(),m=t.length();
    s[0]=" "+s[0];
    s[1]=" "+s[1];
    t=" "+t;
    p[0]=invp[0]=1;
    for(int i=1;i<=max(n,m);++i)
    {
        p[i]=1ll*p[i-1]*base%hashmod;
        invp[i]=1ll*invp[i-1]*inv%hashmod;
    }
    for(int i=0;i<2;++i)
        for(int j=1;j<=n;++j)
            val1[i][j]=(val1[i][j-1]+1ll*(s[i][j]-'a'+1)*p[j]%hashmod)%hashmod;
    for(int i=0;i<2;++i)
        for(int j=n;j>=1;--j)
            val2[i][j]=(val2[i][j+1]+1ll*(s[i][j]-'a'+1)*p[n-j+1]%hashmod)%hashmod;
    solve();
    reverse(t.begin()+1,t.end());
    solve();
    ans=(ans+1ll*sum*((mod+1)>>1)%mod)%mod;
    if(m==1)
        ans=1ll*ans*((mod+1)>>1)%mod;
    cout<<ans<<'\n';
    return 0;
}