//2018.10.11 by ljz
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
const int N=3e3+10;
namespace MAIN{
    int n,d;
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N];
    int head[N],cnt;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
    }
    int dp[N][N];
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
    inline int calc(const res &x){
        res tmp=1,ret=0,p=(n&1)?kcz-1:1;
        for(res i=1;i<=n;i++)tmp=1LL*tmp*(x-i)%kcz*qpow(i,kcz-2)%kcz;
        for(res i=0;i<=n;i++,p=kcz-p)
            add(ret,1LL*p*dp[1][i]%kcz*tmp%kcz),tmp=1LL*tmp*(x-i)%kcz*qpow(x-i-1,kcz-2)%kcz*(n-i)%kcz*qpow(i+1,kcz-2)%kcz;
        return ret;
    }
    void dfs(const res &x){
        for(res i=1;i<=n;i++)dp[x][i]=1;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            dfs(tox);
            for(res j=1;j<=n;j++)dp[x][j]=1LL*dp[x][j]*dp[tox][j]%kcz;
        }
        for(res i=1;i<=n;i++)add(dp[x][i],dp[x][i-1]);
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read(),d=read();
        for(res i=2;i<=n;i++){
            res fa=read();
            addedge(fa,i);
        }
        dfs(1);
        if(d<=n)printf("%d\n",dp[1][d]);
        else printf("%d\n",calc(d));
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}