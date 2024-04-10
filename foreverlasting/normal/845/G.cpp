//2018.8.17 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register LL
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline LL read(){
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
inline LL _abs(const res &x){
    return x>0?x:-x;
}
inline LL _max(const res &x,const res &y){
    return x>y?x:y;
}
inline LL _min(const res &x,const res &y){
    return x<y?x:y;
}
const LL Max=63;
const LL N=1e5+10,M=1e5+10;
LL num[Max+2];
inline void insert(res x){
    for(res i=Max;~i;i--)
        if((x>>i)&1){
            if(!num[i]){num[i]=x;return;}
            x^=num[i];
        }
}
inline LL query(res x){
    res ret=x;
    for(res i=Max;~i;i--)ret=_min(ret,ret^num[i]);
    return ret;
}
struct E{
    LL next,to,val;
    E() {}
    E(res next,res to,res val):next(next),to(to),val(val) {}
}edge[M<<1];
LL head[N],cnt;
inline void addedge(res u,res v,res w){
    edge[++cnt]=E(head[u],v,w),head[u]=cnt;
    edge[++cnt]=E(head[v],u,w),head[v]=cnt;
}
LL n,m;
bool vis[N];
LL ans[N];
void dfs(res x,res Xor){
    ans[x]=Xor,vis[x]=1;
    for(res i=head[x];~i;i=edge[i].next){
        res tox=edge[i].to;
        if(vis[tox])insert(Xor^edge[i].val^ans[tox]);
        else dfs(tox,Xor^edge[i].val);
    }
}
int main(){
    memset(head,-1,sizeof(head));
    n=read(),m=read();
    for(res i=1;i<=m;i++){
        res u=read(),v=read(),w=read();
        addedge(u,v,w);
    }
    dfs(1,0);
    printf("%Ld\n",query(ans[n]));
    return 0;
}