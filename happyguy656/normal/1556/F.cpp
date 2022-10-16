#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int abc;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mod=1e9+7,mxn=1<<14;
ll por(ll x,int y=mod-2){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
int U,n,c1[1<<14],db[1<<14];
ll sm[14][1<<14],vv[14],a[mxn],b[mxn],v[14][14],ans;
ll cal(int z1,int z2){
    ll r=1;
    for(int i=0;i<n;++i)if(z1>>i&1)r=r*sm[i][z2]%mod;
    return r;
}
int main(){
    cin>>n;U=1<<n,--U;for(int i=1;i<=U;++i)c1[i]=c1[i^(i&-i)]+1;for(int i=0;i<n;++i)cin>>vv[i];for(int i=0;i<n;++i)for(int j=0;j<n;++j)v[i][j]=vv[i]*por(vv[i]+vv[j])%mod;
    for(int i=0;i<n;++i)db[1<<i]=i;
    for(int i=0;i<n;++i){sm[i][0]=1;for(int j=0;j<n;++j)sm[i][1<<j]=v[i][j];for(int z=1,zz;z<=U;++z)zz=z&-z,sm[i][z]=sm[i][z^zz]*sm[i][zz]%mod;}
    for(int z=1;z<=U;++z){
        a[z]=1;
        for(int zz=(z-1)&z;zz;--zz,zz&=z)a[z]-=cal(zz,zz^z)*a[zz^z],a[z]%=mod;
    }
    /*
    for(int z=1;z<=U;++z)for(int zz=U^z;zz;--zz,zz&=U^z)a[z]-=a[zz]*
    for(int i=1;i<=U;++i)if(c1[i]&1)a[i]=-a[i];
    memcpy(b,a,sizeof(a));
    for(int i=0;i<14;++i)for(int z=0;z<=U;++z)if(z>>i&1)(a[z]+=a[z^(1<<i)])%=mod;*/
    for(int z=1;z<=U;++z){
        ll x=a[z]*cal(z,U^z)%mod;
        ans+=x*c1[z],ans%=mod;
        /*
        d[z]=(a[z]-b[z])*b[z]%mod;
        if(c1[z]&1)d[z]-=b[z];else d[z]+=b[z];
 //       if(c1[z]&1)d[z]=-d[z];
        cout<<d[z]<<endl;
        ans+=d[z]*c1[z],ans%=mod;*/
    }
    ans=(ans+mod)%mod;printf("%lld\n",ans);
    return 0;
}