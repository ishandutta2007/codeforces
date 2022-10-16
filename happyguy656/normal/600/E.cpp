#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define fi first
#define se second
#define scanf a1234=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3;
int co[mxn],n,to[mxn],nxt[mxn],fir[mxn],tot=1;
inline void gadd(int x,int y){to[++tot]=y,nxt[tot]=fir[x],fir[x]=tot;}

int siz[mxn],zs[mxn],cnt[mxn],mx;
long long now,ans[mxn];
inline void dfs1(int x,int f){
    siz[x]=1;
    forg(i,x)if(to[i]!=f){
        dfs1(to[i],x);siz[x]+=siz[to[i]];
        if(siz[zs[x]]<siz[to[i]])zs[x]=to[i];
    }
}
inline void dfs3(int x,int f,int y){
    if(++cnt[co[x]]>mx)mx=cnt[co[x]],now=co[x];
    else if(cnt[co[x]]==mx)now+=co[x];
    forg(i,x)if(to[i]!=f)dfs3(to[i],x,y);
}
inline void dfs4(int x,int f){
    cnt[co[x]]=0;forg(i,x)if(to[i]!=f)dfs4(to[i],x);
}
inline void dfs2(int x,int f,bool cl){
    forg(i,x)if(to[i]!=f&&to[i]!=zs[x])dfs2(to[i],x,1);
    if(zs[x])dfs2(zs[x],x,0);
    if(++cnt[co[x]]>mx)mx=cnt[co[x]],now=co[x];
    else if(cnt[co[x]]==mx)now+=co[x];
    forg(i,x)if(to[i]!=f&&to[i]!=zs[x])dfs3(to[i],x,x);
    ans[x]=now;
    if(cl){
        now=0,mx=0;
        dfs4(x,f);
    }
}

int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",co+i);
    for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),gadd(u,v),gadd(v,u);
    dfs1(1,0);dfs2(1,0,0);
    for(int i=1;i<=n;++i)printf("%lld ",ans[i]);puts("");
    return 0;
}