#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int mod=998244353,maxn=3e5,G=3;
int t,n,ans,val[300001],fac[300001],inv[300001],lim,tr[1<<21],A[1<<21],B[1<<21];
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
const int invG=pw(G,mod-2);
inline int c(int x,int y)
{
    if(x<y||x<0||y<0)
        return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
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
        int len=p>>1,tg=pw(flag? G:invG,(mod-1)/p);
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
inline vector<int> mul(vector<int> &a,vector<int> &b)
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
    vector<int> res;
    for(int i=0;i<lena+lenb-1;++i)
        res.emplace_back(A[i]);
    return res;
}
int main()
{
    cin>>t;
    fac[0]=inv[0]=val[0]=1;
    for(int i=1;i<=maxn;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[maxn]=pw(fac[maxn],mod-2);
    for(int i=maxn-1;i;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    vector<int> a,b,res;
    a.resize(maxn+1);
    b.resize(maxn+1);
    a[0]=1;
    for(int i=2;i<=maxn;i+=2)
        a[i]=1ll*a[i-2]*inv[2]%mod;
    for(int i=0;i<=maxn;++i)
    {
        if(i&1^1)
            a[i]=1ll*a[i]*inv[i>>1]%mod;
        b[i]=inv[i];
    }
    res=mul(a,b);
    for(int i=0;i<=maxn;++i)
        val[i]=1ll*fac[i]*res[i]%mod;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=0;(i<<2)<=n;++i)
            ans=(ans+1ll*c(n-(i<<1),i<<1)*fac[i<<1]%mod*inv[i]%mod*val[n-(i<<2)]%mod)%mod;
        cout<<ans<<'\n';
    }
    return 0;
}