//2019.10.12 by ljz
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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
const int kcz=1000000007;
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
}
inline int Add(const res &x,const res &y){
    return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
}
inline int mul(const res &x,const res &y){
    if(!x||!y)return 0;
    return int(1LL*x*y%kcz);
}
inline int sqr(const res &x){
    return mul(x,x);
}
inline int mul(const res &x,const res &y,const res &d){
    return int(1LL*x*y/d%kcz);
}
inline int qpow(res x,RG LL y){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
inline LL Qpow(RG LL x,res y){
    RG LL ret=1;
    while(y){
        if(y&1)ret*=x;
        x*=x,y>>=1;
    }
    return ret;
}
const int N=102;
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
namespace MAIN{
    int R,a[4],s,n;
    int id[N][N],idx;
    int Fi[N];
    int coef[N][N*N];
    int p[N][N],poly[N],nw;
    int ans[N];
    inline void MAIN(){
        R=read(),n=R<<1|1;
        for(res i=0;i<4;i++)s+=(a[i]=read());
        s=qpow(s,kcz-2);
        for(res i=0;i<4;i++)a[i]=mul(a[i],s);
        res INV=qpow(a[3],kcz-2);
        memset(id,-1,sizeof(id)),memset(Fi,-1,sizeof(Fi));
        for(res i=0;i<n;i++)for(res j=0;j<n;j++)if((i-R)*(i-R)+(j-R)*(j-R)<=R*R)id[i+1][j+1]=++idx;
        for(res i=1;i<=n;i++)for(res j=1;j<=n;j++)if(id[i][j]>0){Fi[i]=j;break;}
//        for(res i=1;i<=n;i++)printf("%d\n",Fi[i]);
//        for(res i=1;i<=n;i++)for(res j=1;j<=n;j++)printf("%d %d %d\n",i,j,id[i][j]);
        for(res i=1;i<=n;i++)coef[i][id[i][Fi[i]]]=1;
        for(res j=1;j<=n;j++){
            for(res i=1;i<=n;i++){
                if(id[i][j]==-1)continue;
                for(res k=0;k<=n;k++)poly[k]=coef[k][id[i][j]];
                add(poly[0],kcz-1);
                for(res l=0;l<3;l++){
                    res ni=i+dx[l],nj=j+dy[l];
                    if(id[ni][nj]==-1)continue;
                    for(res k=0;k<=n;k++)add(poly[k],kcz-mul(a[l],coef[k][id[ni][nj]]));
                }
                if(id[i][j+1]==-1){
                    poly[0]=Add(0,kcz-poly[0]),nw++;
                    for(res k=0;k<=n;k++)p[nw][k]=poly[k];
//                    break;
                }
                else for(res k=0;k<=n;k++)coef[k][id[i][j+1]]=mul(poly[k],INV);
            }
        }
//        for(res i=1;i<=idx;i++){
//            for(res j=0;j<=n;j++)
//                printf("%d ",coef[j][i]);
//            puts("");
//        }
//        for(res i=1;i<=n;i++){
//            for(res j=0;j<=n;j++)
//                printf("%d ",p[i][j]);
//            puts("");
//        }
        for(res i=1;i<=n;i++){
            res j=i;
            while(j<=n&&!p[j][i])j++;
            if(i!=j)swap(p[i],p[j]);
            res inv=qpow(p[i][i],kcz-2);
            for(j=i+1;j<=n;j++)
                if(p[j][i]){
//                    puts("OK");
                    res I=mul(p[j][i],inv);
                    for(res k=0;k<=n;k++)add(p[j][k],kcz-mul(p[i][k],I));
                }
        }
//        for(res i=1;i<=n;i++){
//            for(res j=0;j<=n;j++)
//                printf("%d ",p[i][j]);
//            puts("");
//        }
        for(res i=n;i;i--){
            ans[i]=p[i][0];
            for(res j=i+1;j<=n;j++)add(ans[i],kcz-mul(ans[j],p[i][j]));
            ans[i]=mul(ans[i],qpow(p[i][i],kcz-2));
        }
        ans[0]=1;
        res I=id[R+1][R+1],Ans=0;
        for(res i=0;i<=n;i++)add(Ans,mul(ans[i],coef[i][I]));
        printf("%d\n",Ans);
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