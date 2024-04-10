#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int mod=1000000007;
int n,m,root,dp[501][1<<16],a[1<<16],b[1<<16],tot,ch[501][2],q[16][5];
string str;
inline void FMTand(int *x,int *y,int *z)
{
    for(int s=0;s<1<<n;++s)
    {
        a[s]=x[s];
        b[s]=y[s];
    }
    for(int i=0;i<n;++i)
        for(int s=0;s<1<<n;++s)
            if(!(s>>i&1))
            {
                a[s]=(a[s]+a[s^(1<<i)])%mod;
                b[s]=(b[s]+b[s^(1<<i)])%mod;
            }
    for(int s=0;s<1<<n;++s)
        a[s]=1ll*a[s]*b[s]%mod;
    for(int i=0;i<n;++i)
        for(int s=0;s<1<<n;++s)
            if(!(s>>i&1))
                a[s]=(a[s]-a[s^(1<<i)]+mod)%mod;
    for(int s=0;s<1<<n;++s)
        z[s]=(z[s]+a[s])%mod;
}
inline void FMTor(int *x,int *y,int *z)
{
    for(int s=0;s<1<<n;++s)
    {
        a[s]=x[s];
        b[s]=y[s];
    }
    for(int i=0;i<n;++i)
        for(int s=0;s<1<<n;++s)
            if(s>>i&1)
            {
                a[s]=(a[s]+a[s^(1<<i)])%mod;
                b[s]=(b[s]+b[s^(1<<i)])%mod;
            }
    for(int s=0;s<1<<n;++s)
        a[s]=1ll*a[s]*b[s]%mod;
    for(int i=0;i<n;++i)
        for(int s=0;s<1<<n;++s)
            if(s>>i&1)
                a[s]=(a[s]-a[s^(1<<i)]+mod)%mod;
    for(int s=0;s<1<<n;++s)
        z[s]=(z[s]+a[s])%mod;
}
inline void solve(int &k,int l,int r)
{
    k=++tot;
    if(l==r)
    {
        if(str[l]>='A'&&str[l]<='D')
        {
            int s=0;
            for(int i=0;i<n;++i)
                if(q[i][str[l]-'A'])
                    s|=1<<i;
            dp[tot][s]=1;
        }
        else if(str[l]>='a'&&str[l]<='d')
        {
            int s=0;
            for(int i=0;i<n;++i)
                if(!q[i][str[l]-'a'])
                    s|=1<<i;
            dp[tot][s]=1;
        }
        else
            for(int i=0;i<4;++i)
            {
                int s=0;
                for(int j=0;j<n;++j)
                    if(q[j][i])
                        s|=1<<j;
                dp[tot][s]=(dp[tot][s]+1)%mod;
                s=0;
                for(int j=0;j<n;++j)
                    if(!q[j][i])
                        s|=1<<j;
                dp[tot][s]=(dp[tot][s]+1)%mod;
            }
        return;
    }
    int tmp=0;
    for(int i=l;i<=r;++i)
    {
        if(str[i]=='(')
            ++tmp;
        if(str[i]==')')
            --tmp;
        if(!tmp)
        {
            solve(ch[k][0],l+1,i-1);
            solve(ch[k][1],i+3,r-1);
            if(str[i+1]!='|')
                FMTand(dp[ch[k][0]],dp[ch[k][1]],dp[k]);
            if(str[i+1]!='&')
                FMTor(dp[ch[k][0]],dp[ch[k][1]],dp[k]);
            return;
        }
    }
}
int main()
{
    cin>>str>>n;
    m=str.length();
    str=" "+str;
    int s=0;
    for(int i=0;i<n;++i)
    {
        cin>>q[i][0]>>q[i][1]>>q[i][2]>>q[i][3]>>q[i][4];
        s|=q[i][4]<<i;
    }
    solve(root,1,m);
    cout<<dp[root][s]<<'\n';
    return 0;
}