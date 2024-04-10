//2021.11.19 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res int
#define LL long long
#define Inf 0x3f3f3f3f
#define sup 0x7fffffff
#define inf 0x3f3f3f3f
#define INF 2000000000000000000
//#define unl __int128
#define eps 1e-5
#define RG
#define db double
#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<LL,int> Pair;
//#define poly vector<int>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define uint unsigned int
#define lowbit(x) ((x)&-(x))
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
//char sr[1<<21],z[20];
//int C=-1,Z=0;
//inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
//inline void print(RG LL x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);
//}
template <typename T> inline void Read(T &x) {
    res c=gc();
    bool f=false;
    for(x=0;!isdigit(c);c=gc())if(c=='-')f=true;
    for(;isdigit(c);c=gc())x=x*10+c-'0';
    if(f)x=-x;
}
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
inline LL Read() {
    RG LL s=0;
    res ch=gc(),w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
//inline void write(RG unl x){
//    if(x>10)write(x/10);
//    putchar(int(x%10)+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
const int kcz=1000000007;
const int G=3,GI=332748118;
//inline void add(res &x,const res &y){
//    x+=y,x>=kcz?x-=kcz:1;
//}
//inline int Add(const res &x,const res &y){
//    return x+y>=kcz?x+y-kcz:x+y;
//}
//inline int mul(const res &x,const res &y){
//    return int(1ll*x*y%kcz);
//}
#define add(x,y) ((x)+=(y),(x)>=kcz?(x)-=kcz:1)
#define Add(x,y) ((x)+(y)>=kcz?(x)+(y)-kcz:(x)+(y))
#define mul(x,y) int(1ll*(x)*(y)%kcz)
#define Mul(x,y,d) int((ull)(x)*(y)/(d)%kcz)
inline int qpow(res x,res y=kcz-2){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
inline int qpow(res x,res y,const res &ljc){
    res ret=1;
    while(y){
        if(y&1)ret=int(1ll*ret*x%ljc);
        x=int(1ll*x*x%ljc),y>>=1;
    }
    return ret;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2021.11.19 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=150000+10;
namespace MAIN{
    int n,m,p;
    struct P{
        int num,tag,a[5],b[5];
    }tr[N<<2];
    int len[N<<2];
    inline P merge(const RG P &A,const RG P &B){
        RG P ret=A;
        ret.tag=0;
        for(res i=0;i<B.num;i++){
            RG bool fl=0;
            for(res j=0;j<ret.num&&!fl;j++)if(B.a[i]==ret.a[j])ret.b[j]+=B.b[i],fl=1;
            if(fl)continue;
            if(ret.num<p){ret.a[ret.num]=B.a[i],ret.b[ret.num]=B.b[i],ret.num++;continue;}
            res mnid=0;
            for(res j=1;j<ret.num;j++)if(ret.b[j]<ret.b[mnid])mnid=j;
            if(B.b[i]<ret.b[mnid]){
                for(res j=0;j<ret.num;j++)ret.b[j]-=B.b[i];
            }
            else {
                res tmp=ret.b[mnid];
                ret.a[mnid]=B.a[i],ret.b[mnid]=B.b[i];
                for(res j=0;j<ret.num;j++)ret.b[j]-=tmp;
            }
        }
        return ret;
    }
    void build(res rt,res l,res r){
        len[rt]=r-l+1;
        if(l==r){
            res x=read();
            tr[rt].num=tr[rt].b[0]=1,tr[rt].a[0]=x;
            return;
        }
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r),tr[rt]=merge(tr[rt<<1],tr[rt<<1|1]);
    }
    inline void change(const res &rt,const res &val){
        tr[rt].num=1,tr[rt].b[0]=len[rt],tr[rt].a[0]=val,tr[rt].tag=val;
    }
    inline void pushdown(const res &rt){
        if(!tr[rt].tag)return;
        change(rt<<1,tr[rt].tag),change(rt<<1|1,tr[rt].tag),tr[rt].tag=0;
    }
    void modify(res rt,res l,res r,const res &L,const res &R,const res &val){
        if(L<=l&&r<=R){change(rt,val);return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        if(L<=mid)modify(rt<<1,l,mid,L,R,val);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R,val);
        tr[rt]=merge(tr[rt<<1],tr[rt<<1|1]);
    }
    P query(res rt,res l,res r,const res &L,const res &R){
        if(L<=l&&r<=R)return tr[rt];
        pushdown(rt);
        res mid=(l+r)>>1;
        if(L<=mid&&R>mid)return merge(query(rt<<1,l,mid,L,R),query(rt<<1|1,mid+1,r,L,R));
        if(L<=mid)return query(rt<<1,l,mid,L,R);
        return query(rt<<1|1,mid+1,r,L,R);
    }
    inline void MAIN(){
        n=read(),m=read(),p=100/read(),build(1,1,n);
        while(m--){
            res opt=read(),l=read(),r=read();
            if(opt==1)modify(1,1,n,l,r,read());
            else {
                RG P ret=query(1,1,n,l,r);
                printf("%d ",ret.num);
                for(res i=0;i<ret.num;i++)printf("%d ",ret.a[i]);
                puts("");
            }
        }
    }
}
int main(){
//    srand(19260817);
//    freopen("data.in","r",stdin);
//    freopen("1.out","fw",stdout);
    res Case=1;
    while(Case--)MAIN::MAIN();
//    Ot();
    return 0;
}