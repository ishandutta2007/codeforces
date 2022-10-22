//2019.9.2 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define unl __int128
#define eps 5.6e-8
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define gc getchar
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
//inline int read() {
//    res s=0,ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
const int N=3e5+10;
namespace MAIN{
    int n,m;
    set<int> S[N];
    int bl[N],siz,sz[N];
    void dfs(res x,res rt){
//        printf("%d %d\n",x,rt);
        bl[x]=rt,siz++;
        for(auto tox:S[x])if(tox!=1&&!bl[tox])dfs(tox,rt);
    }
    void dfs(res x){
        sz[x]=siz;
        for(auto tox:S[x])if(tox!=1&&!sz[tox])dfs(tox);
    }
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=m;i++){
            res u=read(),v=read();
            S[u].insert(v),S[v].insert(u);
        }
        if(S[1].count(n)){puts("1"),printf("%d %d\n",1,n);return;}
        for(res i=2;i<n;i++)if(S[1].count(i)&&S[i].count(n)){puts("2"),printf("%d %d %d\n",1,i,n);return;}
        for(auto x:S[1])for(auto y:S[x])if(S[y].count(n)){puts("3"),printf("%d %d %d %d\n",1,x,y,n);return;}
        for(auto x:S[1])for(auto y:S[x])if(y!=1&&!S[1].count(y)){puts("4"),printf("%d %d %d %d %d\n",1,x,y,1,n);return;}
//        puts("OK");
        for(auto x:S[1])if(!bl[x])siz=0,dfs(x,x),dfs(x);
//        puts("OK");
        res mn=n+10,mid=0;
        for(auto x:S[1])if(sz[x]!=S[x].size()&&S[x].size()<mn)mn=int(S[x].size()),mid=x;
        if(mid){
            puts("5");
            for(auto y:S[mid])
                if(y!=1)for(auto z:S[y])if(z!=1&&z!=mid&&!S[mid].count(z)){printf("%d %d %d %d %d %d\n",1,mid,y,z,mid,n);return;}
        }
        puts("-1");
    }
}
int main(){
//    srand(19260817);
//    freopen("signin.in","r",stdin);
//    freopen("signin.out","w",stdout);
    MAIN::MAIN();
    return 0;
}