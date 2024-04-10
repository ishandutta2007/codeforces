//2019.9.5 by ljz
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
inline int read() {
    res s=0,ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s;
}
//inline int read() {
//    res s=0,ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
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
const int N=2e3+10;
namespace MAIN{
    int n,m,q;
    set<Pair> S;
    bitset<N> a[N],b[N];
    set<int> ans;
    int nxt[N];
    inline void del(const res &x,const res &y){
        nxt[x]=0;
        if((a[y]|a[x])!=a[y])ans.erase(x);
    }
    inline void ins(const res &x,const res &y){
        nxt[x]=y;
        if((a[y]|a[x])!=a[y])ans.insert(x);
    }
    inline void del(const res &x){
        RG Pair val=mp(a[x].count(),x);
        auto tmp=S.lower_bound(val),suf=tmp;
        suf++;
        if(tmp!=S.begin()){
            auto pre=tmp;
            pre--,del((*pre).se,(*tmp).se);
            if(suf!=S.end())ins((*pre).se,(*suf).se);
        }
        if(suf!=S.end())del((*tmp).se,(*suf).se);
        S.erase(tmp);
    }
    inline void ins(const res &x){
        RG Pair val=mp(a[x].count(),x);
        auto tmp=S.insert(val).fi,suf=tmp;
        suf++;
        if(tmp!=S.begin()){
            auto pre=tmp;
            pre--;
            if(suf!=S.end())del((*pre).se,(*suf).se);
            ins((*pre).se,(*tmp).se);
        }
        if(suf!=S.end())ins((*tmp).se,(*suf).se);
    }
    inline void MAIN(){
        n=read(),m=read(),q=read();
        for(res i=1;i<=m;i++)b[i]=b[i-1],b[i].set(i);
        for(res i=1;i<=n;i++)ins(i);
        while(q--){
            res X=read(),L=read(),R=read();
            del(X),a[X]^=b[R]^b[L-1],ins(X);
            if(ans.size()){
                res x=*ans.begin(),y=nxt[x],l=(a[x]&~a[y])._Find_first(),r=(~a[x]&a[y])._Find_first();
                if(x>y)swap(x,y);
                if(l>r)swap(l,r);
                printf("%d %d %d %d\n",x,l,y,r);
            }
            else puts("-1");
        }
    }
}
int main(){
//    srand(19260817);
//    freopen("signin.in","r",stdin);
//    freopen("signin.out","w",stdout);
    MAIN::MAIN();
    return 0;
}