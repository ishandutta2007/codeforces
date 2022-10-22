//2018.10.24 by ljz
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
const int N=5e5+10;
namespace MAIN{
    int n,m;
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N];
    int head[N],cnt;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
    }
    int dep[N],son[N],siz[N],fa[N];
    void Dfs(const res &x,const res &depx){
        dep[x]=depx,siz[x]=1;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            Dfs(tox,depx+1);
            siz[x]+=siz[tox];
            if(siz[tox]>siz[son[x]])son[x]=tox;
        }
    }
    char p[N];
    typedef pair<int,int> Pair;
    vector<Pair> vec[N];
#define pb push_back
#define mp make_pair
#define fi first
#define se second
    bool vis[N],ans[N];
    int tot[N][26];
    inline bool check(res *a){
        bool flag=0;
        for(res i=0;i<26;i++)
            if(a[i]&1){
                if(flag)return 1;
                flag=1;
            }
        return 0;
    }
    void update(const res &x,const res &va){
        tot[dep[x]][p[x]-'a']+=va;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(!vis[tox])update(tox,va);
        }
    }
    void dfs(const res &x,const res &flag){
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox!=son[x])dfs(tox,0);
        }
        if(son[x])dfs(son[x],1),vis[son[x]]=1;
        update(x,1);
        for(res i=0,siz=vec[x].size();i<siz;i++)ans[vec[x][i].fi]=check(tot[vec[x][i].se]);
        vis[son[x]]=0;
        if(!flag)update(x,-1);
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read(),m=read();
        for(res i=2;i<=n;i++)fa[i]=read(),addedge(fa[i],i);
        Dfs(1,1);
        scanf("%s",p+1);
        for(res i=1;i<=m;i++){
            res a=read(),b=read();
            vec[a].pb(mp(i,b));
        }
        dfs(1,0);
        for(res i=1;i<=m;i++)puts(ans[i]?"No":"Yes");
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}