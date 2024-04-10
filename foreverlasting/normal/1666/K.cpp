#include<bits/stdc++.h>
using namespace std;
#define res int
#define pb push_back
#define int long long
const int N=1e6+10;
int read()
{
	static int sl,fh,ch;
	sl=0;fh=1;ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int n,m,S,T;
struct E{
    int next,to,val;
    E() {}
    E(res next,res to,res val):next(next),to(to),val(val) {}
}edge[N<<1];
int head[N],cnt;
inline void addedge(const res &u,const res &v,const res &w){
    edge[++cnt]=E(head[u],v,w),head[u]=cnt;
    edge[++cnt]=E(head[v],u,w),head[v]=cnt;
}
int dep[N],cur[N];
int Q[N],he,ta;
inline bool bfs(){
    for(res i=S;i<=T;i++)dep[i]=0;
    dep[Q[he=ta=1]=S]=1;
    while(he<=ta){
        res u=Q[he++];
        for(res i=head[u];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(!dep[tox]&&edge[i].val)dep[tox]=dep[u]+1,Q[++ta]=tox;
        }
    }
    return dep[T]>0;
}
int dfs(res x,res flow){
    if(x==T||!flow)return flow;
    for(res &i=cur[x];~i;i=edge[i].next){
        res tox=edge[i].to;
        if(dep[tox]==dep[x]+1){
            res f=dfs(tox,min(flow,edge[i].val));
            if(f>0){
                edge[i].val-=f,edge[i^1].val+=f;
                return f;
            }
        }
    }
    return 0;
}
#define LL long long
#define inf 100000000000000000ll
inline LL solve(){
    LL ans=0;
    while(bfs()){
        for(res i=S;i<=T;i++)cur[i]=head[i];
        while(res f=dfs(S,inf))ans+=f;
    }
    return ans;
}
int Vis[N];
void dfs(res x){
    Vis[x]=1;
    for(res i=head[x];~i;i=edge[i].next){
        res tox=edge[i].to;
        if(Vis[tox]||edge[i].val==0)continue;
        dfs(tox);
    }
}
signed main(){
    n=read(),m=read();
    res A=read(),B=read();
    S=0,T=2*n+1,cnt=-1;
    memset(head,-1,sizeof(head));
    addedge(S,A,inf),addedge(A+n,T,inf);
    addedge(S,B+n,inf),addedge(B,T,inf);
    for(res i=1;i<=m;i++){
        res u=read(),v=read(),w=read();
        addedge(u,v+n,w),addedge(v,u+n,w);
    }
    LL ans=solve();
    dfs(S);
    string SS;
    for(res i=1;i<=n;i++){
        if(Vis[i]==Vis[i+n])SS.pb('C');
        else if(Vis[i]>Vis[i+n])SS.pb('A');
        else SS.pb('B');
    }
    printf("%lld\n",ans);
    cout<<SS<<endl;
    return 0;
}