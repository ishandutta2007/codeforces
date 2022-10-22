//2021.12.8 by ljz
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
typedef pair<int,int> Pair;
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
//inline int gc() {
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
//#define Mul(x,y,d) int((ull)(x)*(y)/(d)%kcz)
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
//2021.12.8 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
namespace MAIN{
    char str[30];
    int vis[26];
    int id1,id2;
    char p[4],q[8],a[5][15],b[5][15];
    int fl[4];
    inline void MAIN(){
        str[0]='!',str[28]='!';
        scanf("%s",str+1);
        res n=int(strlen(str+1));
        for(res i=1;i<=n;i++){
            if(!vis[str[i]-'A'])vis[str[i]-'A']=i;
            else {
                id1=i,id2=vis[str[i]-'A'];break;
            }
        }
        for(res i=1;i<=n;i++){
            if(i==id1)p[0]=str[i-1],p[1]=str[i+1];
            if(i==id2)p[2]=str[i-1],p[3]=str[i+1];
        }
        if(abs(id1-id2)==1){puts("Impossible");return;}
        res now=1,ni,nj;
        for(res j=1;j<=13;j++){
            if(now==id2)now++;
            if(now==id1)ni=1,nj=j;
            a[1][j]=str[now],now++;
        }
        for(res j=13;j;j--){
            if(now==id2)now++;
            if(now==id1)ni=2,nj=j;
            a[2][j]=str[now],now++;
        }
        for(res T=1;T<=26;T++){
            q[0]=a[ni][nj-1],q[1]=a[ni][nj+1],q[2]=a[ni-1][nj],q[3]=a[ni+1][nj];
            q[4]=a[ni-1][nj-1],q[5]=a[ni-1][nj+1],q[6]=a[ni+1][nj-1],q[7]=a[ni+1][nj+1];
            fl[0]=fl[1]=fl[2]=fl[3]=0;
            for(res k=0;k<4;k++){
                for(res i=0;i<8;i++){
                    if(q[i]==p[k]||p[k]=='!')fl[k]=1;
                }
            }
            if(fl[0]==1&&fl[1]==1&&fl[2]==1&&fl[3]==1){
                for(res i=1;i<=2;i++){
                    for(res j=1;j<=13;j++)putchar(a[i][j]);
                    puts("");
                }
                return;
            }
            if(nj<13&&ni==1)nj++;
            else if(ni==1&&nj==13)ni=2;
            else if(ni==2&&nj==1)ni=1;
            else nj--;
            for(res j=1;j<13;j++)b[1][j+1]=a[1][j];
            b[2][13]=a[1][13];
            for(res j=2;j<=13;j++)b[2][j-1]=a[2][j];
            b[1][1]=a[2][1];
            for(res i=1;i<=2;i++)for(res j=1;j<=13;j++)a[i][j]=b[i][j];
        }
        now=1;
        for(res j=1;j<=13;j++){
            if(now==id1)now++;
            if(now==id2)ni=1,nj=j;
            a[1][j]=str[now],now++;
        }
        for(res j=13;j;j--){
            if(now==id1)now++;
            if(now==id2)ni=2,nj=j;
            a[2][j]=str[now],now++;
        }
        for(res T=1;T<=26;T++){
            q[0]=a[ni][nj-1],q[1]=a[ni][nj+1],q[2]=a[ni-1][nj],q[3]=a[ni+1][nj];
            q[4]=a[ni-1][nj-1],q[5]=a[ni-1][nj+1],q[6]=a[ni+1][nj-1],q[7]=a[ni+1][nj+1];
            fl[0]=fl[1]=fl[2]=fl[3]=0;
            for(res k=0;k<4;k++){
                for(res i=0;i<8;i++){
                    if(q[i]==p[k]||p[k]=='!')fl[k]=1;
                }
            }
            if(fl[0]==1&&fl[1]==1&&fl[2]==1&&fl[3]==1){
                for(res i=1;i<=2;i++){
                    for(res j=1;j<=13;j++)putchar(a[i][j]);
                    puts("");
                }
                return;
            }
            if(nj<13&&ni==1)nj++;
            else if(ni==1&&nj==13)ni=2;
            else if(ni==2&&nj==1)ni=1;
            else nj--;
            for(res j=1;j<13;j++)b[1][j+1]=a[1][j];
            b[2][13]=a[1][13];
            for(res j=2;j<=13;j++)b[2][j-1]=a[2][j];
            b[1][1]=a[2][1];
            for(res i=1;i<=2;i++)for(res j=1;j<=13;j++)a[i][j]=b[i][j];
        }
        puts("Impossible");
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