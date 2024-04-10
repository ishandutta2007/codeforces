//2019.7.3 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 1100005
#define INF 0x3f3f3f3f3f3f3f
#define eps 1e-10
#define RG register
#define db double
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
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5+10;
namespace MAIN{
    int n,k,d,a[N],L=1,R=1;
    map<int,int> M;
    int laz[N<<2],mn[N<<2];
    void modify(res rt,res l,res r,const res &L,const res &R,const res &va){
        if(L<=l&&r<=R){laz[rt]+=va,mn[rt]+=va;return;}
        res mid=(l+r)>>1;
        if(L<=mid)modify(rt<<1,l,mid,L,R,va);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R,va);
        mn[rt]=min(mn[rt<<1],mn[rt<<1|1])+laz[rt];
    }
    int query(res rt,res l,res r,res va){
        va-=laz[rt];
        if(l==r)return l;
        res mid=(l+r)>>1;
        return (mn[rt<<1]<=va)?query(rt<<1,l,mid,va):query(rt<<1|1,mid+1,r,va);
    }
    int st0[N],st1[N],tp0,tp1;
    inline void MAIN(){
        n=read(),k=read(),d=read();
        for(res i=1;i<=n;i++)a[i]=read()+1000000000+1;
        if(d==0){
            res j=1;
            for(res i=1;i<=n;i=j+1){
                for(j=i;j<=n;j++)if(a[j]!=a[i])break;
                j--;
                if(R-L<j-i)L=i,R=j;
            }
            printf("%d %d\n",L,R);
            return;
        }
        modify(1,1,n,1,n,inf);
        for(res i=1,las=0;i<=n;i++){
            if(i!=1&&(a[i]-a[i-1])%d)modify(1,1,n,las+1,i-1,inf),las=i-1;
            if(M[a[i]]>las)modify(1,1,n,las+1,M[a[i]],inf),las=M[a[i]];
            M[a[i]]=i;
            while(tp0&&a[i]>a[st0[tp0]])modify(1,1,n,st0[tp0-1]+1,st0[tp0],a[i]/d-a[st0[tp0]]/d),tp0--;
            while(tp1&&a[i]<a[st1[tp1]])modify(1,1,n,st1[tp1-1]+1,st1[tp1],a[st1[tp1]]/d-a[i]/d),tp1--;
            st0[++tp0]=st1[++tp1]=i,modify(1,1,n,i,i,-inf+i);
            res p=query(1,1,n,i+k);
            if(i-p>R-L)L=p,R=i;
        }
        printf("%d %d\n",L,R);
    }
}
int main() {
//    srand((unsigned)time(NULL));
    // freopen("zao.in","r",stdin);
    // freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}