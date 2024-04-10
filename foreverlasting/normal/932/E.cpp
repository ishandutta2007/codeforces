//2018.12.27 by ljz
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
const int kcz=1e9+7,K=5e3+10,INV=500000004;
namespace MAIN{
    int n,k;
    int S[K][K];
    inline void add(res &x,const res &y){
        x+=y,x>=kcz?x-=kcz:1;
    }
    inline int Add(const res &x,const res &y){
        return x+y>=kcz?x+y-kcz:x+y;
    }
    inline void pre(){
        S[0][0]=1;
        for(res i=1;i<=k;i++)
            for(res j=1;j<=i;j++)S[i][j]=Add(S[i-1][j-1],1LL*j*S[i-1][j]%kcz);
    }
    inline int qpow(res x,res y){
        res ret=1;
        while(y){
            if(y&1)ret=1LL*x*ret%kcz;
            x=1LL*x*x%kcz,y>>=1;
        }
        return ret;
    }
    int ans;
    inline void MAIN(){
        n=read(),k=read(),pre();
        for(res i=0,pw=1,inv=qpow(2,n);i<=_min(n,k);inv=1LL*inv*INV%kcz,pw=1LL*pw*(n-i)%kcz,i++)add(ans,1LL*S[k][i]*pw%kcz*inv%kcz);
        printf("%d\n",ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}