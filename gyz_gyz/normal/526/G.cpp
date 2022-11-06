#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 100002
using namespace std;
struct pr{int x,y;}rs[2][mx];
int e[mx*2],nt[mx*2],gt[mx*2],rw[mx*2],rk[2][mx],ts[2][mx],w[2][mx],ww[2][mx],ff[2][18][mx];
int fr[mx],ed[mx],v[mx],ds[mx],f[mx],a[mx],b[mx],dl[mx],bg[mx],gg[mx],r[mx];
int n,q,x,y,z,s,t,st,d,s1,s2,le;
inline bool cmp(pr a,pr b){return a.x>b.x;}
inline void bfs(int x){
    rep(i,1,n)v[i]=0;s=1;t=1;v[x]=1;dl[1]=x;ds[x]=0;
    for(;s<=t;s++){
        int ss=dl[s];
        for(int i=fr[ss];i;i=nt[i])if(!v[gt[i]]){
            dl[++t]=gt[i];v[gt[i]]=v[ss]+rw[i];f[gt[i]]=ss;ds[gt[i]]=rw[i];
        }
    }
}
inline void dp(int x,int y){
    bfs(x);le=0;f[x]=x;
    rep(i,1,n)bg[i]=0,gg[i]=0;
    dep(i,n,1){
        int tt=dl[i];
        if(!bg[tt])a[tt]=tt,b[tt]=ds[tt];else a[tt]=bg[tt],b[a[tt]]+=ds[tt];
        if(i>1&&b[a[tt]]>gg[f[tt]]){
            gg[f[tt]]=b[a[tt]];bg[f[tt]]=a[tt];
        }
    }
    rep(i,1,n)ww[y][dl[i]]=ww[y][f[dl[i]]]+ds[dl[i]],ff[y][0][i]=f[i];
    rep(j,1,17)rep(i,1,n)ff[y][j][i]=ff[y][j-1][ff[y][j-1][i]];
    rep(i,1,n)if(i!=dl[1]&&a[f[i]]!=a[i])w[y][a[i]]=ww[y][f[i]];
    rep(i,1,n)if(a[i]==i)rs[y][++le].x=b[i],rs[y][le].y=i;
    sort(rs[y]+1,rs[y]+le+1,cmp);
    rep(i,1,le)rk[y][rs[y][i].y]=i,ts[y][i]=ts[y][i-1]+rs[y][i].x;
    rep(i,1,n)rk[y][i]=rk[y][a[i]],w[y][i]=w[y][a[i]];
    rep(i,le+1,n)ts[y][i]=ts[y][i-1];
}
inline int sl(int x,int y,int z){
    if(rk[z][y]<=x)return ts[z][x]+rs[z][x+1].x;int yy=y;
    dep(i,17,0){
        int ft=ff[z][i][yy];
        if(rk[z][ft]>x)yy=ft;
    }
    if(rk[z][yy]>x)yy=ff[z][0][yy];
    int an1=ts[z][x]+rs[z][rk[z][y]].x+w[z][y]-ww[z][yy],an2=an1;
    if(rk[z][y]!=x+1)an2=an1-rs[z][rk[z][yy]].x+rs[z][x+1].x+ww[z][yy]-w[z][yy];
    else an2=an1-rs[z][rk[z][yy]].x+rs[z][x+2].x+ww[z][yy]-w[z][yy];
    if(an2>an1)an1=an2;return an1;
}
int main(){
    scanf("%d%d",&n,&q);
    rep(i,1,n-1){
        scanf("%d%d%d",&x,&y,&z);
        d++;if(!fr[x])fr[x]=d;else nt[ed[x]]=d;
        ed[x]=d;gt[d]=y;rw[d]=z;
        d++;if(!fr[y])fr[y]=d;else nt[ed[y]]=d;
        ed[y]=d;gt[d]=x;rw[d]=z;
    }
    bfs(1);s1=1;rep(i,2,n)if(v[i]>v[s1])s1=i;
    bfs(s1);s2=1;rep(i,2,n)if(v[i]>v[s2])s2=i;
    dp(s1,0);dp(s2,1);s1=0;s2=0;
    rep(i,1,q){
        scanf("%d%d",&y,&x);x=(x+s1-1)%n+1;y=(y+s1-1)%n+1;
        if(x)x=x*2-2;if(x>n)x=n;
        s1=sl(x,y,0);s2=sl(x,y,1);if(s2>s1)s1=s2;printf("%d\n",s1);
    }
}