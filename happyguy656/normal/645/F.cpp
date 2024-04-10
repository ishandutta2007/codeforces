#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}
typedef long long ll;
const int mxn=2e5+3,mod=1e9+7,mxm=1e6+3;
inline ll por(ll x,int y){ll res=1;for(;y;y>>=1){if(y&1)res=res*x%mod;x=x*x%mod;} return res;}

int n,Q,k;ll jc[mxn],inv[mxn];
int ph[mxm],pr[mxm],pt,bv[mxm];
inline ll C(int x,int y){if(x<y)return 0; return jc[x]*inv[y]%mod*inv[x-y]%mod;}
int cnt[mxm];ll ans;
inline void add(int x){
    ans+=(C(cnt[x]+1,k)-C(cnt[x],k))*ph[x]%mod;
    ++cnt[x];
}
int main(){
    jc[0]=inv[0]=1;for(int i=1;i<mxn;++i)jc[i]=jc[i-1]*i%mod;inv[mxn-1]=por(jc[mxn-1],mod-2);
    for(int i=mxn-2;i;--i)inv[i]=inv[i+1]*(i+1)%mod;
    ph[1]=1;
    for(int i=2;i<mxm;++i){
        if(!bv[i])bv[i]=i,pr[++pt]=i,ph[i]=i-1;
        for(int j=1;j<=pt&&i*pr[j]<mxm&&pr[j]<=bv[i];++j){
            bv[i*pr[j]]=pr[j];
            ph[i*pr[j]]=ph[i]*(pr[j]!=bv[i]?pr[j]-1:pr[j]);
        }
    }
    scanf("%d%d%d",&n,&k,&Q);
    for(int T=1;T<=n+Q;++T){
        int x;scanf("%d",&x);
        for(int i=1;i*i<=x;++i)if(x%i==0){
            add(i);if(i*i!=x)add(x/i);
        }
        if(T>n)ans=(ans%mod+mod)%mod,printf("%lld\n",ans);
    }
    return 0;
}