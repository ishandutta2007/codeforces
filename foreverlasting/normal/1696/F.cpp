//2022.6.25 by ljz
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

//2022.6.25 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=100+10;
namespace MAIN{
    int n;
    int d[N][N][N];
    char str[N];
    int vis[N];
    vector<int> G[N];
    int fa[N];
    void solve(res x,res fax){
        vector<int> A;
        for(res i=2;i<=n;i++){
            if(d[i][fax][x]&&!vis[i])A.pb(i),vis[i]=1,G[x].pb(i),G[i].pb(x),fa[i]=x;
        }
        for(auto y:A)solve(y,x);
    }
    int dis[N][N];
    void dfs(res x,res fax,res rt){
        for(auto tox:G[x]){
            if(tox==fax)continue;
            dis[rt][tox]=dis[rt][x]+1;
            dfs(tox,x,rt);
        }
    }
    inline void MAIN(const res &Case){
        n=read();
        for(res i=1;i<=n;i++)for(res j=1;j<=n;j++)for(res k=1;k<=n;k++)d[i][j][k]=0;
        for(res i=1;i<=n;i++){
            vis[i]=0,vector<int>().swap(G[i]);
            for(res j=1;j<=n-i;j++){
                scanf("%s",str+1);
                for(res k=1;k<=n;k++){
                    d[i][i+j][k]=d[i+j][i][k]=str[k]-'0';
                }
            }
        }
        for(res i=1;i<=n;i++)for(res j=1;j<=n;j++)d[i][i][j]=1;
//        res p=2;
//        while(233){
//            res fl=0;
//            for(res i=1;i<=n;i++){
//                if(d[p][1][i]==1){p++,fl=1;break;}
//            }
//            if(!fl)break;
//            if(p>n)break;
//        }
//        if(p>n){puts("No");return;}
//        vector<int> A;
//        for(res i=1;i<=n;i++){
//            if(d[p][i][1]==1)A.pb(i),vis[i]=1,G[1].pb(i);
//        }
//        A.pb(p),vis[p]=1,vis[1]=1,G[1].pb(p);
//        for(auto x:A)solve(x,1);
//        res s=0;
//        for(res i=1;i<=n;i++)s+=vis[i];
//        if(s!=n){puts("No");return;}
//        puts("Yes");
//        for(res x=1;x<=n;x++)for(auto tox:G[x])printf("%d %d\n",x,tox);
        for(res p=2;p<=n;p++){
            for(res x=1;x<=n;x++)vector<int>().swap(G[x]),fa[x]=vis[x]=0;
            vector<int> A;
            for(res i=2;i<=n;i++)if(d[i][p][1])vis[i]=1,A.pb(i),G[1].pb(i),G[i].pb(1),fa[i]=1;
            A.pb(p),vis[p]=1,vis[1]=1,G[1].pb(p),G[p].pb(1),fa[p]=1;
            for(auto x:A)solve(x,1);
            res s=0;
            for(res i=1;i<=n;i++)s+=vis[i];
            if(s!=n)continue;
            for(res i=1;i<=n;i++)dis[i][i]=0;
            for(res i=1;i<=n;i++)dfs(i,0,i);
            res fl=1;
            for(res i=1;i<=n;i++){
                if(!fl)break;
                for(res j=1;j<=n;j++){
                    if(!fl)break;
                    for(res k=1;k<=n;k++){
                        if((dis[i][k]==dis[j][k])!=(d[i][j][k])){fl=0;break;}
                    }
                }
            }
            if(fl){
                puts("Yes");
                for(res x=2;x<=n;x++)printf("%d %d\n",x,fa[x]);
                return;
            }
        }
        puts("No");
    }
}
int main(){
//    srand(time(0));
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    res Case=read();
    for(res T=1;T<=Case;T++)MAIN::MAIN(T);
//    Ot();
    return 0;
}