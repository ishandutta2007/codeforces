//2018.9.7 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
#define RG register
namespace io{
    const int MAXBUF=1<<15;
    const int OUTPUT=1<<24;
    char b[MAXBUF],*S=b,*T=b;
#define getc() (S==T&&(T=(S=b)+fread(b,1,MAXBUF,stdin),S==T)?0:*S++)
#define O(x) __attribute__((optimize("-O"#x)))
#define inline __inline__ __attribute__((always_inline))
    template<class Type> inline Type read(){
        RG Type aa=0;
        RG bool bb=0;
        RG char ch,*S=io::S,*T=io::T;
        for(ch=getc();(ch<'0'||ch>'9')&&ch!='-';ch=getc());
        for(ch=='-'?bb=1:aa=ch-'0',ch=getc();'0'<=ch&&ch<='9';ch=getc())aa=aa*10+ch-'0';
        io::S=S,io::T=T;
        return bb?-aa:aa;
    }
    inline int gets(RG char *s){
        RG char *iter=s,*S=io::S,*T=io::T;
        while(*iter=getc(),*iter==' '||*iter=='\n'||*iter=='\r');
        while(*++iter=getc(),*iter&&*iter!=' '&&*iter!='\n'&&*iter!='\r');
        *iter=0;
        io::S=S,io::T=T;
        return iter-s;
    }
    char buff[OUTPUT],*iter=buff;
    template<class T> inline void P(RG T x, RG char ch = '\n'){
        static int ST[110];
        res O=0;
        RG char *iter=io::iter;
        if(!x)*iter++='0';
        else{
            (x<0)?x=-x,*iter++='-':1;
            for(;x;x/=10)ST[++O]=x%10;
            for(;O;*iter++='0'+ST[O--]);
        }
        *iter++=ch,io::iter=iter;
    }
    inline void output(){fwrite(buff, 1, iter - buff, stdout),iter=buff;}
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
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=4e3+10;
namespace MAIN{
    int n,k;
    int sum[N][N];
    int dp[N],siz[N];
    struct Queue{
        int x,l,r;
        Queue() {}
        Queue(res x,res l,res r):x(x),l(l),r(r) {}
    }Q[N];
    int he,ta;
    inline void init(){
        dp[0]=siz[0]=ta=0;
        he=1;
    }
    inline int func(res i,res j,res lim){
        return (sum[i][i]+sum[j][j]-sum[i][j]*2)/2+lim+dp[j];
    }
    inline void calc(res lim){
        init();
        Q[++ta]=Queue(0,1,n);
        for(res i=1;i<=n;i++) {
            while(he<ta&&Q[he].r<i)he++;
            dp[i]=func(i,Q[he].x,lim),siz[i]=siz[Q[he].x]+1;
            if(func(n,i,lim)>=func(n,Q[ta].x,lim))continue;
            while(he<ta&&func(Q[ta].l,Q[ta].x,lim)>func(Q[ta].l,i,lim))ta--;
            res l=Q[ta].l,r=Q[ta].r+1;
            while(l<r){
                res mid=(l+r)>>1;
                if(func(mid,i,lim)<func(mid,Q[ta].x,lim))r=mid;
                else l=mid+1;
            }
            Q[ta].r=r-1;
            Q[++ta]=Queue(i,r,n);
        }
    }
    inline void MAIN(){
        res (*F)()=io::read<int>;
        n=F(),k=F();
        for(res i=1;i<=n;i++)
            for(res j=1;j<=n;j++)
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+F();
        res l=0,r=sum[n][n];
        while(l<r){
            res mid=(l+r)>>1;
            calc(mid);
            if(siz[n]>k)l=mid+1;
            else r=mid;
        }
        calc(r);
        io::P(dp[n]-r*k);
    }
}
int main(){
    MAIN::MAIN();
    io::output();
    return 0;
}