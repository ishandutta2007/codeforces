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

const int mxn=1<<18,mod=998244353;
ll por(ll x,int y){ll res=1;for(;y;y>>=1){if(y&1)res=res*x%mod; x=x*x%mod;}return res;}
int n,m,R[mxn];ll jc[mxn],inv[mxn],w[2][mxn],S[mxn],p1[mxn],p2[mxn];
void ntt(ll a[],int n,int tp=0){
    for(int i=0;i<n;++i)if(i>R[i])swap(a[i],a[R[i]]);
    for(int d=1,t=mxn>>1;d<n;d*=2,t>>=1)for(int i=0;i<n;i+=d*2)for(int j=0;j<d;++j){
        ll tmp=w[tp][t*j]*a[i+j+d];a[i+j+d]=(a[i+j]-tmp)%mod,a[i+j]=(a[i+j]+tmp)%mod;
    }
    if(tp){ll iv=por(n,mod-2);for(int i=0;i<n;++i)a[i]=a[i]*iv%mod;}
}
int main(){
    n=mxn-1;jc[0]=inv[0]=1;for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;inv[n]=por(jc[n],mod-2);for(int i=n-1;i;--i)inv[i]=inv[i+1]*(i+1)%mod;
    n=mxn;w[0][0]=w[1][0]=1;w[0][1]=por(3,(mod-1)/n);w[1][1]=por(w[0][1],mod-2);for(int i=2;i<n;++i)w[0][i]=w[0][i-1]*w[0][1]%mod,w[1][i]=w[1][i-1]*w[1][1]%mod;
    scanf("%d%d",&m,&n);int N=1;while(N<=2*n)N*=2;for(int i=1;i<N;++i)R[i]=R[i>>1]>>1,R[i]|=(i&1)*(N>>1);
    for(int i=0,o=1;i<=n;++i,o*=-1)p1[i]=por(i,n)*inv[i]%mod,p2[i]=o*inv[i];ntt(p1,N),ntt(p2,N);for(int i=0;i<N;++i)S[i]=p1[i]*p2[i]%mod;ntt(S,N,1);
    ll ans=0,cj=1;for(int i=1;i<=n&&i<=m;++i)cj=cj*(m-i+1)%mod,ans+=cj*S[i]%mod*por(m+1,m-i)%mod;ans=(ans%mod+mod)%mod;printf("%lld\n",ans);
    return 0;
}