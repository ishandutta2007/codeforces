//2019.1.25 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _abs(const res &x) {
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
typedef vector<int> vec;
#define pb push_back
const int N=2.5e5+10,M=5e5+10;
namespace MAIN {
    vec leaf;
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[M<<1];
    int head[N],cnt;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
        edge[++cnt]=E(head[v],u),head[v]=cnt;
    }
    bool vis[N],lea[N];
    int fa[N],dep[N];
    int n,m,k;
    void dfs(const res &x,const res &fax,const res &depx){
        fa[x]=fax,dep[x]=depx,vis[x]=1;
        if(depx>=(n+k-1)/k){
            puts("PATH");
            printf("%d\n",depx);
            for(res i=x;i;i=fa[i])printf("%d ",i);
            puts("");
            exit(0);
        }
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(vis[tox])continue;
            dfs(tox,x,depx+1),lea[x]=1;
        }
        if(!lea[x])leaf.pb(x);
    }
    inline bool cmp(const res &x,const res &y){
        return dep[x]<dep[y];
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read(),m=read(),k=read();
        for(res i=1;i<=m;i++){
            res u=read(),v=read();
            addedge(u,v);
        }
        dfs(1,0,1);
        puts("CYCLES");
        for(res t=0;t<k;t++){
            res x=leaf[t];
            bool flag=0;
            vec pos;
            pos.clear();
            for(res i=head[x];~i;i=edge[i].next){
                res tox=edge[i].to;
                if(pos.size()!=2)pos.pb(tox);
                if(tox==fa[x]||(dep[x]-dep[tox]+1)%3==0)continue;
                printf("%d\n",dep[x]-dep[tox]+1);
                for(res p=x;p!=fa[tox];p=fa[p])printf("%d ",p);
                puts("");
                flag=1;
                break;
            }
            if(flag)continue;
            sort(pos.begin(),pos.end(),cmp);
            printf("%d\n",dep[pos[1]]-dep[pos[0]]+2);
            res a=pos[0],b=pos[1];
            while(fa[a]!=fa[b])printf("%d ",b),b=fa[b];
            printf("%d %d\n",b,x);
        }
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}