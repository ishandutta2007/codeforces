//2019.5.8 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
#define RG register
inline int read() {
    res s=0,ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s;
}
inline LL Read() {
    RG LL s=0;
    res ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s;
}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
const int kcz=998244353;
const int G=3,GI=332748118;
const int N=1e5+10;
namespace MAIN {
    int pos[N<<2];
    inline int mul(const res &x,const res &y){
        return int(1LL*x*y%kcz);
    }
    inline int Add(const res &x,const res &y){
        return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
    }
    inline void add(res &x,const res &y){
        x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
    }
    inline int qpow(res x,res y){
        res ret=1;
        while(y){
            if(y&1)ret=mul(ret,x);
            y>>=1,x=mul(x,x);
        }
        return ret;
    }
    int Og[N<<2];
    inline void FFT(res *A,const res &type,const res &lim){
        for(res i=0;i<lim;i++)if(i<pos[i])swap(A[i],A[pos[i]]);
        for(res mid=1;mid<lim;mid<<=1){
            res wn=qpow(type==1?G:GI,(kcz-1)/(mid<<1));
            Og[0]=1;
            for(res i=1;i<mid;i++)Og[i]=mul(Og[i-1],wn);
            for(res j=0;j<lim;j+=mid<<1)
                for(res k=0;k<mid;k++){
                    res x=A[j+k],y=mul(A[j+mid+k],Og[k]);
                    A[j+k]=Add(x,y),A[j+mid+k]=Add(x,-y);
                }
        }
        if(type==-1){
            res INV=qpow(lim,kcz-2);
            for(res i=0;i<lim;i++)A[i]=mul(A[i],INV);
        }
    }
    int n,m;
    int inv[N],fac[N];
    int p[N<<2],f[N<<2];
    inline void MAIN(){
        n=read(),m=int(Read()%(kcz-1)),fac[0]=fac[1]=inv[0]=inv[1]=1;
        for(res i=2;i<=n;i++)fac[i]=mul(fac[i-1],i),inv[i]=mul(inv[kcz%i],kcz-kcz/i);
        for(res i=2;i<=n;i++)inv[i]=mul(inv[i-1],inv[i]);
        res l=1,qaq=0;
        while(l<=(n+1)*2)l<<=1,qaq++;
        for(res i=0;i<l;i++)pos[i]=(pos[i>>1]>>1)|((i&1)<<(qaq-1));
        for(res i=0;i<=n;i++)p[n-i]=mul(read(),fac[i]),f[i]=inv[i];
        FFT(p,1,l),FFT(f,1,l);
        for(res i=0;i<l;i++)p[i]=mul(p[i],f[i]);
        FFT(p,-1,l);
        for(res i=0;i<=n;i++)p[n-i]=mul(p[n-i],qpow(qpow(i+1,m),kcz-2)),f[i]=(i&1)?kcz-inv[i]:inv[i];
        for(res i=n+1;i<l;i++)p[i]=f[i]=0;
        FFT(p,1,l),FFT(f,1,l);
        for(res i=0;i<l;i++)p[i]=mul(p[i],f[i]);
        FFT(p,-1,l);
        for(res i=0;i<=n;i++)printf("%d ",mul(p[n-i],inv[i]));
    }
}
int main() {
//    srand((unsigned)time(NULL));
//    freopen("graph.in","r",stdin);
//    freopen("graph.out","w",stdout);
    MAIN::MAIN();
    return 0;
}