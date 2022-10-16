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
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=4e5+3,mxm=mxn*20;
int n;char s[mxn];
int len[mxn],fa[mxn],ts[mxn][26],tt,lst,px[mxn],po[mxn];
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
inline bool cmp1(int x,int y){return len[x]<len[y];}
int rt[mxm],dc;
#define mid ((l+r)>>1)
struct asfd{
    int ls[mxm],rs[mxm];
    inline void ins(int &x,int p,int l=1,int r=n){
        x=++dc;if(l==r)return;if(p<=mid)ins(ls[x],p,l,mid);else ins(rs[x],p,mid+1,r);
    }
    inline bool ask(int x,int lc,int rc,int l=1,int r=n){
        if(x==0)return 0;if(lc<=l&&r<=rc)return 1;
        if(lc<=mid&&ask(ls[x],lc,rc,l,mid))return 1;if(rc>mid&&ask(rs[x],lc,rc,mid+1,r))return 1;
        return 0;
    }
    inline void mer(int &x,int y,int l=1,int r=n){
        if(!y)return;if(!x)return x=y,void();
        ++dc,ls[dc]=ls[x],rs[dc]=rs[x],x=dc;
        mer(ls[x],ls[y],l,mid),mer(rs[x],rs[y],mid+1,r);
    }
    inline int num(int x,int l=1,int r=n){if(!x)return 0;if(l==r)return 1;return num(ls[x],l,mid)+num(rs[x],mid+1,r);}
}sg;
#undef mid
int dp[mxn];
vector<int>g[mxn];
int da[mxn];
inline void dfs(int x,int d=0){
    da[d]=x;
    if(d){
        int l=0,r=d-1,mid,t=po[x];
        while(l<r){
            mid=(l+r+1)>>1;
            int y=da[mid];
            if(sg.ask(rt[y],t-len[x]+len[y],t-1))l=mid;else r=mid-1;
        }
        dp[x]=dp[da[l]]+1;
    }
    for(int i=0;i<g[x].size();++i)dfs(g[x][i],d+1);
}
int main(){
    tt=lst=1;scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;++i)ext(s[i]-'a'),sg.ins(rt[lst],i),po[lst]=i;
    for(int i=1;i<=tt;++i)px[i]=i;sort(px+1,px+tt+1,cmp1);
    for(int i=tt,x;i>1;--i)x=px[i],sg.mer(rt[fa[x]],rt[x]),po[fa[x]]=po[x];
    
    for(int i=2;i<=tt;++i)g[fa[i]].push_back(i);
    
    dfs(1);
    int ans=0;for(int i=2;i<=tt;++i)ans=max(ans,dp[i]);printf("%d\n",ans);
    for(int i=2;i<=tt;++i)assert(dp[i]>=dp[fa[i]]);
    return 0;
}