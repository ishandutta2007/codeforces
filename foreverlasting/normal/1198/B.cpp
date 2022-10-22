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
const int N=2e5+10;
namespace MAIN{
    int mx[N<<2],tr[N<<2];
    int n,q;
    void build(res rt,res l,res r){
        if(l==r){tr[rt]=read();return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
    }
    inline void change(const res &rt,const res &va){
        mx[rt]=max(mx[rt],va),tr[rt]=max(tr[rt],va);
    }
    inline void pushdown(const res &rt){
        if(!mx[rt])return;
        change(rt<<1,mx[rt]),change(rt<<1|1,mx[rt]),mx[rt]=0;
    }
    void modify(res rt,res l,res r,const res &p,const res &va){
        if(l==r){tr[rt]=va;return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        if(p<=mid)modify(rt<<1,l,mid,p,va);
        else modify(rt<<1|1,mid+1,r,p,va);
    }
    void push(res rt,res l,res r){
        if(l==r){printf("%d ",tr[rt]);return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        push(rt<<1,l,mid),push(rt<<1|1,mid+1,r);
    }
	inline void MAIN(){
        n=read(),build(1,1,n),q=read();
        while(q--){
            res opt=read();
            if(opt==1){
                res p=read(),x=read();
                modify(1,1,n,p,x);
            }
            else {
                res x=read();
                change(1,x);
            }
        }
        push(1,1,n);
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