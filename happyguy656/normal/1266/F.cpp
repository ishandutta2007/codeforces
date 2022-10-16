#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,ll>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=5e5+3;
VI g[mxn],ve[mxn],ev[mxn],v0[mxn];int n,dg[mxn],ans,de[mxn],jg[mxn*2],cc[mxn],df1[mxn],df2[mxn],dfn[mxn],dn,fa[mxn];
void dfs0(int x,int f){ 
    de[x]=1;fa[x]=f;
    for(int y:g[x])if(y!=f)dfs0(y,x),de[x]=max(de[x],de[y]+1),v0[de[y]].push_back(x),ve[de[y]].push_back(y);
    df1[x]=dn;
    for(int y:g[x])if(y!=f)df2[x]=dfn[y]=++dn;
}
void dfs1(int x,int f=0,int e=0){
    int mx=e,xx=0,po=f;
    for(int y:g[x])if(y!=f){if(de[y]>=mx)po=y,xx=mx,mx=de[y];else xx=max(xx,de[y]);}
    for(int y:g[x])if(y!=f){int z=y==po?xx+1:mx+1;dfs1(y,x,z);ev[z].push_back(y);v0[z].push_back(y);}
}
#define mid ((l+r)>>1)
struct seee{
    int mx[mxn*4],tg[mxn*4];
    void add(int lc,int rc,int x=1,int l=1,int r=n){
        if(lc>rc||!lc)return;
        if(lc<=l&&r<=rc)return put(x,1);down(x);if(lc<=mid)add(lc,rc,x*2,l,mid);if(rc>mid)add(lc,rc,x*2+1,mid+1,r);up(x);
    }
    void down(int x){if(tg[x])put(x*2,tg[x]),put(x*2+1,tg[x]),tg[x]=0;}
    void put(int x,int v){tg[x]+=v,mx[x]+=v;}
    void up(int x){mx[x]=max(mx[x*2],mx[x*2+1]);}
}se;
#undef mid
void add1(int x){int y=fa[x];assert(y);se.add(dfn[y],dfn[y]),se.add(df1[y]+1,dfn[x]-1),se.add(dfn[x]+1,df2[y]);}
void add2(int x){se.add(df1[x]+1,df2[x]);}
int main(){
    scanf("%d",&n);for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x),++dg[x],++dg[y];
    for(int i=1;i<=n;++i)jg[1]=max(jg[1],dg[i]+1);
    dfs0(1,0);dfs1(1);
    ans=1;
    for(int i=2*n;i>=2;--i){
        int t=i>>1;
        if(i%2){
            int ans0=ans;
            for(int x:v0[t])ans0=max(ans0,cc[x]+1);
            jg[i]=ans0;
        }else{
            for(int x:v0[t])ans=max(ans,++cc[x]);
            for(int x:ve[t])add1(x);
            for(int x:ev[t])add2(x);
            jg[i]=max(ans,se.mx[1]);
        }
    }
    
    for(int i=1;i<=n;++i)printf("%d ",jg[i]);puts("");
    return 0;
}