//2019.9.1 by ljz
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
    int n,x1,x2;
    struct P{
        int va,id;
        P() {}
        P(res va,res id):va(va),id(id) {}
        inline void init(const res &I){
            va=read(),id=I;
        }
        inline bool operator < (const RG P &b) const {
            return va<b.va;
        }
    }a[N],b[N];
    int l,r,L,R;
    inline void MAIN(){
        n=read(),x1=read(),x2=read();
        for(res i=1;i<=n;i++)a[i].init(i);
        sort(a+1,a+n+1);
        for(res i=1;i<=n;i++){
            res I=int(lower_bound(a+1,a+n+1,P((int)(ceil)(1.0*x1/i),0))-a);
            if(I+i-1<=n){l=I,r=I+i-1;break;}
        }
        if(l){
            for(res i=1;i<l;i++)b[i]=a[i];
            for(res i=r+1;i<=n;i++)b[i-(r-l+1)]=a[i];
            for(res i=l;i<=r;i++)b[i+(n-r)]=a[i];
            for(res i=1;i<=n-(r-l+1);i++){
                res I=int(lower_bound(b+1,b+n-(r-l+1)+1,P((int)(ceil)(1.0*x2/i),0))-b);
//                printf("%d %d\n",b[I].va,i);
                if(I+i-1<=n-(r-l+1)){L=I,R=I+i-1;break;}
            }
//            printf("%d\n",R-L+1);
//        if(!L){puts("No");return;}
            if(L){
                puts("Yes");
                printf("%d %d\n",r-l+1,R-L+1);
                for(res i=n-(r-l);i<=n;i++)printf("%d ",b[i].id);puts("");
                for(res i=L;i<=R;i++)printf("%d ",b[i].id);
                return;
            }
        }
        l=r=L=R=0;
        for(res i=1;i<=n;i++){
            res I=int(lower_bound(a+1,a+n+1,P((int)(ceil)(1.0*x2/i),0))-a);
            if(I+i-1<=n){l=I,r=I+i-1;break;}
        }
        if(l){
            for(res i=1;i<l;i++)b[i]=a[i];
            for(res i=r+1;i<=n;i++)b[i-(r-l+1)]=a[i];
            for(res i=l;i<=r;i++)b[i+(n-r)]=a[i];
            for(res i=1;i<=n-(r-l+1);i++){
                res I=int(lower_bound(b+1,b+n-(r-l+1)+1,P((int)(ceil)(1.0*x1/i),0))-b);
                if(I+i-1<=n-(r-l+1)){L=I,R=I+i-1;break;}
            }
//        if(!L){puts("No");return;}
            if(L){
                puts("Yes");
                printf("%d %d\n",R-L+1,r-l+1);
                for(res i=L;i<=R;i++)printf("%d ",b[i].id);puts("");
                for(res i=n-(r-l);i<=n;i++)printf("%d ",b[i].id);
                return;
            }
        }
        puts("No");
    }
}
int main(){
//    srand(19260817);
//    freopen("zao.in","r",stdin);
//    freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}