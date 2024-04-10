//2019.9.4 by ljz
#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
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
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
const int N=1e6+10;
namespace MAIN{
    int n,m;
    string str[N];
//    map<Pair,bool> vis,Vis;
    Pair Q[N<<1];
    int he,ta;
    vector<Pair> G[N<<1];
    int fl[N];
    inline void MAIN(){
        n=read(),m=read();
        for(res i=0;i<n;i++)cin>>str[i];
        Q[he=ta=1]=mp(1,1);
        if(str[0][0]=='#'||str[n-1][m-1]=='#'){puts("0");return;}
        while(he<=ta){
            RG Pair u=Q[he++];
            G[u.fi+u.se].pb(mp(u.fi,u.se));
            res ni=u.fi+1,nj=u.se;
            if(ni<=n&&str[ni-1][nj-1]=='.')if(!fl[(ni-1)*m+nj])fl[(ni-1)*m+nj]=1,Q[++ta]=mp(ni,nj);
            ni=u.fi,nj=u.se+1;
            if(nj<=m&&str[ni-1][nj-1]=='.')if(!fl[(ni-1)*m+nj])fl[(ni-1)*m+nj]=1,Q[++ta]=mp(ni,nj);
        }
        if(!fl[n*m]){puts("0");return;}
        memset(fl,0,sizeof(fl));
        Q[he=ta=1]=mp(n,m);
        while(he<=ta){
            RG Pair u=Q[he++];
            res ni=u.fi-1,nj=u.se;
            if(ni>=1&&str[ni-1][nj-1]=='.')if(!fl[(ni-1)*m+nj])fl[(ni-1)*m+nj]=1,Q[++ta]=mp(ni,nj);
            ni=u.fi,nj=u.se-1;
            if(nj>=1&&str[ni-1][nj-1]=='.')if(!fl[(ni-1)*m+nj])fl[(ni-1)*m+nj]=1,Q[++ta]=mp(ni,nj);
        }
        for(res i=3;i<n+m;i++){
            res cnt=0;
            for(auto x:G[i]){
                if(fl[(x.fi-1)*m+x.se])cnt++;
                if(cnt>=2)break;
            }
            if(cnt==1){puts("1");return;}
        }
        puts("2");
    }
}
int main(){
//    srand(19260817);
//    freopen("signin.in","r",stdin);
//    freopen("signin.out","w",stdout);
    MAIN::MAIN();
    return 0;
}