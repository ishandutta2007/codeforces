#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3,mxm=4e5+3,inf=0x7f7f7f7f;
int to[mxm],nxt[mxm],fir[mxn],w[mxm],gn=1,n,m;
inline void gadd(int x,int y,int z){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn,w[gn]=z;}
int dis[mxn][51];
struct thr{
    int d,x,y;
    thr(){}
    thr(int a,int b,int c){d=a,x=b,y=c;}
    friend bool operator<(const thr&a,const thr&b){return a.d>b.d;}
}tmp;
priority_queue<thr>q;
inline int sqr(int x){return x*x;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,u,v,w;i<=m;++i)scanf("%d%d%d",&u,&v,&w),gadd(u,v,w),gadd(v,u,w);
    memset(dis,0x7f,sizeof(dis)),dis[1][0]=0;
    q.push(thr(0,1,0));
    while(q.size()){
        tmp=q.top();q.pop();
        int d=tmp.d,x=tmp.x,y=tmp.y;
        if(d>dis[x][y])continue;
        if(y){
            forg(i,x){
                int t=d+sqr(y+w[i]);
                if(dis[to[i]][0]>t)dis[to[i]][0]=t,q.push(thr(t,to[i],0));
            }
        }else{
            forg(i,x)if(dis[to[i]][w[i]]>d){
                dis[to[i]][w[i]]=d,q.push(thr(d,to[i],w[i]));
            }
        }
    }
    for(int i=1;i<=n;++i)printf("%d ",dis[i][0]<inf?dis[i][0]:-1);puts("");
    return 0;
}