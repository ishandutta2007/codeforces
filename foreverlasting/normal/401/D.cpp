//2019.7.18 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define eps 1e-10
#define RG register
#define db long double
#define lb long db
#define pc(x) __builtin_popcount(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define gc getchar
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
//inline void write(RG __int128 x){
//    if(x>10)write(x/10);
//    putchar(x%10+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace MAIN{
    LL n;
    int m;
    LL dp[(1<<18)+10][100+10];
    int num[18+10],cnt;
    bool vis[10+10];
    inline void MAIN(){
        n=Read(),m=read(),dp[0][0]=1;
        while(n)num[cnt++]=int(n%10),n/=10;
        res end=(1<<cnt)-1;
        for(res S=0;S<=end;S++){
            for(res i=0;i<=9;i++)vis[i]=0;
            for(res i=0;i<=cnt;i++){
                if(S==(1<<i)&&!num[i])break;
                if(S&(1<<i)&&!vis[num[i]]){
                    vis[num[i]]=1;
                    for(res j=0;j<m;j++)
                        dp[S][(j*10+num[i])%m]=dp[S][(j*10+num[i])%m]+dp[S^(1<<i)][j];
                }
            }
        }
        printf("%lld\n",dp[end][0]);
    }
}
int main() {
//    srand((unsigned)time(NULL));
//    freopen("route.in","r",stdin);
//    freopen("route.out","w",stdout);
    MAIN::MAIN();
    return 0;
}