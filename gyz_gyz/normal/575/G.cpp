#include<cstdio>
#include<algorithm>
#include<vector>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 100001
#define ll long long
#define inf 1000000000
using namespace std;
vector<int>e[mx],w[mx],sv[mx];
int dis[mx],diss[mx],dl[mx],fr[mx],ff[mx],nt[mx],rr[mx],vis[mx],rk[mx];
int ed,n,m,dd,x,y,z;
inline bool cmp(int x,int y){
    if(rk[x]!=rk[y])return rk[x]<rk[y];else return diss[x]<diss[y];
}
inline void bfs1(){
    rep(i,1,n-1)dis[i]=inf;
    int s=1,t=1;vis[0]=1;
    for(;s<=t;s++){
        int ss=dl[s],sz=e[ss].size()-1;
        rep(i,0,sz){
            int tt=e[ss][i];
            if(dis[ss]+1<dis[tt]){
                dis[tt]=dis[ss]+1;vis[tt]=1,dl[++t]=tt;
            }
        }
    }
}
inline void bfs2(){
    rep(i,0,n-2)diss[i]=inf;
    rep(i,0,n-1)vis[i]=0;
    int s=1,t=1;vis[n-1]=1;dl[1]=n-1;
    for(;s<=t;s++){
        int ss=dl[s],sz=e[ss].size()-1;
        rep(i,0,sz){
            int tt=e[ss][i];
            if(!w[ss][i]&&diss[ss]+1<diss[tt]){
                diss[tt]=diss[ss]+1;nt[tt]=ss;
                vis[tt]=1,dl[++t]=tt;
            }
        }
    }
}
void prf(int x){
    if(x)prf(fr[x]);
    printf("%d ",x);
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d%d%d",&x,&y,&z);
        e[x].push_back(y);
        w[x].push_back(z);
        e[y].push_back(x);
        w[y].push_back(z);
    }
    bfs1();bfs2();ed=n-1;
    rep(i,0,n-1)if(dis[i]!=inf){
        sv[dis[i]].push_back(i);
        if(dis[i]>dd)dd=dis[i];
    }
    rep(i,1,dd){int nm=sv[i].size()-1;
        int lsm=sv[i-1].size();
        rep(j,0,nm){x=sv[i][j];rk[x]=lsm*10;
            int sz=e[x].size()-1;
            rep(ii,0,sz){int frm=e[x][ii];
                if(dis[frm]+1==dis[x]){
                    int ww=w[x][ii]*lsm+rk[frm];
                    if(ww<rk[x])rk[x]=ww,fr[x]=frm,ff[x]=w[x][ii];
                }
            }
            rr[j]=x;
        }
        sort(rr,rr+nm+1,cmp);
        rep(j,0,nm)rk[rr[j]]=j;
    }
    rep(i,0,n-2)if(vis[i]){
        if(dis[i]==dis[ed]&&rk[i]==rk[ed]&&diss[i]<diss[ed])ed=i;
        if(dis[i]==dis[ed]&&rk[i]<rk[ed])ed=i;
        if(dis[i]<dis[ed])ed=i;
    }
    for(x=ed;x;x=fr[x])printf("%d",ff[x]);if(!ed)printf("0");
    printf("\n%d\n",dis[ed]+diss[ed]+1);
    prf(ed);for(x=nt[ed];x;x=nt[x])printf("%d ",x);
}