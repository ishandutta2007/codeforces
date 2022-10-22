//2018.10.15 by ljz
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
const int N=5e3+10;
namespace MAIN{
    int n;
    int dp[N][N][2];
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N];
    int head[N],cnt;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
    }
    int siz[N];
    int c[N],d[N],b;
    void DP(const res &x){
        siz[x]=1;
        dp[x][0][0]=0,dp[x][1][0]=c[x],dp[x][1][1]=c[x]-d[x];
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            DP(tox);
            for(res j=siz[x];~j;j--)
                for(res k=0;k<=siz[tox];k++){
                    dp[x][j+k][0]=_min(dp[x][j+k][0],dp[tox][k][0]+dp[x][j][0]);
                    dp[x][j+k][1]=_min(dp[x][j+k][1],_min(dp[x][j][1]+dp[tox][k][1],dp[x][j][1]+dp[tox][k][0]));
                }
            siz[x]+=siz[tox];
        }
    }
    int ans;
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        memset(dp,inf,sizeof(dp));
        n=read(),b=read();
        c[1]=read(),d[1]=read();
        for(res i=2;i<=n;i++){
            c[i]=read(),d[i]=read();
            res fa=read();
            addedge(fa,i);
        }
        DP(1);
        for(res i=n;i;i--)if(dp[1][i][1]<=b||dp[1][i][0]<=b){ans=i;break;}
        printf("%d\n",ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}