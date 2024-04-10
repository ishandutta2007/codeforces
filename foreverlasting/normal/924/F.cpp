// luogu-judger-enable-o2
//2019.9.6 by ljz
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
#define lowbit(x) (x&-x)
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
const int B=172;
const int N=44000+10;
namespace MAIN{
    typedef bitset<B> bit;
    unordered_map<bit,int> M;
    bit A,a[N];
    bool vis[20][N];
    int cnt=1;
    int nxt[N][10];
    LL dp[20][10][N];
    int b[20];
    inline LL solve(RG LL n,const res &k){
        if(n==0)return 1;
        res m=0,u=1;
        while(n)b[m++]=int(n%10),n/=10;
        RG LL ret=0;
        for(res i=m-1;~i;i--){
            for(res j=0;j<b[i]+(i==0);j++)ret+=dp[i][k][nxt[u][j]];
            u=nxt[u][b[i]];
        }
        return ret;
    }
    inline void MAIN(){
        A.set(0),a[M[A]=1]=A,vis[0][1]=1;
        for(res i=1;i<20;i++)
            for(res u=1;u<=cnt;u++)
                if(vis[i-1][u])
                    for(res j=0;j<10;j++){
                        if(!nxt[u][j]){
                            if(!j)nxt[u][j]=u;
                            else {
                                A.reset();
                                for(res k=j;k<B;k++)if(a[u][k])A[k-j]=1;
                                for(res k=0;k<B-j;k++)if(a[u][k])A[k+j]=1;
                                for(res k=1;k<j;k++)if(a[u][k])A[j-k]=1;
                                if(M.count(A))nxt[u][j]=M[A];
                                else a[nxt[u][j]=M[A]=++cnt]=A;
                            }
                        }
                        vis[i][nxt[u][j]]=1;
                    }
        for(res j=1;j<=cnt;j++){
            res k=0;
            for(;k<10;k++)if(a[j][k])break;
            for(;k<10;k++)dp[0][k][j]=1;
        }
        for(res j=1;j<19;j++)
            for(res k=1;k<=cnt;k++)
                if(vis[19-j][k])
                    for(res i=0;i<10;i++)
                        for(res l=0;l<10;l++)
                            dp[j][l][k]+=dp[j-1][l][nxt[k][i]];
        res T=read();
        while(T--){
            RG LL l=Read(),r=Read();
            res k=read();
            printf("%lld\n",solve(r,k)-solve(l-1,k));
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