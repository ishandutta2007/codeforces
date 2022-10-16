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

const int mxn=3e5+3;
int to[mxn*2],nxt[mxn*2],fir[mxn],gn=1;
int n,m;
inline void gadd(int x,int y){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn;}

int dfn[mxn],dfa[mxn],dep[mxn],siz[mxn],zs[mxn],top[mxn],fa[mxn],dt;
inline void dfs1(int x,int f){
    siz[x]=1;fa[x]=f;dep[x]=dep[f]+1;
    forg(i,x)if(to[i]!=f){
        dfs1(to[i],x);
        siz[x]+=siz[to[i]];
        if(siz[to[i]]>siz[zs[x]])zs[x]=to[i];
    }
}
inline void dfs2(int x,int f){
    dfn[x]=++dt,dfa[dt]=x;
    top[x]=x==zs[f]?top[f]:x;
    if(zs[x])dfs2(zs[x],x);
    forg(i,x)if(!dfn[to[i]])dfs2(to[i],x);
}
inline int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
inline int gson(int x,int y){
    if(dfn[x]>=dfn[zs[y]]&&dfn[x]<=dfn[zs[y]]+siz[zs[y]]-1)return zs[y];
    x=top[x];
    while(fa[x]!=y)x=top[fa[x]];
    return x;
}

int cnt[mxn],cnt1[mxn],cnt2[mxn],cnt3[mxn];
map<pii,int>co;

int main(){
    scanf("%d",&n);for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),gadd(u,v),gadd(v,u);
    dfs1(1,0),dfs2(1,0);
    scanf("%d",&m);

    long long ans=0;
    for(int i=1;i<=m;++i){
        int x,y;scanf("%d%d",&x,&y);int z=lca(x,y);
        ans+=cnt[z],++cnt[z];
        int a=0,b=0;
        if(x!=z){
            a=gson(x,z);
            ans-=cnt1[a];++cnt1[a];
            ++cnt2[x],--cnt2[a];
            ++cnt3[x],--cnt3[z];
        }
        if(y!=z){
            b=gson(y,z);
            ans-=cnt1[b];++cnt1[b];
            ++cnt2[y],--cnt2[b];
            ++cnt3[y],--cnt3[z];
        }
        if(a>b)swap(a,b);
        if(a&&b)ans+=co[pii(a,b)],++co[pii(a,b)];
    }
    for(int i=n;i;--i){
        int x=dfa[i];forg(j,x)if(to[j]!=fa[x])cnt2[x]+=cnt2[to[j]],cnt3[x]+=cnt3[to[j]];
    }
    for(int x=1;x<=n;++x)ans+=1ll*cnt[x]*cnt3[x],ans-=1ll*cnt1[x]*cnt2[x];
    printf("%lld\n",ans);
    
    return 0;
}