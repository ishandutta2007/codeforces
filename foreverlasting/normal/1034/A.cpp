//2019.2.24 by ljz
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
const int N=3e5+10;
const int A=1.5e7+10;
namespace MAIN{
    int n;
    int a[N];
    int prim[A],tot,mx;
    bool vis[A];
    inline void pre(){
        for(res i=2;i<=mx;i++){
            if(!vis[i])prim[++tot]=i;
            for(res j=1;j<=tot&&prim[j]<=mx/i;j++){
                vis[prim[j]*i]=1;
                if(i%prim[j]==0)break;
            }
        }
    }
    int GCD;
    inline int gcd(res x,res y){
        while(y){
            res t=x;
            x=y,y=t%x;
        }
        return x;
    }
    int num[A];
    inline void MAIN(){
        n=read();
        bool Flag=0;
        for(res i=1;i<=n;i++){a[i]=read(),mx=_max(mx,a[i]),GCD=gcd(a[i],GCD);if(a[i]>1)Flag=1;}
        if(!Flag){puts("-1");return;}
        pre();
        for(res i=1;i<=n;i++)a[i]/=GCD,num[a[i]]++;
        res ans=n;
        for(res i=1;i<=tot;i++){
            res x=prim[i],sum=0;
            for(res j=x;j<=mx;j+=x)sum+=num[j];
            ans=_min(ans,n-sum);
        }
        printf("%d\n",ans==n?-1:ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}