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
const int N=2e5+10;
namespace MAIN{
    int n;
    struct P{
        int x,y;
        P() {}
        P(res x,res y):x(x),y(y) {}
        inline bool operator < (const RG P &b) const {
            return y!=b.y?y>b.y:x<b.x;
        }
    }a[N];
    int b[N],bx,c[N],cx;
#define lowbit(x) (x&-x)
    int tr[N];
    inline void modify(const res &x,const res &y){
        for(res i=x;i<=n;i+=lowbit(i))tr[i]+=y;
    }
    inline int query(const res &x){
        res ret=0;
        for(res i=x;i;i-=lowbit(i))ret+=tr[i];
        return ret;
    }
    LL ans;
    bool vis[N];
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++){
            res x=read(),y=read();
            a[i]=P(x,y),b[++bx]=x,c[++cx]=y;
        }
        sort(a+1,a+n+1),sort(b+1,b+bx+1),sort(c+1,c+cx+1),bx=int(unique(b+1,b+bx+1)-b-1),cx=int(unique(c+1,c+cx+1)-c-1);
        for(res i=1;i<=n;i++)a[i].x=int(lower_bound(b+1,b+bx+1,a[i].x)-b),a[i].y=int(lower_bound(c+1,c+cx+1,a[i].y)-c);
        for(res i=1;i<=n;){
            res j=i;
            while(a[i].y==a[j].y&&j<=n){if(!vis[a[j].x])modify(a[j].x,1),vis[a[j].x]=1;j++;}
            j--;
            res las=0;
            for(res k=i;k<=j;k++)ans+=1LL*(query(n)-query(a[k].x-1))*(query(a[k].x)-query(las)),las=a[k].x;
            i=j+1;
        }
        printf("%lld\n",ans);
    }
}
int main() {
//    srand((unsigned)time(NULL));
//    freopen("zao.in","r",stdin);
//    freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}