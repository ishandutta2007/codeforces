//2018.9.28 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register LL
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline LL read(){
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
inline LL _abs(const res &x){
    return x>0?x:-x;
}
inline LL _max(const res &x,const res &y){
    return x>y?x:y;
}
inline LL _min(const res &x,const res &y){
    return x<y?x:y;
}
const LL N=1e5+10;
namespace MAIN{
    LL n,m,A,cf,cm;
    struct P{
        LL va,id;
        P() {}
        P(res va,res id):va(va),id(id) {}
        inline bool operator < (const P &b) const {
            return va<b.va;
        }
    }a[N];
    LL sum[N],now;
    LL X,Y;
    inline LL func(const res &x,const res &y){
        return cf*x+cm*y;
    }
    LL ans[N];
    inline void MAIN(){
        now=n=read(),A=read(),cf=read(),cm=read(),m=read();
        for(res i=1;i<=n;i++){
            res va=read();
            a[i]=P(va,i);
        }
        sort(a+1,a+n+1);
        for(res i=1;i<=n;i++)sum[i]=sum[i-1]+a[i].va;
        for(res i=0;i<=n;i++){
            res d=m-(A*i-(sum[n]-sum[n-i])),tot,k;
            if(d<0)break;
            now=_min(now,n-i);
            if(!now)k=A;
            else {
                while(d<a[now].va*(now-1)-sum[now-1])now--;
                d-=a[now].va*(now-1)-sum[now-1];
                k=_min(a[now].va+d/now,A);
            }
            if(func(X,Y)<func(i,k))X=i,Y=k;
        }
        printf("%lld\n",func(X,Y));
        for(res i=n-X+1;i<=n;i++)ans[a[i].id]=A;
        for(res i=1;i<=n-X;i++)ans[a[i].id]=_max(a[i].va,Y);
        for(res i=1;i<=n;i++)printf("%lld ",ans[i]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}