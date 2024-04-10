//2019.7.15 by ljz
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
//inline void write(RG __int128 x){
//    if(x>10)write(x/10);
//    putchar(x%10+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e5+10;
namespace MAIN{
    int n;
    int a[N];
    LL sum;
    inline void MAIN(){
        n=read(),sum=-n*(n-1)/2;
        for(res i=1;i<=n;i++)a[i]=read(),sum+=a[i];
        sort(a+1,a+n+1);
        res cnt=0,id=0;
        for(res i=2;i<=n;i++)if(a[i]==a[i-1])cnt++,id=i;
        if(cnt>1){puts("cslnb");return;}
        if(cnt==1){
            if(a[id]==0){puts("cslnb");return;}
            for(res i=1;i<=n;i++)if(i!=id&&i!=id-1&&(a[i]==a[id]||a[i]==a[id]-1)){puts("cslnb");return;}
        }
        if(a[1]==0){
            RG bool fl=0;
            for(res i=2;i<=n;i++)
                if(a[i]!=a[i-1]+1){fl=1;break;}
            if(!fl){puts("cslnb");return;}
        }
        if(sum<=0){puts("cslnb");return;}
        if(sum&1){puts("sjfnb");return;}
        puts("cslnb");
    }
}
int main() {
//    srand((unsigned)time(NULL));
//    freopen("zao.in","r",stdin);
//    freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}