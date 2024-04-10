//2019.6.7 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define eps 1e-10
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
//inline void add(res &x,const res &y,const res &kcz){
//    x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
//}
//inline int Add(const res &x,const res &y,const res &kcz){
//    return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
//}
//inline int mul(const res &x,const res &y,const res &kcz){
//    return int(1LL*x*y%kcz);
//}
//inline int qpow(res x,res y,const res &kcz){
//    res ret=1;
//    while(y){
//        if(y&1)ret=mul(ret,x,kcz);
//        y>>=1,x=mul(x,x,kcz);
//    }
//    return ret;
//}
#define gc getchar
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
inline int read() {
    res s=0,ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s;
}
//inline int read() {
//    res s=0,ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
//inline void swap(res &x,res &y) {
//    x^=y^=x^=y;
//}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int kcz=998244353;
const int N=2e5+10;
namespace MAIN {
    int n,m;
    int fac[N],inv[N],a[N],w[N],sum[2],Sum;
    inline void add(res &x,const res &y,const res &kcz){
        x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
    }
    inline int Add(const res &x,const res &y,const res &kcz){
        return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
    }
    inline int mul(const res &x,const res &y,const res &kcz){
        return int(1LL*x*y%kcz);
    }
    inline int qpow(res x,res y,const res &kcz){
        res ret=1;
        while(y){
            if(y&1)ret=mul(ret,x,kcz);
            y>>=1,x=mul(x,x,kcz);
        }
        return ret;
    }
    int gl[2][N],cur;
    int INV[2][N];
    map<int,int> M[2];
    inline int DP(const res &fl,const res &val,const res &lim){
        if(M[fl].count(val))return M[fl][val];
        res ret=0,sum=0;
        for(res i=0;i<m;i++)add(sum,mul(fl==0?Add(val,-sum,kcz):Add(val,sum,kcz),INV[fl][i],kcz),kcz),add(ret,mul(sum,fl==0?gl[cur][m-i-1]:gl[cur][i+1],kcz),kcz);
        return M[fl][val]=ret;
    }
    inline void MAIN(){
        n=read(),m=read();
        res qaq=m+5;
        for(res i=1;i<=n;i++)a[i]=read();
        for(res i=1;i<=n;i++)w[i]=read(),sum[a[i]]+=w[i],Sum+=w[i];
        for(res i=0;i<=2*qaq;i++)inv[i]=qpow(Sum+i-qaq,kcz-2,kcz);
        gl[0][0]=1,INV[0][0]=qpow(sum[0],kcz-2,kcz),INV[1][0]=qpow(sum[1],kcz-2,kcz);
        for(res i=1;i<=m;i++){
            INV[0][i]=qpow(sum[0]-i,kcz-2,kcz),INV[1][i]=qpow(sum[1]+i,kcz-2,kcz);
            for(res j=0;j<=i;j++)gl[cur^1][j]=0;
            for(res j=0;j<i;j++){
                res p=mul(sum[1]+j,inv[2*j-i+1+qaq],kcz);
                add(gl[cur^1][j],mul(gl[cur][j],1-p,kcz),kcz),add(gl[cur^1][j+1],mul(gl[cur][j],p,kcz),kcz);
            }
            cur^=1;
        }
        for(res i=1;i<=n;i++)printf("%d\n",Add(w[i],a[i]==0?-DP(a[i],w[i],m):DP(a[i],w[i],m),kcz));
    }
}
int main() {
//    srand((unsigned)time(NULL));
    // freopen("zao.in","r",stdin);
    // freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}