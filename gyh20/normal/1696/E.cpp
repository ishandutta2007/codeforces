#include<cstdio>
#define re register
using namespace std;
inline int read(){
    re int t=0;re char v=getchar();
    while(v<'0')v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return t;
}
const int M=1e9+7;
int fac[1000002],inv[1000002],n,m,a[200002],ans;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
    re int s=1;
    while(y){
        if(y&1)s=1ll*s*x%M;
        x=1ll*x*x%M,y>>=1;
    }
    return s;
}
inline int C(re int x,re int y){if(x<y)return 0;return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
int main(){
    n=1e6;
    for(re int i=fac[0]=inv[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
    n=read();
    for(re int i=1;i<=n+1;++i)a[i]=read();
    for(re int i=1;i<=n+1;++i)add(ans,C(i-1+a[i],i));
    printf("%d",ans);
}