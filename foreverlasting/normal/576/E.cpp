//2018.8.10 by ljz
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
const int M=5e5+10,Q=5e5+10,N=5e5+10,K=50+10;
int n,m,k,q;
struct E{
    int u,v;
    E() {}
    E(res u,res v):u(u),v(v) {}
}edge[M];
struct MOD{
    int s,col,id,l,r;
    MOD() {}
    MOD(res s,res col,res id,res l):s(s),col(col),id(id),l(l) {}
}mod[Q];
int las[M],pre[Q],nxt[Q];
vector<MOD> F[Q<<2];
void insertmodify(res rt,res l,res r,res L,res R,MOD id){
    if(L<=l&&r<=R){
        F[rt].push_back(id);
        return;
    }
    if(l==r)return;
    res mid=(l+r)>>1;
    if(L<=mid)insertmodify(rt<<1,l,mid,L,R,id);
    if(R>mid)insertmodify(rt<<1|1,mid+1,r,L,R,id);
}
int st[Q][3],top;
namespace UNOINSET{
    int fa[K][M],H[K][M];
    bool va[K][M];
    int find(res x,res col,bool &flag){
    	while(fa[col][x])flag^=va[col][x],x=fa[col][x];
    	return x;
    }
    inline void unoin(res x,res y,res col,bool flag){
        if(H[col][x]>H[col][y])_swap(x,y);
        fa[col][x]=y,va[col][x]=flag,st[++top][0]=x,st[top][1]=col,st[top][2]=0;
        if(H[col][x]==H[col][y])H[col][y]++,st[top][2]=1;
    }
}
using namespace UNOINSET;
inline void solve(vector<MOD>G){
    if(!G.size())return;
    for(res i=0;i<G.size();i++){
        if(!mod[G[i].id].col)continue;
        res x=edge[G[i].s].u,y=edge[G[i].s].v,col=mod[G[i].id].col;
        bool flag=1;
        res fx=find(x,col,flag),fy=find(y,col,flag);
//		printf("%d %d\n",fx,fy);
        if(fx==fy)continue;
        unoin(fx,fy,col,flag);
    }
}
inline void remove(res now){
	while(top>now){
        if(st[top][2])st[top][2]=0,H[st[top][1]][fa[st[top][1]][st[top][0]]]--;
        fa[st[top][1]][st[top][0]]=0,top--;
    }
}
void segdiv(res rt,res l,res r){
    res now=top;
    solve(F[rt]);
    if(l==r){
        res x=edge[mod[l].s].u,y=edge[mod[l].s].v,col=mod[l].col;
        bool flag=1;
        res fx=find(x,col,flag),fy=find(y,col,flag);
//		printf("%d %d\n",fx,fy);
//		printf("%d\n",flag);
        if(fx==fy&&flag)puts("NO"),mod[l].col=mod[pre[l]].col;
        else puts("YES");
        remove(now);
        return;
    }
    res mid=(l+r)>>1;
    segdiv(rt<<1,l,mid),segdiv(rt<<1|1,mid+1,r);
    remove(now);
}
int main(){
    n=read(),m=read(),k=read(),q=read();
    for(res i=1;i<=m;i++){
        res u=read(),v=read();
        edge[i]=E(u,v);
    }
    for(res i=1;i<=q;i++){
        res s=read(),col=read();
        mod[i]=MOD(s,col,i,i+1);
        if(las[s])pre[i]=las[s],nxt[las[s]]=i-1;
        las[s]=i,nxt[i]=q;
    }
    for(res i=1;i<=q;i++)if(mod[i].l<=(mod[i].r=nxt[i]))insertmodify(1,1,q,mod[i].l,mod[i].r,mod[i]);
//	for(res i=1;i<=q;i++)printf("%d %d %d %d %d\n",mod[i].id,mod[i].l,mod[i].r,mod[i].s,mod[i].col);
    segdiv(1,1,q);
    return 0;
}