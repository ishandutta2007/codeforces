//2021.12.20 by ljz
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
const int kcz=998244353;
const int G=3,GI=332748118;
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:1;
}
inline int Add(const res &x,const res &y){
    return x+y>=kcz?x+y-kcz:x+y;
}
//inline int mul(const res &x,const res &y){
//    return int(1ll*x*y%kcz);
//}
//#define add(x,y) ((x)+=(y)-kcz,(x)+=(x)>>31&kcz)
//#define Add(x,y) (((x)+(y)-kcz)>>31&kcz)
#define mul(x,y) int((LL)(x)*(y)%kcz)
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
//2021.12.20 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=4e5+10;
namespace MAIN{
    int sit[N],sitr[N];
    int pos[N];
    char str[N];
    Pair chain[N],Chain[N];
    int cx;
    namespace Tr{
        vector<pair<int,int> > G[N];
        int sz[N],son[N],dep[N],fa[N],ch[N];
        void dfs(res x,res fax,res depx){
            sz[x]=1,fa[x]=fax,dep[x]=depx;
            for(auto [tox,c]:G[x]){
                if(tox==fax)continue;
                dfs(tox,x,depx+1),ch[tox]=c,sz[x]+=sz[tox];
                if(sz[tox]>sz[son[x]])son[x]=tox;
            }
        }
        int top[N],dfn[N],idx,pos[N];
        void dfs(res x,res topx){
            top[pos[dfn[x]=++idx]=x]=topx;
            if(son[x])dfs(son[x],topx);
            for(auto [tox,c]:G[x]){
                if(tox==fa[x]||tox==son[x])continue;
                dfs(tox,tox);
            }
        }
        inline void gchain(res u,res v){
            res A=0,B=0;
            while(top[u]!=top[v]){
                if(dep[top[u]]>dep[top[v]])chain[++A]=mp(sitr[u],sitr[top[u]]),u=fa[top[u]];
                else Chain[++B]=mp(sit[top[v]],sit[v]),v=fa[top[v]];
            }
            if(dep[u]<dep[v])chain[++A]=mp(sit[u]+1,sit[v]);
            if(dep[u]>dep[v])chain[++A]=mp(sitr[u],sitr[v]-1);
            for(res i=B;i>=1;i--)chain[++A]=Chain[i];
            cx=A;
        }
    }
    namespace SA{
        int str[N];
        int rnk[N],buc[N],sa[N],hei[N],fr[N],sc[N],n,m;
        inline void get_SA(){
            m=10000;
            for(res i=1;i<=n;i++)buc[fr[i]=str[i]]++;
            for(res i=2;i<=m;i++)buc[i]+=buc[i-1];
            for(res i=n;i;i--)sa[buc[fr[i]]--]=i;
            for(res k=1;k<=n;k<<=1){
                res num=0;
                for(res i=n-k+1;i<=n;i++)sc[++num]=i;
                for(res i=1;i<=n;i++)if(sa[i]>k)sc[++num]=sa[i]-k;
                memset(buc,0,sizeof(buc));
                for(res i=1;i<=n;i++)buc[fr[i]]++;
                for(res i=2;i<=m;i++)buc[i]+=buc[i-1];
                for(res i=n;i;i--)sa[buc[fr[sc[i]]]--]=sc[i],sc[i]=0;
                swap(fr,sc);
                fr[sa[1]]=1;
                num=1;
                for(res i=2;i<=n;i++)fr[sa[i]]=(sc[sa[i]]==sc[sa[i-1]]&&sc[sa[i]+k]==sc[sa[i-1]+k])?num:++num;
                if(num==n)break;
                m=num;
            }
        }
        inline void get_hei(){
            res k=0;
            rnk[sa[1]]=1;
            for(res i=2;i<=n;i++)rnk[sa[i]]=rnk[sa[i-1]]+(fr[sa[i]]!=fr[sa[i-1]]||sc[sa[i]]!=sc[sa[i-1]]);
            for(res i=1;i<=n;i++){
                if(rnk[i]==1)continue;
                if(k)k--;
                res j=sa[rnk[i]-1];
                while(j+k<=n&&i+k<=n&&str[i+k]==str[j+k])k++;
                hei[rnk[i]]=k;
            }
        }
        int st[N][21];
        inline void PRE(){
            for(res i=1;i<=n;i++)st[i][0]=hei[i];
            for(res j=1;j<=20;j++)for(res i=1;i+(1<<j)-1<=n;i++)st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
        int Lg[N];
        inline int query_min(res l,res r){
            res k=Lg[r-l];
            return min(st[l][k],st[r-(1<<k)+1][k]);
        }
        inline int LCP(const res &l,const res &r){
            if(l==r)return n-l+1;
            res x=rnk[l],y=rnk[r];
            if(x>y)swap(x,y);
            return query_min(x+1,y);
        }
        inline void pre(){
            for(res i=2;i<=n;i++)Lg[i]=Lg[i>>1]+1;
            str[n+1]=26,get_SA(),get_hei(),PRE();
        }
        inline bool small(res p){
            p=sa[p];
            for(res i=1;i<=cx;i++){
                res s=n-p,t=chain[i].se-chain[i].fi+1,_=min({s,t,LCP(p,chain[i].fi)});
                if(_!=min(s,t))return str[p+_]<str[chain[i].fi+_];
                if(_==s&&_==t)return i!=cx;
                if(_<t)return 1;
                p+=t;
            }
            return 0;
        }
        inline bool match(res p){
            p=sa[p];
            for(res i=1;i<=cx;i++){
//                printf("%d\n",p);
                res s=n-p,t=chain[i].se-chain[i].fi+1,_=min({s,t,LCP(p,chain[i].fi)});
                if(_<t)return 0;
                if(_==s)return i==cx;
                p+=t;
            }
            return 1;
        }
        inline int gpos(){
            res l=1,r=n,ret=0;
            while(l<=r){
                res mid=(l+r)>>1;
                if(small(mid))l=mid+1,ret=mid;
                else r=mid-1;
            }
            return ret;
        }
        inline int findl(res r){
            res l=1,ret=r+1;
            while(l<=r){
                res mid=(l+r)>>1;
                if(match(mid))r=mid-1,ret=mid;
                else l=mid+1;
            }
            return ret;
        }
        inline int findr(res l){
            res r=n,ret=l-1;
            while(l<=r){
                res mid=(l+r)>>1;
                if(match(mid))l=mid+1,ret=mid;
                else r=mid-1;
            }
            return ret;
        }
    }
    vector<int> Q[N];
    int n,m,q;
    int tr[N];
    inline void modify(const res &x,const res &y){
        for(res i=x;i<=SA::n;i+=lowbit(i))tr[i]+=y;
    }
    inline int query(const res &x){
        res ret=0;
        for(res i=x;i;i-=lowbit(i))ret+=tr[i];
        return ret;
    }
    int ans[N];
    Pair que[N];
    inline void MAIN(){
        n=read(),m=read(),q=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            char sss[5];
            scanf("%s",sss+1);
            Tr::G[u].emplace_back(mp(v,sss[1])),Tr::G[v].emplace_back(mp(u,sss[1]));
        }
        for(res i=1;i<=m;i++){
            scanf("%s",str+1);
            res t=int(strlen(str+1));
            for(res j=1;j<=t;j++)SA::n++,SA::str[SA::n]=str[j],pos[SA::n]=i;
            SA::str[++SA::n]='z'+1;
        }
        Tr::dfs(1,0,1),Tr::dfs(1,1),Tr::ch[1]='a'-1;
        for(res i=1;i<=Tr::idx;i++){
            res p=Tr::pos[i];
            SA::n++,sit[p]=SA::n,SA::str[SA::n]=Tr::ch[p];
        }
        for(res i=Tr::idx;i>=1;i--){
            res p=Tr::pos[i];
            SA::n++,sitr[p]=SA::n,SA::str[SA::n]=Tr::ch[p];
        }
        SA::pre();
//        for(res i=1;i<=SA::n;i++)printf("%c",SA::str[i]);puts("");
//        for(res i=1;i<=SA::n;i++)printf("%d\n",SA::sa[i]);
        for(res T=1;T<=q;T++){
            res u=read(),v=read(),L=read(),R=read();
            Tr::gchain(u,v),que[T]=mp(L,R);
//            for(res i=1;i<=cx;i++)printf("%d %d\n",chain[i].fi,chain[i].se);puts("------");
            res x=SA::gpos();
            res l=SA::findl(x),r=SA::findr(x+1);
//            printf("%d %d %d\n",l,r,x);
            if(l<=r)Q[l-1].pb(-T),Q[r].pb(T);
        }
        for(res i=1;i<=SA::n;i++){
            res p=SA::sa[i];
            if(pos[p])modify(pos[p],1);
            for(auto x:Q[i])ans[abs(x)]+=(x>0?1:-1)*(query(que[abs(x)].se)-query(que[abs(x)].fi-1));
        }
        for(res i=1;i<=q;i++)printf("%d\n",ans[i]);
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