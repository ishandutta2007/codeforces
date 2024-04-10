//2019.9.24 by ljz
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
#define ctz(x) __builtin_ctz(x)
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
#define kcz 1000000007
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
//char sr[1<<21],z[20];
//int C=-1,Z=0;
//inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
//inline void print(res x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);sr[++C]='\n';
//}
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
//inline void swap(res &x,res &y) {
//    x^=y^=x^=y;
//}
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
}
inline int Add(const res &x,const res &y){
    return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
}
inline int mul(const res &x,const res &y){
    return int(1LL*x*y%kcz);
}
inline int mul(const res &x,const res &y,const res &d){
    return int(1LL*x*y/d%kcz);
}
inline int qpow(res x,res y){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
const int N=4e5+10;
namespace MAIN{
    int n,I;
    int a[N],b[N];
    int buc[N];
    int pre[N],suf[N];
	inline void MAIN(){
	    n=read(),I=8*read();
	    for(res i=1;i<=n;i++)a[i]=b[i]=read();
	    sort(b+1,b+n+1);
	    res nw=int(unique(b+1,b+n+1)-b-1);
	    for(res i=1;i<=n;i++)a[i]=int(lower_bound(b+1,b+nw+1,a[i])-b),buc[a[i]]++;
	    sort(a+1,a+n+1);
	    if(log2(nw)<=I/n){puts("0");return;}
//	    for(res i=1;i<=n;i++)printf("%d ",a[i]);
	    for(res i=1;i<=nw;i++)pre[i]=pre[i-1]+buc[i];
	    for(res i=nw;i;i--)suf[i]=suf[i+1]+buc[i];
	    res ans=inf;
	    res x=qpow(2,I/n);
	    for(res i=1;i<=nw;i++){
	        res sum=pre[i-1]+suf[i+x];
	        ans=min(ans,sum);
	    }
	    printf("%d\n",ans);
	}
}
int main() {
//    srand(19260817);
//    freopen("path.in","r",stdin);
//    freopen("path.out","w",stdout);
	MAIN::MAIN();
//    Ot();
	return 0;
}