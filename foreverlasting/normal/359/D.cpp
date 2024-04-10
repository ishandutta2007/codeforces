//2019.4.20 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
#define RG register
inline int read(){
    res s=0,ch=getchar();
    bool w=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline LL Read(){
    RG LL s=0;
    res ch=getchar();
    bool w=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void swap(res &x,res &y){
    x^=y^=x^=y;
}
const int N=3e5+10;
namespace MAIN{
    int n;
    int GCD[N][21],Mn[N][21];
    inline int gcd(res x,res y){
        while(y){
            res t=x;
            x=y,y=t%x;
        }
        return x;
    }
    inline bool get(const res &l,const res &r){
        res k=int(log2(r-l+1));
        return gcd(GCD[l][k],GCD[r-(1<<k)+1][k])==min(Mn[l][k],Mn[r-(1<<k)+1][k]);
    }
    int vec[N],vecx;
    inline int check(const res &lim){
        vecx=0;
        for(res i=1;i+lim<=n;i++)if(get(i,i+lim))vec[++vecx]=i;
        return vecx;
    }
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)GCD[i][0]=Mn[i][0]=read();
        for(res j=1;j<=20;j++)
            for(res i=1;i+(1<<j)-1<=n;i++)
                GCD[i][j]=gcd(GCD[i][j-1],GCD[i+(1<<(j-1))][j-1]),Mn[i][j]=min(Mn[i][j-1],Mn[i+(1<<(j-1))][j-1]);
        res l=0,r=n-1,ret=1;
        while(l<=r){
            res mid=(l+r)>>1;
            if(check(mid))l=mid+1,ret=mid;
            else r=mid-1;
        }
        check(ret),printf("%d %d\n",vecx,ret);
        for(res i=1;i<=vecx;i++)printf("%d ",vec[i]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}