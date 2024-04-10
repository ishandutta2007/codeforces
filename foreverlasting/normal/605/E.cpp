//2018.10.24 by ljz
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
const int N=1e3+10;
namespace MAIN{
    int n;
    double p[N][N];
    typedef pair<double,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
    priority_queue<Pair,vector<Pair>,greater<Pair> >Q;
    double dis[N],rest[N];
    bool vis[N];
    inline void spfa(){
        for(res i=1;i<=n;i++)dis[i]=rest[i]=1.0;
        dis[n]=0,Q.push(mp(0,n));
        while(!Q.empty()){
            res u=Q.top().se;
            double dist=Q.top().fi;
            Q.pop();
            if(vis[u])continue;
            dis[u]=dist,vis[u]=1;
            for(res i=1;i<=n;i++){
                if(vis[i]||p[i][u]==0)continue;
                dis[i]+=rest[i]*p[i][u]*dis[u];
                rest[i]-=rest[i]*p[i][u];
                Q.push(mp(dis[i]/(1-rest[i]),i));
            }
        }
    }
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)
            for(res j=1;j<=n;j++){
                scanf("%lf",&p[i][j]);
                p[i][j]/=100;
            }
        spfa();
        printf("%.7lf\n",dis[1]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}