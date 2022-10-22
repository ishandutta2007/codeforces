//2021.7.14 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
//#define unl __int128
#define eps 5.6e-8
#define RG
#define db double
//#define pc(x) __builtin_popcount(x)
//#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define lowbit(x) (x&-x)
#define gc getchar
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
// }
//inline int read() {
//    res s=0,ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
// char sr[1<<21],z[20];
// int C=-1,Z=0;
// inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
// inline void print(res x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);
// }
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
inline LL Read() {
    RG LL s=0;
    res ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s;
}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
//inline void write(RG unl x){
//    if(x>10)write(x/10);
//    putchar(int(x%10)+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
int kcz=998244353;
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
}
inline int Add(const res &x,const res &y){
    return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
}
inline int mul(const res &x,const res &y){
    return int(1LL*x*y%kcz);
}
inline int mul(const res &x,const res &y,const res &d){
    return int(1LL*x*y/d%kcz);
}
inline int qpow(res x,res y=kcz-2){
    if(y<=0)return 1;
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2021.7.14 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=2e5+10;
namespace MAIN{
    int n,m,k;
    vector<int> G[N];
    struct E{
        int next,to,fl;
        E() {}
        E(res next,res to):next(next),to(to),fl(0) {}
    }edge[N<<1];
    int head[N],cnt=-1;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
        edge[++cnt]=E(head[v],u),head[v]=cnt;
    }
    bool vis[N];
    void dfs(res x){
        vis[x]=1;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(vis[tox])continue;
            G[x].pb(tox),edge[i].fl=edge[i^1].fl=1,dfs(tox);
        }
    }
    int dep[N],fa[N];
    void Dfs(res x){
        for(auto tox:G[x])dep[tox]=dep[x]+1,fa[tox]=x,Dfs(tox);
    }
    inline void MAIN(){
        n=read(),m=read(),k=read();
        for(res i=1;i<=n;i++)head[i]=-1;
        for(res i=1;i<=m;i++){
            res u=read(),v=read();
            addedge(u,v);
        }
        dfs(1),Dfs(1);
        if(m==n-1){
            puts("1");
            res s=0;
            for(res x=1;x<=n;x++)s+=(dep[x]&1);
            if(s>=(k+1)/2){
                res t=0;
                for(res x=1;x<=n;x++){
                    if(dep[x]&1)printf("%d ",x),t++;
                    if(t==(k+1)/2)return;
                }
            }
            else {
                res t=0;
                for(res x=1;x<=n;x++){
                    if((dep[x]^1)&1)printf("%d ",x),t++;
                    if(t==(k+1)/2)return;
                }
            }
        }
        for(res x=1;x<=n;x++){
            for(res i=head[x];~i;i=edge[i].next){
                if(edge[i].fl)continue;
                res tox=edge[i].to;
                if(abs(dep[x]-dep[tox])+1<=k){
                    puts("2");
                    if(dep[x]>dep[tox])swap(x,tox);
                    printf("%d\n",dep[tox]-dep[x]+1);
                    for(res now=tox;now!=x;now=fa[now])printf("%d ",now);
                    printf("%d\n",x);return;
                }
            }
        }
        res id=0;
        for(res x=1;x<=n;x++)if(dep[id]<dep[x])id=x;
        res now=id,t=1;
        puts("1");
        printf("%d ",now);
        while(233){
            now=fa[fa[now]];
            printf("%d ",now),t++;
            if(t==(k+1)/2)return;
        }
    }
}
int main(){
//    srand(19260817);
    // freopen("tracing.in","r",stdin);
    // freopen("tracing.out","w",stdout);
    MAIN::MAIN();
//    Ot();
    return 0;
}