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

const int mxn=5e5+3,mxm=1e7+3,mod=1e9+7;
int n,a[mxn],m;
int t1[mxm],t2[mxm];
int pr[mxm],pt,v[mxm],mu[mxm];
int bin[mxn];

int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i),m=max(m,a[i]);
    mu[1]=1;
    for(rint i=2;i<mxm;++i){
        if(!v[i])pr[++pt]=i,v[i]=i,mu[i]=-1;
        for(rint j=1;j<=pt&&pr[j]*i<mxm&&pr[j]<=v[i];++j){
            v[i*pr[j]]=pr[j];
            
            if(pr[j]!=v[i])mu[i*pr[j]]=-mu[i];
        }
    }


    for(int i=1;i<=n;++i)++t2[a[i]];
    for(rint i=1;i<=pt;++i){
        for(rint j=m/pr[i];j;--j)t2[j]=(t2[j]+t2[j*pr[i]])%mod;
    }
    
    bin[0]=1;for(int i=1;i<=n;++i)bin[i]=bin[i-1]*2%mod;
    for(int i=1;i<=m;++i)t1[i]=bin[t2[i]]-1;
    
    long long tmp=0;
    for(int i=1;i<=m;++i)tmp+=mu[i]*t1[i];
    tmp%=mod;
    t1[1]-=tmp;
    long long ans=0;
    for(rint i=1;i<=m;++i)ans+=1ll*mu[i]*t1[i]*t2[i]%mod;
    ans%=mod;if(ans<0)ans+=mod;
    printf("%lld\n",ans);
    return 0;
}