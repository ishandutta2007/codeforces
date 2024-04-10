//2019.2.22 by ljz
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
const int N=2e6+10;
const int kcz=1e9+7;
namespace MAIN{
    int Ex,Ey,n;
    int fac[N],inv[N];
    inline void pre(){
        fac[0]=fac[1]=inv[0]=inv[1]=1;
        for(res i=2;i<=N-10;i++)fac[i]=1LL*fac[i-1]*i%kcz,inv[i]=1LL*inv[kcz%i]*(kcz-kcz/i)%kcz;
        for(res i=2;i<=N-10;i++)inv[i]=1LL*inv[i-1]*inv[i]%kcz;
    }
    inline int C(const res &x,const res &y){
        if(x<y)return 0;
        return 1LL*fac[x]*inv[y]%kcz*inv[x-y]%kcz;
    }
    struct P{
        int x,y;
        P() {}
        P(res x,res y):x(x),y(y) {}
        inline bool operator < (const P &b) const {
            return x!=b.x?x<b.x:y<b.y;
        }
        inline int solve(){
            return C(x+y,x);
        }
        inline P operator - (const P &b) const {
            return P(x-b.x,y-b.y);
        }
    }a[N];
    int Ax,Ay,Bx,By;
    inline bool calc(res &x,res &y){
        res a1=x*Ay-y*Ax,a2=Bx*Ay-Ax*By,b1=x*By-y*Bx,b2=Ax*By-Ay*Bx;
        if((!a2)||(!b2)){x=y=-1;return 1;}
        if((a1%a2)||(b1%b2)){x=y=-1;return 1;}
        y=a1/a2,x=b1/b2;
        return x>Ex||y>Ey||x<0||y<0;
    }
    int dp[N];
    inline void add(res &x,const res &y){
        x+=y,x>=kcz?x-=kcz:1,x<0?x+=kcz:1;
    }
    inline int Add(const res &x,const res &y){
        return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
    }
    inline void MAIN(){
        pre();
        Ex=read()-1,Ey=read()-1,n=read(),Ax=1,Ay=0,Bx=0,By=1;
        calc(Ex,Ey);
        for(res i=1;i<=n;i++){
            res x=read()-1,y=read()-1;
            if(calc(x,y)==1){n--,i--;continue;}
            a[i]=P(x,y);
        }
        a[++n]=P(Ex,Ey);
        sort(a+1,a+n+1);
        for(res i=1;i<=n;i++){
            dp[i]=a[i].solve();
            for(res j=1;j<i;j++)add(dp[i],kcz-1LL*dp[j]*(a[i]-a[j]).solve()%kcz);
        }
        printf("%d\n",dp[n]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}