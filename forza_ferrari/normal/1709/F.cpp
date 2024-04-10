#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int mod=998244353,g=3;
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
const int invg=pw(g,mod-2);
int n,m,p,tr[1<<20],A[1<<20],B[1<<20];
vector<int> dp[21];
inline void init(int n)
{
    for(int i=0;i<n;++i)
        tr[i]=(tr[i>>1]>>1)|(i&1? n>>1:0);
}
inline void NTT(int *f,int n,bool flag)
{
    for(int i=0;i<n;++i)
        if(i<tr[i])
            swap(f[i],f[tr[i]]);
    for(int p=2;p<=n;p<<=1)
    {
        int len=p>>1,tg=pw(flag? g:invg,(mod-1)/p);
        for(int k=0;k<n;k+=p)
        {
            int buf=1;
            for(int l=k;l<k+len;++l)
            {
                int tt=1ll*buf*f[l+len]%mod;
                f[l+len]=(f[l]-tt+mod)%mod;
                f[l]=(f[l]+tt)%mod;
                buf=1ll*buf*tg%mod;
            }
        }
    }
    if(!flag)
    {
        int inv=pw(n,mod-2);
        for(int i=0;i<n;++i)
            f[i]=1ll*f[i]*inv%mod;
    }
}
inline void mul(vector<int> &a,vector<int> &b,vector<int> &res)
{
    int lena=a.size(),lenb=b.size(),lim=1;
    for(;lim<lena+lenb;lim<<=1);
    for(int i=0;i<lim;++i)
        A[i]=B[i]=0;
    for(int i=0;i<lena;++i)
        A[i]=a[i];
    for(int i=0;i<lenb;++i)
        B[i]=b[i];
    init(lim);
    NTT(A,lim,1);
    NTT(B,lim,1);
    for(int i=0;i<lim;++i)
        A[i]=1ll*A[i]*B[i]%mod;
    NTT(A,lim,0);
    res.resize(lena+lenb-1);
    for(int i=0;i<lena+lenb-1;++i)
        res[i]=A[i];
}
inline void dfs(int k)
{
    if(k==n)
    {
        dp[k].resize(m+1,1);
        return;
    }
    dfs(k+1);
    vector<int> res;
    mul(dp[k+1],dp[k+1],res);
    int sum=0;
    dp[k].resize(m+1);
    for(int i=(int)res.size()-1;i>=0;--i)
    {
        if(i<=m)
            dp[k][i]=(1ll*(m-i+1)*res[i]%mod+sum)%mod;
        sum=(sum+res[i])%mod;
    }
}
int main()
{
    cin>>n>>m>>p;
    if(m+m<p)
    {
        cout<<"0\n";
        return 0;
    }
    dfs(1);
    vector<int> res;
    mul(dp[1],dp[1],res);
    cout<<res[p]<<'\n';
    return 0;
}