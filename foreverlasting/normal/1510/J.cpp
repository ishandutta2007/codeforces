//2021.10.2 by ljz
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
#define res register int
#define LL long long
#define Inf 0x3f3f3f3f
#define sup 0x7fffffff
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
//#define unl __int128
#define eps 1e-5
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
//#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
//#define poly vector<int>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define lowbit(x) (x&-x)
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
    res s=0,ch=gc(),laz=1;
    while(ch<'0'||ch>'9'){if(ch=='-')laz=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*laz;
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
//    res ch=gc(),laz=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')laz=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*laz;
//}
//inline void write(RG unl x){
//    if(x>10)write(x/10);
//    putchar(int(x%10)+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
const int kcz=998244353;
const int G=3,GI=332748118;
//inline void add(res &x,const res &y){
//    x+=y,x>=kcz?x-=kcz:1;
//}
//inline int Add(const res &x,const res &y){
//    return x+y>=kcz?x+y-kcz:x+y;
//}
inline int mul(const res &x,const res &y){
    return int(1ll*x*y%kcz);
}
#define add(x,y) (x+=y,x>=kcz?x-=kcz:1)
#define Add(x,y) (x+y>=kcz?x+y-kcz:x+y)
//#define mul(x,y) int(1ll*x*y%kcz)
#define Mul(x,y,d) int((ull)x*y/d%kcz)
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
//mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2021.10.2 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=5e5+10;
namespace MAIN{
    char str[N];
    int a[N],ax;
    int bx,cx;
    int len[N],lenx;
    int fl;
    int Fl;
    inline void MAIN(){
        scanf("%s",str+1);
        res n=int(strlen(str+1));
        res FL=0;
        for(res i=1;i<=n;i++)FL|=str[i]=='#';
        if(!FL){puts("0");return;}
        for(res i=1;i<=n;i++){
            if(str[i]=='_'){
                res j=i;
                while(str[j]=='_'&&j<=n)j++;
                if(i==1)bx=j-i;
                if(j==n+1)cx=j-i;
                if(i!=1&&j!=n+1)fl|=((j-i)&1),Fl|=(j-i)==4,a[++ax]=j-i;
                i=j-1;
            }
        }
        sort(a+1,a+ax+1);
        if(str[1]=='#'){
            if(a[ax]>=2||str[n]!='#'){puts("-1");return;}
            for(res i=1;i<=n;i++){
                if(str[i]=='#'){
                    res j=i;
                    while(str[j]=='#'&&j<=n)j++;
                    len[++lenx]=j-i;
                    i=j-1;
                }
            }
            printf("%d\n",lenx);
            for(res i=1;i<=lenx;i++)printf("%d ",len[i]);
            puts("");
            return;
        }
        if(str[n]=='#'){
            if(a[ax]>=2||str[1]!='#'){puts("-1");return;}
            for(res i=1;i<=n;i++){
                if(str[i]=='#'){
                    res j=i;
                    while(str[j]=='#'&&j<=n)j++;
                    len[++lenx]=j-i;
                    i=j-1;
                }
            }
            printf("%d\n",lenx);
            for(res i=1;i<=lenx;i++)printf("%d ",len[i]);
            puts("");
            return;
        }
        if((cx&1)&&(bx&1)&&!fl){
            for(res i=1;i<=n;i++){
                if(str[i]=='_'){
                    res j=i+1;
                    while(str[j]=='#'&&j<=n)j++;
                    len[++lenx]=j-i;
                    i=j;
                }
            }
            printf("%d\n",lenx);
            for(res i=1;i<=lenx;i++)printf("%d ",len[i]);
            puts("");
            return;
        }
        if((!ax||2<=a[1]-1)&&!Fl&&(cx-2>=2||cx==2)&&(2<=bx-2||bx==2)){
            for(res i=1;i<=n;i++){
                res j=i;
                while(str[j]=='#'&&j<=n)j++;
                i=j;
                while(str[j]=='_'&&j<=n)j++;
                if(i==1){
                    if((j-i)&1){
                        str[1]=str[2]='#';
                        for(res k=1;k<=(j-i-5)/2;k++)str[2+2*k]='#';
                        str[j-1]=str[j-2]='#';
                    }
                    else {
                        if((j-i)==2)str[1]=str[2]='#';
                        else {
                            for(res k=1;k<=(j-i-2)/2;k++)str[k*2-1]='#';
                            str[j-2]=str[j-1]='#';
                        }
                    }
                    i=j;
                }
                else if(j==n+1){
                    if((j-i)&1){
                        str[i+1]=str[i+2]='#';
                        for(res k=1;k<=(j-i-5)/2;k++)str[i+2*k+2]='#';
                    }
                    else {
                        if((j-i)==2);
                        else for(res k=1;k<=(j-i-2)/2;k++)str[i+k*2-1]='#';
                    }
                    i=j;
                }
                else {
                    if((j-i)&1){
                        if((j-i)==3)str[i+1]=str[i+2]='#';
                        else {
                            for(res k=1;k<=(j-i-3)/2;k++)str[i+2*k-1]='#';
                            str[j-1]=str[j-2]='#';
                        }
                    }
                    else {
                        str[i+1]=str[i+2]='#';
                        for(res k=1;k<=(j-i-6)/2;k++)str[i+2*k+2]='#';
                        str[j-2]=str[j-1]='#';
                    }
                    i=j;
                }
            }
            for(res i=1;i<=n;i++){
                res j=i;
                while(str[j]=='_'&&j<=n)j++;
                i=j;
                if(j>n)break;
                while(str[j]=='#'&&j<=n)j++;
                len[++lenx]=j-i;
                i=j;
            }
            printf("%d\n",lenx);
            for(res i=1;i<=lenx;i++)printf("%d ",len[i]);
            return;
        }
        Fl=1;
        for(res i=1;i<=ax;i++)Fl&=(4==a[i]||4<=a[i]-2);
        Fl&=(3==cx||3<=cx-2);
        Fl&=(3==bx||3<=bx-2);
        if(!Fl)puts("-1");
        else {
            str[0]=str[n+1]='_',str[n+2]='#';
            res rem=1,l=0;
            for(res i=1;i<=n+2;i++)
                if(str[i]=='#'){
                    if(rem){
                        for(;;)
                            if(4==rem||4<=rem-2){
                                len[++lenx]=l;
                                if(rem==4)break;
                                rem-=2,l+=2;
                            }
                            else rem--,l++;
                    }
                    rem=0,l=i+1;
                }
                else rem++;
            printf("%d\n",lenx-1);
            for(res i=2;i<=lenx;i++)printf("%d ",len[i]-len[i-1]-1);
        }
    }
}
int main(){
//    srand(19260817);
//    freopen("data.in","r",stdin);
//    freopen("1.out","w",stdout);
    MAIN::MAIN();
//    Ot();
    return 0;
}