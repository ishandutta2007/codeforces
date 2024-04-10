#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define maxn 400010
int head[maxn],v[maxn*2],nxt[maxn*2],tot=0;
void add_edge(int s,int e){
    tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
    tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}
int siz[maxn],up[maxn];
int cutd[maxn],cutu[maxn];
int ok[maxn];
int stack[maxn],cnt=0;
int pre[maxn],last[maxn];
void dfs1(int u,int f){
    siz[u]=1;ok[u]=1;cutd[u]=0;\
    for(int i=head[u];i;i=nxt[i])
    if(v[i]!=f){
        dfs1(v[i],u);
        siz[u]+=siz[v[i]];
        cutd[u]=max(cutd[u],cutd[v[i]]);
        if(siz[v[i]]>n/2&&siz[v[i]]-cutd[v[i]]>n/2)ok[u]=-1;
        if(siz[v[i]]<=n/2)cutd[u]=max(cutd[u],siz[v[i]]);
    }
    up[u]=n-siz[u];
    if(up[u]>n/2)ok[u]=0;
}
void dfs2(int u,int f){
	cnt=0;
    for(int i=head[u];i;i=nxt[i])
    if(v[i]!=f)stack[++cnt]=v[i];
    pre[0]=0;
    for(int i=1;i<=cnt;++i){
        pre[i]=max(pre[i-1],cutd[stack[i]]);
        if(siz[stack[i]]<=n/2)pre[i]=max(pre[i],siz[stack[i]]);
    }
    last[cnt+1]=0;
    for(int i=cnt;i>=1;--i){
        last[i]=max(last[i+1],cutd[stack[i]]);
        if(siz[stack[i]]<=n/2)last[i]=max(last[i],siz[stack[i]]);
    }
    for(int i=1;i<=cnt;++i){
        int now=max(pre[i-1],last[i+1]);
        now=max(now,cutu[u]);
        if(up[u]<=n/2)now=max(now,up[u]);
        cutu[stack[i]]=now;
        if(!ok[stack[i]]&&up[stack[i]]-cutu[stack[i]]<=n/2)ok[stack[i]]=1;
    }
    for(int i=head[u];i;i=nxt[i])
    if(v[i]!=f)dfs2(v[i],u);
}
void rd(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}}
int main(){
    rd(n);
    int s,e;
    for(int i=1;i<n;++i){
        rd(s);rd(e);
        add_edge(s,e);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;++i){
    putchar(ok[i]==1?'1':'0');
    if(i!=n)putchar(' ');
    else puts("");
}
    return 0;
}