#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define int long long
#define forv(a,b) for(auto&a:b)
using namespace std;
const int N=3e5+10,mod=1e9+9;
int n,q,f[N],t[4*N],ma[4*N],mb[4*N],a[N],A=691504013,B=308495997,C=276601605,pwa[N],pwb[N],pa[N],pb[N];
int pw(int a,int i)
{
    int b=1;
    for(;i;i>>=1,a=a*a%mod) if(i&1) b=b*a%mod;
    return b;
}
void build(int s,int l,int r)
{
    if(l==r)
    {
        t[s]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
    t[s]=(t[2*s]+t[2*s+1])%mod;
}
void tran(int s,int l,int r)
{
    if(!ma[s]&&!mb[s]) return;
    int mid=(l+r)/2;
    int ca=ma[s]*pwa[mid-l+1]%mod;
    int cb=mb[s]*pwb[mid-l+1]%mod;
    ma[2*s]=(ma[2*s]+ma[s])%mod;
    mb[2*s]=(mb[2*s]+mb[s])%mod;
    t[2*s]=(t[2*s]+C*(ca-cb)%mod)%mod;
    ca=ma[s]*pwa[r-mid]%mod*pa[mid-l+1]%mod;
    cb=mb[s]*pwb[r-mid]%mod*pb[mid-l+1]%mod;
    ma[2*s+1]=(ma[2*s+1]+ma[s]*pa[mid-l+1]%mod)%mod;
    mb[2*s+1]=(mb[2*s+1]+mb[s]*pb[mid-l+1]%mod)%mod;
    t[2*s+1]=(t[2*s+1]+C*(ca-cb)%mod)%mod;
    ma[s]=mb[s]=0;
}
void update(int s,int l,int r,int u,int v)
{
    if(l>v||r<u) return;
    if(l>=u&&r<=v)
    {
        t[s]=(t[s]+f[r-u+1]-f[l-u])%mod;
        ma[s]=(ma[s]+pa[l-u])%mod;
        mb[s]=(mb[s]+pb[l-u])%mod;
        return;
    }
    tran(s,l,r);
    int mid=(l+r)/2;
    update(2*s,l,mid,u,v);
    update(2*s+1,mid+1,r,u,v);
    t[s]=(t[2*s]+t[2*s+1])%mod;
}
int get(int s,int l,int r,int u,int v)
{
    if(l>v||r<u) return 0;
    if(l>=u&&r<=v) return t[s];
    tran(s,l,r);
    int mid=(l+r)/2;
    return (get(2*s,l,mid,u,v)+get(2*s+1,mid+1,r,u,v))%mod;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("446.inp","r",stdin);
    cin>>n>>q;
    forinc(i,1,n) cin>>a[i];
    build(1,1,n);
    f[1]=f[2]=1;
    forinc(i,3,n) f[i]=(f[i-1]+f[i-2])%mod;
    forinc(i,2,n) f[i]=(f[i]+f[i-1])%mod;
    pa[0]=pb[0]=1;
    forinc(i,1,n)
    {
        pa[i]=(pa[i-1]*A)%mod;
        pb[i]=(pb[i-1]*B)%mod;
        pwa[i]=(pwa[i-1]+pa[i])%mod;
        pwb[i]=(pwb[i-1]+pb[i])%mod;
    }
    forinc(i,1,q)
    {
        int c,l,r;
        cin>>c>>l>>r;
        if(c==1) update(1,1,n,l,r);
        else cout<<(get(1,1,n,l,r)+mod)%mod<<"\n";
    }
}