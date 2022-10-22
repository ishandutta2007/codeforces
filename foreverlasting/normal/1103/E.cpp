//2019.2.20 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _abs(const res &x) {
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
#define ull unsigned LL
const int pw[]={1,10,100,1000,10000,100000,1000000};
const ull INV5=14757395258967641293ull;
const ull kcz=1ull<<58;
namespace MAIN {
    int n;
    struct cp{
        ull a[5];
        cp() {a[0]=a[1]=a[2]=a[3]=a[4]=0;}
    }w10[10],a[100000+10];
    inline cp operator + (const cp &x,const cp &y){
        cp z;
        for(res i=0;i<=4;i++)z.a[i]=x.a[i]+y.a[i];
        return z;
    }
    inline cp operator - (const cp &x,const cp &y){
        cp z;
        for(res i=0;i<=4;i++)z.a[i]=x.a[i]-y.a[i];
        return z;
    }
    inline cp operator * (const cp &x,const ull &y){
        cp z;
        for(res i=0;i<=4;i++)z.a[i]=x.a[i]*y;
        return z;
    }
    inline cp operator * (const cp &x,const cp &y){
        ull b[9];
        for(res i=0;i<=8;i++)b[i]=0;
        for(res i=0;i<=4;i++)
            for(res j=0;j<=4;j++)b[i+j]+=x.a[i]*y.a[j];
        for(res i=3;~i;i--)b[i]+=b[i+5],b[i+5]=0;
        cp z;
        for(res i=0;i<=4;i++)z.a[i]=b[i];
        return z;
    }
    inline void pre(){
        w10[0].a[0]=1,w10[1].a[3]=-1;
        for(res i=2;i<10;i++)w10[i]=w10[i-1]*w10[1];
    }
    inline void FFT(cp *A,const res &type,const res &lim){
        for(res mid=0;mid<5;mid++){
            for(res i=0;i<lim;i++)
                if((i/pw[mid])%10==0){
                    cp b[10];
                    for(res j=0;j<10;j++)
                        for(res k=0;k<10;k++)
                            b[j]=b[j]+A[i+k*pw[mid]]*w10[(type*j*k%10+10)%10];
                    for(res j=0;j<10;j++)
                        A[i+j*pw[mid]]=b[j];
                }
        }
        if(type==-1){
            ull INV=INV5*INV5*INV5*INV5*INV5;
            for(res i=0;i<lim;i++)A[i]=A[i]*INV;
        }
    }
    inline cp qpow(cp x,res y){
        cp ret=w10[0];
        while(y){
            if(y&1)ret=ret*x;
            x=x*x,y>>=1;
        }
        return ret;
    }
    inline void MAIN(){
        pre();
        n=read();
        for(res i=1;i<=n;i++)a[read()].a[0]++;
        FFT(a,1,100000);
        for(res i=0;i<100000;i++)a[i]=qpow(a[i],n);
        FFT(a,-1,100000);
        for(res i=0;i<n;i++)printf("%llu\n",((a[i].a[0]-a[i].a[4])/32)%kcz);
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}