//2022.6.28 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
#include<random>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res int
#define LL long long
#define sup 0x7fffffff
#define inf 0x3f3f3f3f
#define INF 1000000000000000000
#define unl __int128
#define eps 1e-10
#define RG
#define db double
#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define poly vector<int>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define uint unsigned int
#define lowbit(x) ((x)&-(x))
#define gc getchar
#define ld long db
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//inline int gc(){
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
//char sr[1<<21],z[20];
//int C=-1,Z=0;
//inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
//inline void print(RG LL x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);
//}
//template <typename T> inline void Read(T &x) {
//    res c=gc();
//    bool f=false;
//    for(x=0;!isdigit(c);c=gc())if(c=='-')f=true;
//    for(;isdigit(c);c=gc())x=x*10+c-'0';
//    if(f)x=-x;
//}
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        else if(ch==EOF)break;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
inline LL Read() {
    RG LL s=0;
    res ch=gc(),w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        else if(ch==EOF)break;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
inline void write(unl x){
    if(x>10)write(x/10);
    putchar(int(x%10)+'0');
}
const int kcz=1000000007;
const int G=3,GI=332748118;
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:1;
}
inline int Add(const res &x,const res &y){
    return x+y>=kcz?x+y-kcz:x+y;
}
inline int mul(const res &x,const res &y){
    return (int)((LL)x*y%kcz);
}
inline int Mul(const res &x,const res &y,const res &d){
    return (int)((ull)(x)*(y)/(d)%kcz);
}
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
        if(y&1)ret=(int)(1ll*ret*x%ljc);
        x=(int)(1ll*x*x%ljc),y>>=1;
    }
    return ret;
}
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//std::mt19937(std::random_device()())
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}

//2022.6.28 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=2e5+10;
namespace MAIN{
    int n,q,x,y;
    ld d[3];
    struct TR{
        ld f[3][3];
        inline TR operator + (const TR &A) const {
            TR B={};
            for(res i=0;i<3;i++){
                for(res j=0;j<3;j++){
                    for(res k=0;k<3;k++){
                        for(res l=0;l<3;l++){
                            if(k==1&&l!=0)continue;
                            if(k!=0&&l==1)continue;
                            B.f[i][j]=max(B.f[i][j],f[i][k]+A.f[l][j]);
                        }
                    }
                }
            }
            return B;
        }
    }tr[N<<2];
    int a[N];
    void build(res rt,res l,res r){
        if(l==r){
            for(auto &i:tr[rt].f)for(ld &j:i)j=-INF;
            for(res i=0;i<3;i++)tr[rt].f[i][i]=d[i]*a[l];
            return;
        }
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        tr[rt]=tr[rt<<1]+tr[rt<<1|1];
    }
    TR query(res rt,res l,res r,const res &L,const res &R){
        if(L<=l&&r<=R)return tr[rt];
        res mid=(l+r)>>1;
        if(L<=mid&&R>mid)return query(rt<<1,l,mid,L,R)+query(rt<<1|1,mid+1,r,L,R);
        if(L<=mid)return query(rt<<1,l,mid,L,R);
        return query(rt<<1|1,mid+1,r,L,R);
    }
    void modify(res rt,res l,res r,const res &p){
        if(l==r){
            for(auto &i:tr[rt].f)for(ld &j:i)j=-INF;
            for(res i=0;i<3;i++)tr[rt].f[i][i]=d[i]*a[l];
            return;
        }
        res mid=(l+r)>>1;
        if(p<=mid)modify(rt<<1,l,mid,p);
        else modify(rt<<1|1,mid+1,r,p);
        tr[rt]=tr[rt<<1]+tr[rt<<1|1];
    }
    inline void MAIN(const res &Case){
        n=read(),q=read();
        x=read(),y=read();
        if(x>y)swap(x,y);
        d[0]=0,d[1]=(ld)1/y,d[2]=(ld)1/(x+y);
        for(res i=1;i<=n;i++)a[i]=read();
        build(1,1,n);
        while(q--){
            res opt=read();
            if(opt==1){
                res k=read(),v=read();
                a[k]=v,modify(1,1,n,k);
            }
            else {
                res l=read(),r=read();
                TR ret=query(1,1,n,l,r);
                ld ans=0;
                for(auto &i:ret.f)for(ld &j:i)ans=max(ans,j);
                printf("%.10Lf\n",ans);
            }
        }
    }
}
int main(){
//    srand(time(0));
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    res Case=1;
    for(res T=1;T<=Case;T++)MAIN::MAIN(T);
//    Ot();
    return 0;
}