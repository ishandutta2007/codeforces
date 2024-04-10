#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
//mt19937 rnd(time(0));
//int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=2e5+3;
int n,m,d1[mxn],dn,d2[mxn],de[mxn],C,fa[mxn],db[mxn];bool vs[mxn];
ll ans=-9e18;
VI g[mxn];
void dfs0(int x,int f){
    fa[x]=f;
    d1[x]=++dn,db[dn]=x,de[x]=de[f]+1;for(int y:g[x])if(y!=f)dfs0(y,x);
    d2[x]=dn;
}
#define mid ((l+r)>>1)
struct seeeeee{
    int a[mxn*4],tg[mxn*4],po[mxn*4];
    void bu(int x=1,int l=1,int r=n){
        if(l==r)return a[x]=de[db[l]],po[x]=db[l],void();
        bu(x*2,l,mid),bu(x*2+1,mid+1,r);up(x);
    }
    void del(int lc,int rc,int x=1,int l=1,int r=n){
        if(lc<=l&&r<=rc)return put(x,-1);down(x);
        if(lc<=mid)del(lc,rc,x*2,l,mid);if(rc>mid)del(lc,rc,x*2+1,mid+1,r);up(x);
    }
    void up(int x){if(a[x*2]>a[x*2+1])a[x]=a[x*2],po[x]=po[x*2];else a[x]=a[x*2+1],po[x]=po[x*2+1];}
    void down(int x){if(tg[x])put(x*2,tg[x]),put(x*2+1,tg[x]),tg[x]=0;}
    void put(int x,int v){tg[x]+=v,a[x]+=v;}
    int gg(){return a[1]?po[1]:0;}
}se;
#undef mid
ll EE(int R){
    int x=C-R,y=R-n+C,L=n-C;
    ll re=1ll*x*y;re=min(re,1ll*(x+L)*(y+L));
    int e=(-x-y)>>1;for(int i=-5;i<=5;++i)if(e+i>=0&&e+i<=L)re=min(re,1ll*(x+e+i)*(y+e+i));
    return re;
}
int main(){
    cin>>n>>m;for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
    dfs0(1,0);se.bu();
    vs[0]=1;
    for(int t=0;t<=m;++t){
        if(t){int x=se.gg();for(;!vs[x];x=fa[x])++C,vs[x]=1,se.del(d1[x],d2[x]);}
        ans=max(ans,EE(t));
    }
    cout<<ans<<endl;
    return 0;
}