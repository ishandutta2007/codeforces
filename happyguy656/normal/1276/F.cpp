#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int> pii;
typedef set<int>::iterator SP;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3,mxm=mxn*20;
int n;char s[mxn];
ll ans=2;
int to[mxn],nxt[mxn],fir[mxn],gn;
int dfn[mxn],dfa[mxn],dt,top[mxn],zs[mxn],siz[mxn],dep[mxn];
inline void gadd(int x,int y){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn;}
vector<int>ga[mxn];
struct asdagw{
    inline void ext(int c){
        int p=lst,np=++tt,q,nq;len[np]=len[p]+1,lst=np;
        for(;p&&!ts[p][c];p=fa[p])ts[p][c]=np;
        if(!p)fa[np]=1;else{
            q=ts[p][c];if(len[q]==len[p]+1)fa[np]=q;else{
                nq=++tt,len[nq]=len[p]+1,fa[nq]=fa[q],memcpy(ts[nq],ts[q],sizeof(ts[q]));
                fa[q]=fa[np]=nq;
                for(;ts[p][c]==q;p=fa[p])ts[p][c]=nq;
            }
        }
    }
    int len[mxn],tt,lst,fa[mxn],ts[mxn][26],po[mxn];
    inline void b1(){
        tt=lst=1;
        for(int i=1;i<n;++i)ext(s[i]-'a'),po[i]=lst;
        for(int i=2;i<=tt;++i)ans+=len[i]-len[fa[i]];
        ext(s[n]-'a');for(int i=2;i<=tt;++i)ans+=len[i]-len[fa[i]];
        for(int i=2;i<=tt;++i)ga[fa[i]].push_back(i);
    }
    inline void b2(){
        tt=lst=1;
        for(int i=n;i>1;--i)ext(s[i]-'a'),po[i]=lst;
        for(int i=2;i<=tt;++i)ans+=len[i]-len[fa[i]],gadd(fa[i],i);
    }
}G,H;

inline void dfs0(int x){
    siz[x]=1;
    forg(i,x){
        dep[to[i]]=dep[x]+1,dfs0(to[i]);siz[x]+=siz[to[i]];
        if(siz[to[i]]>siz[zs[x]])zs[x]=to[i];
    }
}
inline void dfs1(int x){
    int f=H.fa[x];dfn[x]=++dt,dfa[dt]=x;
    top[x]=x==zs[f]?top[f]:x;
    if(zs[x])dfs1(zs[x]);forg(i,x)if(to[i]!=zs[x])dfs1(to[i]);
}

inline int lca(int x,int y){while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])swap(x,y); x=H.fa[top[x]];}return dep[x]<dep[y]?x:y;}
inline int llca(int x,int y){if(!x||!y)return 0;assert(x&&y);return H.len[lca(dfa[x],dfa[y])];}
ll h1[mxn],h2[mxn];
set<int>hh[mxn];
inline void mer(int x,int y){
    h1[x]+=h1[y];
    if(hh[x].size()<hh[y].size())swap(hh[x],hh[y]),swap(h2[x],h2[y]);
    for(auto i:hh[y]){
        if(hh[x].size()){
            assert(hh[x].find(i)==hh[x].end());
            SP p=hh[x].lower_bound(i);
            int n1=p==hh[x].end()?0:*p;
            int n2=p==hh[x].begin()?0:*--p;
            h2[x]+=llca(n1,i)+llca(n2,i)-llca(n1,n2);
        }else assert(0);
        hh[x].insert(i);
    }
}
inline void dfs(int x){
    for(auto y:ga[x])dfs(y),mer(x,y);
    ans+=(G.len[x]-G.len[G.fa[x]])*(h1[x]-h2[x]);
}
int main(){
    scanf("%s",s+1),n=strlen(s+1);
    G.b1(),H.b2();
    dfs0(1),dfs1(1);
    for(int i=1;i<=n-2;++i){
        int x=G.po[i],y=H.po[i+2];
        h1[x]=H.len[y];
        hh[x].insert(dfn[y]);
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}