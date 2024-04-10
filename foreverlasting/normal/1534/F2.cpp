//2021.7.7 by ljz
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
//2021.7.7 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=4e5+10;
namespace MAIN{
    char str[N];
    vector<char> v[N];
    vector<int> G[N];
    vector<int> E[N];
    int dfn[N],low[N],idx,vis[N],st[N],top,sig[N],nw;
//    int FL[N];
//    vector<int> C[N];
    int Fl[N];
    int mn[N],mx[N];
    void tarjan(res x){
        dfn[x]=low[x]=++idx,vis[st[++top]=x]=1;
        for(auto tox:G[x]){
            if(!dfn[tox])tarjan(tox),low[x]=min(low[x],low[tox]);
            else if(vis[tox])low[x]=min(low[x],dfn[tox]);
        }
        if(low[x]==dfn[x]){
            res y=0;
            nw++;
            do{
                vis[y=st[top--]]=0,sig[y]=nw;
//                C[sig[y]=nw].pb(y);
//                if(Fl[y])FL[nw]=1;
            }while(x!=y);
        }
    }
    int las[N];
    int a[N];
    int fl[N],du[N];
    vector<int> B;
    int Vis[N];
    void dfs(res x){
        Vis[x]=1;
        for(auto tox:E[x]){
            if(Vis[tox]){mn[x]=min(mn[x],mn[tox]),mx[x]=max(mx[x],mx[tox]);continue;}
            dfs(tox),mn[x]=min(mn[x],mn[tox]),mx[x]=max(mx[x],mx[tox]);
        }
    }
    int jud[N];
    void Dfs(res x){
        for(auto tox:E[x]){
//            if(Fl[tox])jud[Fl[tox]]=1;
//            Dfs(tox);
            if(jud[tox])continue;
            jud[tox]=1,Dfs(tox);
        }
    }
    Pair seg[N];
    int tot;
    int A[N];
    int Mpx;
    inline void MAIN(){
        res n=read(),m=read();
        for(res i=1;i<=n*m;i++)mn[i]=n*m+1;
        for(res i=1;i<=n;i++){
            scanf("%s",str+1);
            v[i].pb(' ');
            for(res j=1;j<=m;j++)v[i].pb(str[j]);
            for(res j=1;j<=m;j++){
                if(str[j]=='#'){
                    res id=(i-1)*m+j;
                    if(!las[j])B.pb(id);
                    fl[id]=1;
                    if(j>1&&las[j-1]){
                        G[las[j-1]].pb(id);
                        if(str[j-1]=='#')G[id].pb(las[j-1]);
                    }
                    if(j<m&&las[j+1])G[las[j+1]].pb(id);
                    if(las[j]){
                        G[las[j]].pb(id);
                        if(v[i-1][j]=='#')G[id].pb(las[j]);
                    }
                    las[j]=id;
                }
            }
        }
        for(res i=1;i<=m;i++)a[i]=read();
        for(res j=1;j<=m;j++){
            res now=0;
            for(res i=n;i;i--){
                if(v[i][j]=='#')now++;
                if(now==a[j]){Fl[(i-1)*m+j]=j,A[j]=(i-1)*m+j;break;}
            }
        }
//        for(res i=1;i<=n;i++){
//            for(res j=1;j<=m;j++)printf("%d ",Fl[(i-1)*m+j]);
//            puts("");
//        }
        for(res i=1;i<=n*m;i++)if(!dfn[i]&&fl[i])tarjan(i);
//        for(res i=1;i<=m;i++)if(!jud[i])Dfs(A[i]);
//        for(res i=1;i<=n*m;i++)vis[i]=0;
//        for(res x=1;x<=n*m;x++){
//            if(!fl[x])continue;
//            for(auto tox:G[x]){
//                if(sig[tox]==sig[x])continue;
//                if(vis[sig[tox]])continue;
//                if(FL[sig[x]]&&FL[sig[tox]]&&!vis[sig[tox]]){
//                    for(auto p:C[sig[tox]])if(Fl[p])jud[Fl[p]]=1;
//                    vis[sig[tox]]=1;
//                }
////                E[sig[x]].pb(sig[tox]),du[sig[tox]]++;
//            }
//        }
//        for(res i=1;i<=nw;i++)if(!vis[i]){
//                res la=0;
//                for(auto x:C[i]){
//                    if(Fl[x])la=x;
//                }
//                for(auto x:C[i]){
//                    if(Fl[x]&&x!=la)jud[Fl[x]]=1;
//                }
//            }
        for(res x=1;x<=n*m;x++){
            if(!fl[x])continue;
            for(auto tox:G[x]){
                if(sig[tox]==sig[x])continue;
//                if(vis[sig[tox]])continue;
                E[sig[x]].pb(sig[tox]),du[sig[tox]]++;
            }
        }
        for(res i=1;i<=m;i++)if(a[i])Dfs(sig[A[i]]);
        for(res i=1;i<=m;i++){
            if(jud[sig[A[i]]]||!a[i]||mx[sig[A[i]]])continue;
            mn[sig[A[i]]]=mx[sig[A[i]]]=++Mpx;
        }
//        printf("%d\n",Mpx);
        for(res i=1;i<=nw;i++)if(!du[i])dfs(i),seg[++tot]=mp(mn[i],mx[i]);
//        for(res i=1;i<=nw;i++){
//            for(auto x:C[i])printf("%d ",x);
//            puts("");
//        }
        sort(seg+1,seg+tot+1);
//        puts("Seg l,r:");
//        for(res i=1;i<=tot;i++)printf("%d %d\n",seg[i].fi,seg[i].se);
//        puts("");
//        for(res i=1;i<=Mpx;i++)b[i]=a[mP[i]];
//        for(res i=1;i<=Mpx;i++)a[i]=b[i];
//        for(res i=Mpx+1;i<=m;i++)a[i]=0;
//        for(res i=1;i<=m;i++)printf("%d ",a[i]);puts("");
//        if(m!=80000){
        res l=0,ans=0;
        for(res i=1,rm=0,rf=0,j=1;i<=Mpx;i++){
            while(j<=tot&&seg[j].fi<=i)rf=max(rf,seg[j].se),j++;
            if(i>rm)ans++,rm=rf;
        }
        printf("%d\n",ans);
//        for(res i=1;i<=tot;){
//            res j=i,r=l;
//            while(j<=tot&&seg[j].fi<=l+1)r=max(r,seg[j].se),j++;
////            printf("k:%d j:%d r:%d\n",k,j,r);
//            i=j,ans++,l=r;
//        }
//        if(l>=Mpx)printf("%d\n",ans);
//        else puts("-1");
//        }
//        else puts("-1");
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