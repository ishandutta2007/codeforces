#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int> pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=5e5+3;
int n,m,to[mxn*4],nxt[mxn*4],fir[mxn],gn=1;
void gadd(int x,int y){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn;}
int dfn[mxn],low[mxn],dn,stk[mxn],sn,bn;
vector<int>hd[mxn];
bool ah[mxn],ro[mxn];
void tar(int x,int f){
    dfn[x]=low[x]=++dn,stk[++sn]=x;
    forg(i,x)if(!dfn[to[i]])tar(to[i],x),low[x]=min(low[x],low[to[i]]);
    else if(to[i]!=f)low[x]=min(low[x],dfn[to[i]]);
    if(dfn[x]==low[x]){
        int y;do y=stk[sn--],hd[x].push_back(y),ah[y]=1;while(y!=x);
        ah[x]=0,ro[x]=hd[x].size()>1;
    }
}
int d1[mxn],d2[mxn],d3[mxn],v1[mxn],da[mxn];
void upd(int x,int v){if(v>d1[x])v1[x]=d1[x],d1[x]=v;else if(v>v1[x])v1[x]=v;}
void dfs1(int x,int f){
    forg(i,x)if(to[i]!=f&&!ah[to[i]])dfs1(to[i],x),upd(x,1+da[to[i]]);
    if(ro[x]){
        int sz=hd[x].size(),y; --sz;
        for(int i=0;i<sz;++i)y=hd[x][i],dfs1(y,x),d3[x]=max(d3[x],d1[y]+min(sz-i,i+1));
    }
    da[x]=max(d1[x],d3[x]);
}

int vl[mxn*2],q[mxn*2];
void dfs2(int x,int f){
    if(!ah[x]&&x>1){
        if(1+da[x]!=da[f])d2[x]=da[f]+1;
        else d2[x]=max(d3[f],v1[f])+1;
        d2[x]=max(d2[x],d2[f]+1);
    }
    if(ro[x]){
        int sz=hd[x].size(),y;
        for(int i=0,y;i<sz;++i)y=hd[x][i],vl[i]=vl[i+sz]=y==x?max(d1[x],d2[x]):d1[y];
        int qh=1,qt=0,K=sz>>1;
        for(int i=2*sz-1;~i;--i){
            if(qh<=qt&&q[qh]-i>K)++qh;
            if(qh<=qt)y=hd[x][i%sz],d2[y]=max(d2[y],vl[q[qh]]+q[qh]-i);
            while(qh<=qt&&vl[i]+i>=vl[q[qt]]+q[qt])--qt;
            q[++qt]=i;
        }
        qh=1,qt=0;
        for(int i=0;i<2*sz;++i){
            if(qh<=qt&&i-q[qh]>K)++qh;
            if(qh<=qt)y=hd[x][i%sz],d2[y]=max(d2[y],vl[q[qh]]+i-q[qh]);
            while(qh<=qt&&vl[i]-i>=vl[q[qt]]-q[qt])--qt;
            q[++qt]=i;
        }
        for(int i=0;i<sz-1;++i)dfs2(hd[x][i],x);
    }
    forg(i,x)if(to[i]!=f&&!ah[to[i]])dfs2(to[i],x);
}

int main(){
    scanf("%d%d",&n,&m);for(int i=1,u,v;i<=m;++i)scanf("%d%d",&u,&v),gadd(u,v),gadd(v,u);
    tar(1,0);
    dfs1(1,0),dfs2(1,0);
    for(int i=1;i<=n;++i)printf("%d ",max(da[i],d2[i]));puts("");
    return 0;
}