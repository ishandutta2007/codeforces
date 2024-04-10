#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int mod=10007;
struct matrix
{
    int n,m,a[401][401];
    matrix()
    {
        n=m=0;
        memset(a,0,sizeof a);
    }
    inline void clear()
    {
        n=m=0;
        memset(a,0,sizeof a);
    }
    inline void init(int w)
    {
        n=m=w;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=w;++j)
                a[i][j]=i==j;
    }
}a,b;
inline int Mod(int x)
{
    return x>=mod? x-mod:x;
}
inline matrix operator *(matrix &x,matrix &y)
{
    matrix res;
    res.n=x.n;
    res.m=y.m;
    for(int i=1;i<=x.n;++i)
        for(int j=1;j<=i;++j)
            for(int k=1;k<=j;++k)
                res.a[i][k]=Mod(res.a[i][k]+1ll*x.a[i][j]*y.a[j][k]%mod);
    return res;
} 
int n,m,lim,dp[401][401][401],ans;
string s;
inline int calc(int x,int l,int r)
{
    if(x<0)
        return 0;
    if(dp[x][l][r]!=-1)
        return dp[x][l][r];
    if(l==1&&r==n)
        return dp[x][l][r]=!x;
    dp[x][l][r]=0;
    if(l>1&&s[l-1]!=s[r])
        dp[x][l][r]=Mod(dp[x][l][r]+calc(x-1,l-1,r));
    if(r<n&&s[l]!=s[r+1])
        dp[x][l][r]=Mod(dp[x][l][r]+calc(x-1,l,r+1));
    if(l>1&&r<n&&s[l-1]==s[r+1])
        dp[x][l][r]=Mod(dp[x][l][r]+calc(x,l-1,r+1));
    //cout<<x<<" "<<l<<" "<<r<<" "<<dp[x][l][r]<<'\n';
    return dp[x][l][r];
}
inline matrix pw(matrix a,int b)
{
    matrix res;
    res.init(a.n);
    while(b)
    {
        if(b&1)
            res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}
int main()
{
    cin>>s>>m;
    n=s.length();
    a.n=a.m=b.n=b.m=lim=n+((n+1)>>1);
    s=" "+s;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;++i)
    {
        int cnt=0;
        for(int j=1;j<=n;++j)
        {
            cnt=Mod(cnt+calc(i,j,j));
            if(j<n&&s[j]==s[j+1])
                cnt=Mod(cnt+calc(i,j,j+1));
        }
        if(i)
            a.a[lim-((n-i+1)>>1)][i]=cnt;
        else
            b.a[n][1]=cnt;
    }
    if(n>1)
        b.a[1][1]=1;
    for(int i=2;i<n;++i)
        a.a[i][i-1]=1;
    for(int i=n;i<lim;++i)
        a.a[i+1][i]=1;
    for(int i=1;i<n;++i)
        a.a[i][i]=24;
    for(int i=n;i<lim;++i)
        a.a[i][i]=25;
    a.a[lim][lim]=26;
    a=pw(a,(n+m+1)>>1);
    for(int i=1;i<=lim;++i)
        ans=Mod(ans+1ll*a.a[lim][i]*b.a[i][1]%mod)%mod;
    if((n+m)&1^1)
    {
        cout<<ans<<'\n';
        return 0;
    }
    a.clear();
    b.clear();
    a.n=a.m=b.n=b.m=lim;
    for(int i=0;i<n;++i)
    {
        int cnt=0;
        for(int j=1;j<=n;++j)
            if(j<n&&s[j]==s[j+1])
                cnt=Mod(cnt+calc(i,j,j+1));
        if(i)
            a.a[lim-((n-i+1)>>1)][i]=cnt;
        else
            b.a[n][1]=cnt;
    }
    if(n>1)
        b.a[1][1]=1;
    for(int i=2;i<n;++i)
        a.a[i][i-1]=1;
    for(int i=n;i<lim;++i)
        a.a[i+1][i]=1;
    for(int i=1;i<n;++i)
        a.a[i][i]=24;
    for(int i=n;i<lim;++i)
        a.a[i][i]=25;
    a=pw(a,(n+m+1)>>1);
    for(int i=1;i<=lim;++i)
        ans=Mod(ans-1ll*a.a[lim][i]*b.a[i][1]%mod+mod);
    cout<<ans<<'\n';
    return 0;
}