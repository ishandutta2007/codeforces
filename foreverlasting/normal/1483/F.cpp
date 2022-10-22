//2022.3.17 by ljz
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
//inline int gc() {
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
//inline void write(RG __int128 x){
//    if(x>10)write(x/10);
//    putchar(int(x%10)+'0');
//}
const int kcz=998244353;
//const int G=3,GI=332748118;
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
#define mul(x,y) (int)((LL)(x)*(y)%kcz)
#define Mul(x,y,d) (int)((ull)(x)*(y)/(d)%kcz)
inline int qpow(res x,res y=kcz-2){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
//inline int qpow(res x,res y,const res &ljc){
//    res ret=1;
//    while(y){
//        if(y&1)ret=(int)(1ll*ret*x%ljc);
//        x=(int)(1ll*x*x%ljc),y>>=1;
//    }
//    return ret;
//}
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2022.3.17 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=1e6+10;
namespace MAIN{
    int n;
    int tr[N][26],fail[N],tot,end[N],pos[N];
    inline int insert(const string &s){
        res now=0;
        for(auto x:s){
            res c=x-'a';
            if(!tr[now][c])tr[now][c]=++tot;
            now=tr[now][c];
        }
        return now;
    }
    int Q[N],he,ta;
    inline void get_fail(){
        he=1;
        for(res i=0;i<26;i++)if(tr[0][i])Q[++ta]=tr[0][i];
        while(he<=ta){
            res u=Q[he++];
            for(res i=0;i<26;i++)
                if(tr[u][i])fail[tr[u][i]]=tr[fail[u]][i],Q[++ta]=tr[u][i];
                else tr[u][i]=tr[fail[u]][i];
        }
    }
    string s[N];
    vector<int> G[N];
    int dfn[N],low[N],idx;
    struct BIT{
        int tr[N];
        inline void modify(const res &x,const res &y){
            for(res i=x;i<=tot+1;i+=lowbit(i))tr[i]+=y;
        }
        inline int query(const res &x){
            res ret=0;
            for(res i=x;i;i-=lowbit(i))ret+=tr[i];
            return ret;
        }
        inline int query(const res &l,const res &r){
            return query(r)-query(l-1);
        }
    }T;
    void dfs(res x){
        dfn[x]=++idx;
        if(!end[x])end[x]=end[fail[x]];
        for(auto tox:G[x])dfs(tox);
        low[x]=idx;
    }
    int cnt[N],vis[N],ans;
    inline void MAIN(const res &Case){
        n=read();
        for(res i=1;i<=n;i++)cin>>s[i],end[pos[i]=insert(s[i])]=i;
        get_fail();
        for(res i=1;i<=tot;i++)G[fail[i]].pb(i);
        dfs(0);
        for(res i=1;i<=n;i++){
            res now=0,L=(int)s[i].size();
            vector<int> A;
            for(auto x:s[i])now=tr[now][x-'a'],T.modify(dfn[now],1),A.pb(end[now]);
            A.back()=end[fail[now]];
            for(res j=-1+(int)s[i].size();~j;j--){
                res x=A[j];
                if(x){
                    res l=j+1-(int)s[x].size();
                    if(L<=l)vis[x]=1;
                    else L=l,cnt[x]++;
                }
            }
            for(auto x:A)if(x&&!vis[x])vis[x]=1,ans+=cnt[x]==T.query(dfn[pos[x]],low[pos[x]]);
            for(auto x:A)cnt[x]=vis[x]=0;
            now=0;
            for(auto x:s[i])now=tr[now][x-'a'],T.modify(dfn[now],-1);
        }
        printf("%d\n",ans);
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