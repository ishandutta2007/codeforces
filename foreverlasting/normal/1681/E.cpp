//2022.5.24 by ljz
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

//2022.5.24 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=2e5+10;
namespace MAIN{
    int n;
    struct Matrix{
        LL t[2][2];
        inline Matrix operator * (const Matrix &A) const {
            Matrix B{};
            for(res i=0;i<2;i++){
                for(res j=0;j<2;j++){
                    LL ret=INF;
                    for(res k=0;k<2;k++){
                        ret=min(ret,t[i][k]+A.t[k][j]);
                    }
                    B.t[i][j]=ret;
                }
            }
            return B;
        }
    }a[N],tr[N<<2];
    void build(res rt,res l,res r){
        if(l==r){
            tr[rt]=a[l];
            return;
        }
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        tr[rt]=tr[rt<<1]*tr[rt<<1|1];
    }
    Matrix query(res rt,res l,res r,const res &L,const res &R){
        if(L<=l&&r<=R)return tr[rt];
        res mid=(l+r)>>1;
        if(L<=mid&&R>mid)return query(rt<<1,l,mid,L,R)*query(rt<<1|1,mid+1,r,L,R);
        if(L<=mid)return query(rt<<1,l,mid,L,R);
        return query(rt<<1|1,mid+1,r,L,R);
    }
    int p[N][2];
    inline void MAIN(const res &Case){
        n=read();
        for(res i=1;i<=4;i++)read();
        p[1][0]=p[1][1]=1;
        res px=1,py=1;
        for(res i=2;i<=n-1;i++){
            read();
            res y=read(),X=read();
            read();
            a[n-i+1].t[0][0]=abs(y-px);
            a[n-i+1].t[1][0]=i-px+i-X;
            a[n-i+1].t[0][1]=i-py+i-y;
            a[n-i+1].t[1][1]=abs(X-py);
            p[i][0]=y,p[i][1]=X;
            px=y,py=X;
        }
        if(2<=n-1)build(1,2,n-1);
        res q=read();
        while(q--){
            res x1=read(),y1=read(),x2=read(),y2=read(),x=max(x1,y1),y=max(x2,y2);
            if(x>y)swap(x1,x2),swap(y1,y2),swap(x,y);
            if(x==y){
                LL ans=INF;
                if(x1>y1){
                    if(x2>y2){
                        ans=abs(y1-y2);
                    }
                    else {
                        ans=x-y1+x-x2;
                    }
                }
                else {
                    if(x2>y2){
                        ans=x-x1+x-y2;
                    }
                    else {
                        ans=abs(x1-x2);
                    }
                }
                printf("%lld\n",ans);
                continue;
            }
            if(x+1==y){
                LL ans=INF;
                if(x1>y1){
                    if(x2>y2){
                        ans=min(ans,(LL)abs(y1-p[x][0])+abs(y2-p[x][0]));
                        ans=min(ans,(LL)x-y1+x-p[x][1]+y-p[x][1]+y-y2);
                    }
                    else {
                        ans=min(ans,(LL)abs(y1-p[x][0])+y-p[x][0]+y-x2);
                        ans=min(ans,(LL)x-y1+x-p[x][1]+abs(x2-p[x][1]));
                    }
                }
                else {
                    if(x2>y2){
                        ans=min(ans,(LL)abs(x1-p[x][1])+y-p[x][1]+y-y2);
                        ans=min(ans,(LL)x-x1+x-p[x][0]+abs(y2-p[x][0]));
                    }
                    else {
                        ans=min(ans,(LL)abs(x1-p[x][1])+abs(x2-p[x][1]));
                        ans=min(ans,(LL)x-x1+x-p[x][0]+y-p[x][0]+y-x2);
                    }
                }
                printf("%lld\n",ans+1);
                continue;
            }
            Matrix A=query(1,2,n-1,n-y+2,n-x);
//            printf("%d %d %d %d\n",A.t[0][0],A.t[0][1],A.t[1][0],A.t[1][1]);
            LL ans=INF;
            if(x1>y1){
                if(x2>y2){
                    ans=min(ans,abs(y1-p[x][0])+abs(y2-p[y-1][0])+A.t[0][0]);
                    ans=min(ans,abs(y1-p[x][0])+y-p[y-1][1]+y-y2+A.t[1][0]);
                    ans=min(ans,x-y1+x-p[x][1]+abs(y2-p[y-1][0])+A.t[0][1]);
                    ans=min(ans,x-y1+x-p[x][1]+y-p[y-1][1]+y-y2+A.t[1][1]);
                }
                else {
                    ans=min(ans,abs(y1-p[x][0])+abs(x2-p[y-1][1])+A.t[1][0]);
                    ans=min(ans,abs(y1-p[x][0])+y-p[y-1][0]+y-x2+A.t[0][0]);
                    ans=min(ans,x-y1+x-p[x][1]+abs(x2-p[y-1][1])+A.t[1][1]);
                    ans=min(ans,x-y1+x-p[x][1]+y-p[y-1][0]+y-x2+A.t[0][1]);
                }
            }
            else {
                if(x2>y2){
                    ans=min(ans,abs(x1-p[x][1])+abs(y2-p[y-1][0])+A.t[0][1]);
                    ans=min(ans,abs(x1-p[x][1])+y-p[y-1][1]+y-y2+A.t[1][1]);
                    ans=min(ans,x-x1+x-p[x][0]+abs(y2-p[y-1][0])+A.t[0][0]);
                    ans=min(ans,x-x1+x-p[x][0]+y-p[y-1][1]+y-y2+A.t[1][0]);
                }
                else {
                    ans=min(ans,abs(x1-p[x][1])+abs(x2-p[y-1][1])+A.t[1][1]);
                    ans=min(ans,abs(x1-p[x][1])+y-p[y-1][0]+y-x2+A.t[0][1]);
                    ans=min(ans,x-x1+x-p[x][0]+abs(x2-p[y-1][1])+A.t[1][0]);
                    ans=min(ans,x-x1+x-p[x][0]+y-p[y-1][0]+y-x2+A.t[0][0]);
                }
            }
            printf("%lld\n",ans+y-x);
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