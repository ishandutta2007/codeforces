//2019.8.30 by ljz
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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
const int N=1e3+10;
namespace MAIN{
    int n;
    inline bool ck(const res &x){
        for(res i=2;i<=int(sqrt(x));i++)if(x%i==0)return 0;
        return 1;
    }
    bool lj[N][N];
    vector<Pair> vec;
    inline void MAIN(){
        n=read();
        if(ck(n)){
            printf("%d\n",n);
            for(res i=1;i<n;i++)printf("%d %d\n",i,i+1);
            printf("%d %d\n",1,n);
            return;
        }
        for(res i=1;i<n;i++)lj[i][i+1]=lj[i+1][i]=1;
        lj[n][1]=lj[1][n]=1;
        res p=0;
        for(res i=n+1;;i++)if(ck(i)){p=i;break;}
        res ex=p-n;
//        printf("%d\n",p);
        for(res i=1;i<=min(ex,n>>1);i++)lj[i][i+(n>>1)]=lj[i+(n>>1)][i]=1;
        if(ex<=n>>1){
            for(res i=1;i<=n;i++)
                for(res j=1;j<i;j++)
                    if(lj[i][j])vec.pb(mp(i,j));
            printf("%d\n",int(vec.size()));
            for(auto x:vec)printf("%d %d\n",x.fi,x.se);
            return;
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