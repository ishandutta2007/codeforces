#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1<<17,mod=1e9+7,V2=(mod+1)/2;
int n,b[mxn];ll d0[18][mxn],d1[mxn],d2[mxn],d3[mxn],fb[mxn];
int cb(int x){int re=0;while(x)++re,x-=x&-x;return re;}
void AND(ll a[],int tp=1){
    for(int d=1;d<n;d*=2)for(int i=0;i<n;i+=d*2)for(int j=0;j<d;++j){
        if(tp)(a[i+j]+=a[i+j+d])%=mod;else (a[i+j]-=a[i+j+d])%=mod;
    }
}
void OR(ll a[],int tp=1){
    for(int d=1;d<n;d*=2)for(int i=0;i<n;i+=d*2)for(int j=0;j<d;++j){
        if(tp)(a[i+j+d]+=a[i+j])%=mod;else (a[i+j+d]-=a[i+j])%=mod;
    }
}
void XOR(ll a[],int tp=1){
    for(int d=1;d<n;d*=2)for(int i=0;i<n;i+=d*2)for(int j=0;j<d;++j){
        ll t=a[i+j+d];a[i+j+d]=(a[i+j]-t)%mod,a[i+j]=(a[i+j]+t)%mod;
        if(!tp)a[i+j+d]=a[i+j+d]*V2%mod,a[i+j]=a[i+j]*V2%mod;
    }
}
void JJ(){
    for(int i=0;i<n;++i)d0[cb(i)][i]=b[i];
    for(int i=0;i<18;++i)OR(d0[i]);
    for(int k=17;~k;--k){
        for(int i=0;i<n;++i)d0[k][i]=(k?2:1)*d0[k][i]*d0[0][i]%mod;
        for(int j=1;j<k;++j)for(int i=0;i<n;++i)(d0[k][i]+=d0[j][i]*d0[k-j][i])%=mod;
        OR(d0[k],0);
    }
    for(int i=0;i<n;++i)d1[i]=d0[cb(i)][i];
}

int main(){
    scanf("%d",&n);for(int i=1,x;i<=n;++i)scanf("%d",&x),++b[x];n=1<<17;
    JJ();for(int i=0;i<n;++i)d2[i]=d3[i]=b[i];XOR(d2);for(int i=0;i<n;++i)d2[i]=d2[i]*d2[i]%mod;XOR(d2,0);
    fb[1]=1;for(int i=2;i<n;++i)fb[i]=(fb[i-1]+fb[i-2])%mod;
    for(int i=0;i<n;++i)d1[i]=d1[i]*fb[i]%mod,d2[i]=d2[i]*fb[i]%mod,d3[i]=d3[i]*fb[i]%mod;
    AND(d1),AND(d2),AND(d3);for(int i=0;i<n;++i)d1[i]=d1[i]*d2[i]%mod*d3[i]%mod;AND(d1,0);
    ll ans=0; for(int i=1;i<n;i*=2)ans+=d1[i];
    ans=(ans%mod+mod)%mod;printf("%lld\n",ans);
    return 0;
}