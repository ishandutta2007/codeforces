//2018.10.12 by ljz
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
const int kcz=1e9+7;
const int K=1e6+10;
namespace MAIN{
    int n,k;
    int f[K];
    inline int qpow(res x,res y){
        res ret=1;
        while(y){
            if(y&1)ret=1LL*ret*x%kcz;
            y>>=1,x=1LL*x*x%kcz;
        }
        return ret%kcz;
    }
    inline void add(res &x,const res &y){
        x+=y;
        x>=kcz?x-=kcz:1;
        x<0?x+=kcz:1;
    }
    inline int calc(const res &x,const res &n){
        res tmp=1,ret=0,p=(n&1)?kcz-1:1;
        for(res i=1;i<=n;i++)tmp=1LL*tmp*(x-i)%kcz*qpow(i,kcz-2)%kcz;
        for(res i=0;i<=n;i++,p=kcz-p)
            add(ret,1LL*p*f[i]%kcz*tmp%kcz),tmp=1LL*tmp*(x-i)%kcz*qpow(x-i-1,kcz-2)%kcz*(n-i)%kcz*qpow(i+1,kcz-2)%kcz;
        return ret;
    }
    inline void MAIN(){
        n=read(),k=read();
        for(res i=1;i<=k+1;i++)add(f[i],f[i-1]+qpow(i,k));
        if(n<=k+1)printf("%d\n",f[n]);
        else printf("%d\n",calc(n,k+1));
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}