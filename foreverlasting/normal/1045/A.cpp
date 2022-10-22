#include<bits/stdc++.h>
#define inf 1234567890
#define T 33333
int n,m,cnt=1,d[200005],node,head[44444],iter[44444],dep[44444],ys[5001],tot[5001];
struct edge{
    int to,nxt,cap;
}e[2333333];
struct wea{
    int op,l,r,a,b,c,k;
}v[5005];
inline void addedge(int u,int v,int cap){
    e[++cnt]=(edge){v,head[u],cap};head[u]=cnt;
    e[++cnt]=(edge){u,head[v],0};head[v]=cnt;
}
void build(int l,int r,int o){
    if(l==r){
        d[o]=l;
        return;
    }
    d[o]=++node;
    const int mid=l+r>>1;
    build(l,mid,o<<1);
    build(mid+1,r,o<<1|1);
    addedge(d[o],d[o<<1],inf);
    addedge(d[o],d[o<<1|1],inf);
}
void add(int l,int r,int o,int id,const int&L,const int&R){
    if(L<=l&&r<=R){
        addedge(id,d[o],1);
        return;
    }
    const int mid=l+r>>1;
    if(L<=mid)add(l,mid,o<<1,id,L,R);
    if(mid<R)add(mid+1,r,o<<1|1,id,L,R);
}
std::queue<int>q;
void bfs(){
    dep[0]=1;
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=e[i].nxt)
        if(e[i].cap&&!dep[e[i].to]){
            dep[e[i].to]=dep[u]+1;
            q.push(e[i].to);
        }
    }
}
int dfs(int u,int f){
    if(!f||u==T)return f;
    for(int&i=iter[u];i;i=e[i].nxt)
    if(e[i].cap&&dep[u]<dep[e[i].to]){
        int d=dfs(e[i].to,std::min(f,e[i].cap));
        if(d){
            e[i].cap-=d;
            e[i^1].cap+=d;
            return d;
        }
    }
    return 0;
}
int dinic(){
    for(int f,flow=0;;){
        memset(dep,0,sizeof dep);
        bfs();
        if(!dep[T])return flow;
        memcpy(iter,head,sizeof iter);
        while(f=dfs(0,inf))flow+=f;
    }
}
void find(int now,int&s,int pre){
    if(s)return;
    if(now>m&&now<=n+m){
        s=now-m;
        return;
    }
    for(int i=head[now];i;i=e[i].nxt)
    if(e[i].to!=pre&&e[i].cap){
        find(e[i].to,s,now);
        --e[i].cap;
        return;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    node=n+m;
    build(1,m,1);
    for(int i=1;i<=n;++i){
        scanf("%d",&v[i].op);
        if(v[i].op==0){
            scanf("%d",&v[i].k);
            addedge(0,i+m,1);
            for(int j=0;j<v[i].k;++j){
                int x;
                scanf("%d",&x);
                addedge(i+m,x,1);
            }
        }else
        if(v[i].op==1){
            addedge(0,i+m,1);
            scanf("%d%d",&v[i].l,&v[i].r);
            add(1,m,1,i+m,v[i].l,v[i].r);
        }else{
            addedge(0,i+m,2);
            scanf("%d%d%d",&v[i].a,&v[i].b,&v[i].c);
            addedge(i+m,v[i].a,1);
            addedge(i+m,v[i].b,1);
            addedge(i+m,v[i].c,1);
        }
    }
    for(int i=1;i<=m;++i)addedge(i,T,1);
    int mx=dinic();
    printf("%d\n",mx);
    for(int i=head[T];i;i=e[i].nxt)
    if(e[i].cap){
        find(e[i].to,ys[e[i].to],T);
    }
    for(int i=1;i<=m;++i)++tot[ys[i]];
    for(int i=1;i<=n;++i)
    if(v[i].op==2&&tot[i]==1){
        if(ys[v[i].a]!=i)ys[v[i].a]=i;else
        ys[v[i].b]=i;
    }
    for(int i=1;i<=m;++i)
    if(ys[i])printf("%d %d\n",ys[i],i);
    return 0;
}