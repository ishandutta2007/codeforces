//2019.3.16 by ljz
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
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _abs(const res &x) {
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=50+10;
#define lb long double
namespace MAIN{
    int n;
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N<<1];
    int head[N],cnt;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
        edge[++cnt]=E(head[v],u),head[v]=cnt;
    }
    int sz[N];
    lb fac[N],dp[N][N],f[N];
    inline lb C(const res &x,const res &y){
        return fac[x]/(fac[y]*fac[x-y]);
    }
    void dfs(const res &x,const res &fax){
        sz[x]=1,dp[x][0]=1;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            dfs(tox,x),sz[x]+=sz[tox];
            for(res j=0,SZ=sz[x]-sz[tox];j<SZ;j++)
                for(res k=0;k<=sz[tox];k++)
                    f[j+k]+=dp[x][j]*dp[tox][k]*C(j+k,j)*C(sz[x]-j-k-1,sz[tox]-k);
            for(res j=0;j<=sz[x];j++)dp[x][j]=f[j],f[j]=0;
        }
        if(fax){
            for(res i=0;i<sz[x];i++){
                f[i]+=(sz[x]-i)*dp[x][i];
                for(res j=i+1;j<=sz[x];j++)f[j]+=dp[x][i]*0.5;
            }
            for(res i=0;i<=sz[x];i++)dp[x][i]=f[i],f[i]=0;
        }
    }
    inline void MAIN(){
        n=read(),fac[0]=fac[1]=1,memset(head,-1,sizeof(head));
        for(res i=2;i<=n;i++)fac[i]=fac[i-1]*i;
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            addedge(u,v);
        }
        for(res i=1;i<=n;i++)dfs(i,0),printf("%.7lf\n",(double)dp[i][n-1]/(double)fac[n-1]);
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}