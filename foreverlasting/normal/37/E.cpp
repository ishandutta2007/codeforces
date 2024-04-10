//2018.10.18 by ljz
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
const int N=50+10;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
namespace MAIN{
    int n,m;
    inline int ID(const res &x,const res &y){
        return (x-1)*m+y;
    }
    char str[N];
    int mp[N][N];
    vector<int> vec;
#define pb push_back
    struct E{
        int next,to,val;
        E() {}
        E(res next,res to,res val):next(next),to(to),val(val) {}
    }edge[N*N*4];
    int head[N*N],cnt;
    inline void addedge(const res &u,const res &v,const res &w){
        edge[++cnt]=E(head[u],v,w),head[u]=cnt;
    }
    int dis[N*N];
    bool vis[N*N];
    typedef pair<int,int> Pair;
    priority_queue<Pair,vector<Pair>,greater<Pair> >Q;
#define Mp make_pair
    inline void spfa(const res &S){
        memset(dis,inf,sizeof(dis));
        dis[S]=0,vis[S]=1;
        Q.push(Mp(0,S));
        while(!Q.empty()){
            res u=Q.top().second;
            Q.pop();
            vis[u]=0;
            for(res i=head[u];~i;i=edge[i].next){
                res tox=edge[i].to;
                if(dis[tox]>dis[u]+edge[i].val){
                    dis[tox]=dis[u]+edge[i].val;
                    if(!vis[tox])vis[tox]=1,Q.push(Mp(dis[tox],tox));
                }
            }
        }
    }
    int ans=inf;
    bool judge;
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read(),m=read();
        for(res i=1;i<=n;i++){
            scanf("%s",str+1);
            for(res j=1;j<=m;j++){
                mp[i][j]=(str[j]=='B');
                if(mp[i][j])vec.pb(ID(i,j)),judge=1;
            }
        }
        if(!judge){puts("0");return;}
        for(res i=1;i<=n;i++)
            for(res j=1;j<=m;j++)
                for(res k=0;k<4;k++){
                    res tx=i+dx[k],ty=j+dy[k];
                    if(tx<1||ty<1||tx>n||ty>m)continue;
                    addedge(ID(i,j),ID(tx,ty),mp[i][j]!=mp[tx][ty]);
                }
        for(res i=1;i<=n;i++)
            for(res j=1;j<=m;j++){
                spfa(ID(i,j));
                res tmp=0;
                for(res k=0,siz=vec.size();k<siz;k++)tmp=_max(tmp,dis[vec[k]]);
                ans=_min(ans,tmp);
            }
        printf("%d\n",ans+1);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}