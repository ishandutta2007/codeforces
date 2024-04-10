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
const int N=2e5+10;
namespace MAIN{
    int m,n;
    Pair a[N],b[N];
    LL sum[N];
    inline void add(res l,res r,const res &va,const res &fl){
        if(fl)swap(l,r);
        if(l<0&&r<0)l+=n,r+=n;
        if(l<0)sum[l+n]+=va,l=0;
        sum[l]+=va,sum[r+1]-=va;
    }
    int v[N];
    int Ans[N];
    inline void MAIN(){
        m=read(),n=read();
        for(res i=1;i<=n;i++)a[i]=mp(read(),i);
        sort(a+1,a+n+1);
        for(res i=1;i<=n;i++)b[i]=mp(read(),i);
        sort(b+1,b+n+1);
        for(res i=1;i<=n;i++)v[i]=b[i].fi;
        for(res i=1;i<=n;i++){
            res x=a[i].fi-1;
            if(x<=m-x)add(int(lower_bound(v+1,v+n+1,1)-v-i),int(upper_bound(v+1,v+n+1,x)-v-i-1),x+1,0);
            else add(int(lower_bound(v+1,v+n+1,x-m/2+1)-v-i),int(upper_bound(v+1,v+n+1,x)-v-i-1),x+1,0),add(int(lower_bound(v+1,v+n+1,1)-v-i),int(upper_bound(v+1,v+n+1,x-m/2)-v-i-1),-(x+1),0);
            x++;
            if(m-x<=x)add(int(lower_bound(v+1,v+n+1,x)-v-i),int(upper_bound(v+1,v+n+1,m)-v-i-1),-x,0);
            else add(int(lower_bound(v+1,v+n+1,x)-v-i),int(upper_bound(v+1,v+n+1,x+m/2)-v-i-1),-x,0),add(int(lower_bound(v+1,v+n+1,x+m/2+1)-v-i),int(upper_bound(v+1,v+n+1,m)-v-i-1),x,0);
        }
        for(res i=1;i<=n;i++)v[i]=a[i].fi;
        for(res i=1;i<=n;i++){
            res x=b[i].fi-1;
            if(x<=m-x)add(i-(int(lower_bound(v+1,v+n+1,1)-v)),i-(int(upper_bound(v+1,v+n+1,x+1)-v-1)),x+1,1);
            else add(i-(int(lower_bound(v+1,v+n+1,x-m/2+1)-v)),i-(int(upper_bound(v+1,v+n+1,x+1)-v-1)),x+1,1),add(i-(int(lower_bound(v+1,v+n+1,1)-v)),i-(int(upper_bound(v+1,v+n+1,x-m/2)-v-1)),m-(x+1),1);
            x++;
            if(m-x<=x)add(i-(int(lower_bound(v+1,v+n+1,x+1)-v)),i-(int(upper_bound(v+1,v+n+1,m)-v-1)),-x,1);
            else add(i-(int(lower_bound(v+1,v+n+1,x+1)-v)),i-(int(upper_bound(v+1,v+n+1,x+m/2)-v-1)),-x,1),add(i-(int(lower_bound(v+1,v+n+1,x+m/2+1)-v)),i-(int(upper_bound(v+1,v+n+1,m)-v-1)),m+x,1);
        }
        RG LL ans=INF;
        res pos=0;
        for(res i=0;i<n;i++){
            if(i)sum[i]+=sum[i-1];
            if(sum[i]<ans)ans=sum[i],pos=i;
        }
        printf("%lld\n",ans);
        for(res i=1;i<=n;i++)i+pos<=n?Ans[a[i].se]=b[i+pos].se:Ans[a[i].se]=b[i+pos-n].se;
        for(res i=1;i<=n;i++)printf("%d ",Ans[i]);
    }
}
int main(){
//    srand(19260817);
//    freopen("signin.in","r",stdin);
//    freopen("signin.out","w",stdout);
    MAIN::MAIN();
    return 0;
}