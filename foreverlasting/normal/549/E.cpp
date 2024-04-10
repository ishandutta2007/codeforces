//2021.7.19 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
//#define unl __int128
#define eps 5.6e-12
#define RG
#define db double
//#define pc(x) __builtin_popcount(x)
//#define ctz(x) __builtin_ctz(x)
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
// inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
// }
//inline int read() {
//    res s=0,ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
// char sr[1<<21],z[20];
// int C=-1,Z=0;
// inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
// inline void print(res x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);
// }
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
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
int kcz=998244353;
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
inline int qpow(res x,res y=kcz-2){
    if(y<=0)return 1;
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2021.7.19 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=1e4+10;
namespace MAIN{
    inline db Rand(){
        return 1.0*rand()/RAND_MAX;
    }
    inline db Reps(){
        return 0;
//        return (rng()-0.5)*eps;
    }
    struct P{
        db x,y;
        P() {}
        P(db x,db y):x(x),y(y) {}
        inline void r(){
            cin>>x>>y,x+=Reps(),y+=Reps();
        }
        inline bool operator < (const RG P &B) const{
            return x<B.x||(x==B.x&&y<B.y);
        }
        inline db operator ^ (const RG P &B)const{
            return x*B.y-y*B.x;
        }
        inline db operator * (const RG P &B)const{
            return x*B.x+y*B.y;
        }
        inline bool operator << (const RG P &B)const{
            return (y<0)^(B.y<0)?B.y<0:(*this^B)>0||((*this^B)==0&&x>=0&&B.x<0);
        }
        inline P operator - () const{
            return P(-x,-y);
        }
    }a[N],b[N],c[N];
    inline db len(const P &a){
        return sqrt(a.x*a.x+a.y*a.y);
    }
    inline P operator + (const P &a,const P &b){
        return P(a.x+b.x,a.y+b.y);
    }
    inline P operator - (const P &a,const P &b){
        return P(a.x-b.x,a.y-b.y);
    }
    inline bool cmp(const P &a,const P &b){
        return (a^b)!=0?(a^b)>0:len(a)<len(b);
    }
    inline db dot(const RG P &x,const RG P &y,const RG P &z){
        return (((y)-(x))*((z)-(x)));
    }
    inline db crs(const RG P &x,const RG P &y,const RG P &z){
        return (((y)-(x))^((z)-(x)));
    }
    inline P angle(const RG P &x,const RG P &y,const RG P &z){
        return P(dot(x,y,z),crs(x,y,z));
    }
    inline int graham(res n,RG P *A,RG P *B){
        static int st[N];
        res top=0;
        sort(A+1,A+n+1);
        RG P o=A[1];
        for(res i=n;i;i--)A[i]=A[i]-o;
        sort(A+2,A+n+1,cmp);
        for(res i=1;i<=n;st[++top]=i,i++)while(top>=2&&((A[i]-A[st[top-1]])^(A[st[top]]-A[st[top-1]]))>=0)top--;
        for(res i=1;i<=top;i++)B[i]=A[st[i]]+o;
        for(res i=1;i<=n;i++)A[i]=A[i]+o;
        return top;
    }
    inline int up(RG P &x,const RG P y){
        return x<<y?x=y,1:0;
    }
    inline int down(RG P &x,const RG P y){
        return y<<x?x=y,1:0;
    }
    int convex;
    bool ck(res L,res R,const RG P *ch,const res &n){
        P mn(1,0),mx(inf,-1);
        res p=0;
        for(res i=L+1;i<R;i++)if(up(mn,angle(c[i],c[L],c[R])))p=i;
        for(res i=R+1;i!=L;i++){
            if(i==convex+1)i=1;
            if(i==L||i==R)break;
            down(mx,-angle(c[i],c[L],c[R]));
        }
        res fl=1;
        for(res i=1;i<=n;i++){
            RG P o=angle(ch[i],c[L],c[R]);
            if(!o.y){if(o.x<=0){fl=0;break;}}
            else if(o.y<0)down(mx,o);
            else up(mn,-o);
            if(!(mn<<mx)){fl=0;break;}
        }
        return fl||(p&&(ck(L,p,ch,n)||ck(p,R,ch,n)));
    }
    inline void MAIN(){
        res n=read(),m=read();
        for(res i=1;i<=n;i++)a[i].r();
        for(res i=1;i<=m;i++)b[i].r();
        convex=graham(n,a,c);
        if(convex==1||ck(1,convex,b,m)){puts("YES");return;}
        convex=graham(m,b,c);
        if(convex==1||ck(1,convex,a,n)){puts("YES");return;}
        puts("NO");
    }
}
int main(){
    srand(19260817);
    // freopen("tracing.in","r",stdin);
    // freopen("tracing.out","w",stdout);
    MAIN::MAIN();
//    Ot();
    return 0;
}
//-7.89849 -11.0472 1.06111e+09 -1
//-11.9047 0.967126
//35.9461 25.0495
//63.9339 51.8831