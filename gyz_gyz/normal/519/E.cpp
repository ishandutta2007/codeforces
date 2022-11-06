#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define Rep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 200001
using namespace std;
int f[21][mx],sz[mx],st[mx],ed[mx],nt[mx],t[mx],h[mx],n,m,x,y;
void bbf(int x){
    sz[x]=1;
    for(int i=st[x];i;i=nt[i])if(t[i]!=f[0][x]){
        h[t[i]]=h[x]+1;f[0][t[i]]=x;bbf(t[i]);sz[x]+=sz[t[i]];
    }
}
inline int lca(int x,int y){
    if(h[x]>h[y])Rep(i,20,0)if(h[f[i][x]]>h[y])x=f[i][x];
    if(h[x]>h[y])x=f[0][x];
    Rep(i,20,0)if(f[i][x]!=f[i][y]){x=f[i][x];y=f[i][y];}
    if(x!=y){x=f[0][x];y=f[0][y];}
    return x;
}
int main(){
    scanf("%d",&n);f[0][1]=1;
    rep(i,1,n-1){
        scanf("%d%d",&x,&y);
        if(!st[x])st[x]=i;else nt[ed[x]]=i;
        ed[x]=i;t[i]=y;
        if(!st[y])st[y]=i+n-1;else nt[ed[y]]=i+n-1;
        ed[y]=i+n-1;t[i+n-1]=x;
    }
    bbf(1);scanf("%d",&m);
    rep(i,1,20)rep(j,1,n)f[i][j]=f[i-1][f[i-1][j]];
    rep(i,1,m){
        scanf("%d%d",&x,&y);
        if(x==y){printf("%d\n",n);continue;}
        if((h[x]+h[y])%2){printf("0\n");continue;}
        if(h[x]<h[y]){int tmp=x;x=y;y=tmp;}
        int z=lca(x,y);
        int ww=h[x]-(h[x]+h[y])/2+h[z];
        int w=x;Rep(i,20,0)if(h[f[i][w]]>ww)w=f[i][w];
        if(f[0][w]==z){
            int g=y;Rep(i,20,0)if(h[f[i][g]]>ww)g=f[i][g];
            printf("%d\n",n-sz[g]-sz[w]);
        }else printf("%d\n",sz[f[0][w]]-sz[w]);
    }
}