//2019.2.8 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int kcz=998244353;
const int N=4e5+10;
const int G=3,GI=332748118;
namespace MAIN{
    int n,m;
    inline int qpow(res x,res y){
        res ret=1;
        while(y){
            if(y&1)ret=1LL*x*ret%kcz;
            x=1LL*x*x%kcz,y>>=1;
        }
        return ret;
    }
    inline void add(res &x,const res &y){
        x+=y,x>=kcz?x-=kcz:1,x<0?x+=kcz:1;
    }
    inline int Add(const res &x,const res &y){
        return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
    }
    int pos[N],Og[N];
    inline void NTT(res *A,const res &type,const res &lim){
        for(res i=0;i<lim;i++)if(i<pos[i])_swap(A[i],A[pos[i]]);
        for(res mid=1;mid<lim;mid<<=1){
            res wn=qpow(type==1?G:GI,(kcz-1)/(mid<<1));
            Og[0]=1;
            for(res j=1;j<mid;++j)Og[j]=1LL*Og[j-1]*wn%kcz;
            for(res j=0;j<lim;j+=mid<<1){
                res w=1;
                for(res k=0;k<mid;k++){
                    res x=A[j+k],y=1LL*Og[k]*A[j+mid+k]%kcz;
                    A[j+k]=Add(x,y),A[j+mid+k]=Add(x,kcz-y);
                }
            }
        }
        if(type==-1){
            res INV=qpow(lim,kcz-2);
            for(res i=0;i<=lim;i++)A[i]=1LL*A[i]*INV%kcz;
        }
    }
    int A[N],B[N];
    void getinv(res *a,res *b,res lim){
        if(lim==1){b[0]=qpow(a[0],kcz-2);return;}
        getinv(a,b,lim>>1);
        for(res i=0;i<lim;i++)A[i]=a[i],B[i]=b[i];
        res qaq=0,len=1;
        while(len<=lim)len<<=1,qaq++;
        for(res i=0;i<len;i++)pos[i]=(pos[i>>1]>>1)|((i&1)<<(qaq-1));
        NTT(A,1,len),NTT(B,1,len);
        for(res i=0;i<len;i++)A[i]=1LL*A[i]*B[i]%kcz*B[i]%kcz;
        NTT(A,-1,len);
        for(res i=0;i<lim;i++)b[i]=Add(b[i],Add(b[i],kcz-A[i]));
        for(res i=0;i<len;i++)A[i]=B[i]=0;
    }
    int F[N],G[N];
    void getsqrt(res *a,res *b,const res &lim){
        if(lim==1){b[0]=1;return;}
        getsqrt(a,b,lim>>1);
        getinv(b,G,lim);
        for(res i=0;i<lim;i++)F[i]=a[i];
        res qaq=0,len=1;
        while(len<=lim)len<<=1,qaq++;
        for(res i=0;i<len;i++)pos[i]=(pos[i>>1]>>1)|((i&1)<<(qaq-1));
        NTT(F,1,len),NTT(G,1,len);
        for(res i=0,INV2=qpow(2,kcz-2);i<len;i++)F[i]=1LL*F[i]*G[i]%kcz*INV2%kcz;
        NTT(F,-1,len);
        for(res i=0,INV2=qpow(2,kcz-2);i<lim;i++)b[i]=Add(1LL*b[i]*INV2%kcz,F[i]);
        for(res i=0;i<len;i++)F[i]=G[i]=0;
    }
    int a[N],b[N];
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=n;i++){
            res x=read();
            if(x>m)continue;
            a[x]++;
        }
        for(res i=0;i<=m;i++)a[i]=Add(-4*a[i],kcz);
        a[0]++;
        res l=1;
        while(l<=m)l<<=1;
        getsqrt(a,b,l);
        b[0]=Add(b[0],1);
        memset(a,0,sizeof(a));
        getinv(b,a,l);
        for(res i=1;i<=m;i++)printf("%lld\n",1LL*a[i]*2%kcz);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}