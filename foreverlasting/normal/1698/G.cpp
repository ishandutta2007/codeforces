//2022.6.29 by ljz
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
const int kcz=998244353;
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

//2022.6.29 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int HashMod=100007;
namespace MAIN{
    int n;
    char str[50];
    struct HashTable{
        struct Line{
            LL u,v;
            int next;
        }e[10000000];
        int h[HashMod],cnt;
        inline void Add(const LL &u,const LL &v,const LL &w){
            e[++cnt]={w,v,h[u]},h[u]=cnt;
        }
        inline void Hash(const LL &x,const LL &k){
            Add(x%HashMod,k,x);
        }
        inline LL Query(const LL &x){
            LL s=x%HashMod;
            for(res i=h[s];i;i=e[i].next)if(e[i].u==x)return e[i].v;
            return -1;
        }
    }Hash;
    inline LL bsgs(const LL &p){
        res m=(int)sqrtl(p),u=63-__builtin_clzll(p);
        LL t=1;
        for(res i=1;i<=m;i++){
            t<<=1;
            if(t>>u&1)t^=p;
            if(t==1)return i;
            Hash.Hash(t,i);
        }
        LL tt=t;
        for(res i=2;i<=2*m;i++){
            LL ret=0,x=tt;
            for(res j=0;j<u;j++){
                if(t>>j&1)ret^=x;
                x<<=1;
                if(x>>u&1)x^=p;
            }
            t=ret;
            LL k=Hash.Query(t);
            if(k!=-1)return (LL)i*m-k;
        }
    }
    inline void MAIN(const res &Case){
        scanf("%s",str+1);
        n=(int)strlen(str+1);
        LL P=0;
        res m=0,s=0;
        while(str[n]=='0'&&n>=1)n--;
        if(n==0){puts("-1");return;}
        for(res i=1;i<=n;i++){
            if(str[i]=='1'){m=i;break;}
        }
        for(res i=1;i<=n;i++)s+=str[i]=='1';
        if(s==1){
            printf("%d %d\n",m,m+1);
            return;
        }
        for(res i=m;i<=n;i++)P|=((LL)str[i]-'0')<<(i-m);
        LL op=bsgs(P);
        if(op==-1)puts("-1");
        else printf("%lld %lld\n",m,m+op);
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