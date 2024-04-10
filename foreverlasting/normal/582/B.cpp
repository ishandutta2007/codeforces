//2019.2.28 by ljz
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
const int N=1e2+10;
namespace MAIN{
    int n,T;
    int a[N];
    struct Matrix{
        int t[N][N];
        Matrix() {for(res i=0;i<=100;i++)for(res j=0;j<=100;j++)t[i][j]=-inf;}
        inline void init(){
            for(res i=0;i<=n;i++)
                for(res j=0;j<=n;j++)t[i][j]=0;
        }
    };
    inline Matrix operator * (const Matrix &x,const Matrix &y){
        Matrix ret;
        for(res i=0;i<=n;i++)
            for(res j=0;j<=n;j++)
                for(res k=0;k<=n;k++)
                    ret.t[i][j]=_max(ret.t[i][j],x.t[i][k]+y.t[k][j]);
        return ret;
    }
    inline Matrix qpow(Matrix x,res y){
        Matrix ret;
        ret.init();
        while(y){
            if(y&1)ret=ret*x;
            x=x*x,y>>=1;
        }
        return ret;
    }
    Matrix ans;
    inline void MAIN(){
        n=read(),T=read();
        for(res i=1;i<=n;i++)a[i]=read();
        for(res i=1;i<=n;i++)
            for(res j=1;j<=n;j++){
                if(a[i]>a[j])ans.t[i][j]=-inf;
                else {
                    ans.t[i][j]=1;
                    for(res k=1;k<j;k++)
                        if(a[k]<=a[j])ans.t[i][j]=_max(ans.t[i][j],ans.t[i][k]+1);
                }
            }
        ans=qpow(ans,T);
        res Ans=0;
        for(res i=1;i<=n;i++)
            for(res j=1;j<=n;j++)Ans=_max(Ans,ans.t[i][j]);
        printf("%d\n",Ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}