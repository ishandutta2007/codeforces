//2019.3.14 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
#define RG register
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
const int N=50+10;
namespace MAIN{
    inline int Add(const res &x,const res &y){
        return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
    }
    inline void add(res &x,const res &y){
        x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
    }
    inline int mul(const res &x,const res &y){
        return int(1LL*x*y%kcz);
    }
    int n,p;
    int a[N];
    int dp[2][2][2][2];
    int pw[N],ans;
    inline void MAIN(){
        n=read(),p=read(),pw[0]=dp[0][0][0][0]=1;
        for(res i=1;i<=n;i++)a[i]=read(),pw[i]=mul(pw[i-1],2);
        res cur=0;
        for(res i=1;i<=n;i++){
            memset(dp[cur^1],0,sizeof(dp[cur^1]));
            for(res j=0;j<=1;j++)
                for(res k=0;k<=1;k++)
                    for(res l=0;l<=1;l++){
                        if(!dp[cur][j][k][l])continue;
                        res ret=dp[cur][j][k][l],A=(i>=2?mul(ret,pw[i-2]):0),B=mul(ret,pw[i-1]);
                        res &DP0=dp[cur^1][j][k][l],&DP1=dp[cur^1][j^1][k][l|1],&DP2=dp[cur^1][j^1][k|1][l];
                        if(a[i]!=0){
                            if(k)add(DP0,A),add(DP1,A);
                            else add(DP1,B);
                        }
                        if(a[i]!=1){
                            if(l)add(DP0,A),add(DP2,A);
                            else add(DP2,B);
                        }
                    }
            cur^=1;
        }
        for(res k=0;k<=1;k++)
            for(res l=0;l<=1;l++)
                add(ans,dp[cur][p][k][l]);
        printf("%d\n",ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}