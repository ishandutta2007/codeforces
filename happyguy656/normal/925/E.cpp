#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define vb(x) lb[x].begin()
#define ve(x) lb[x].end()
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int> pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3,sq=333;
int to[mxn],nxt[mxn],fir[mxn],gn=1,n,fa[mxn],dep[mxn],siz[mxn],dfn[mxn],dn,top[mxn],zs[mxn],dfa[mxn],va[mxn],m,xw[mxn],ans,ux[mxn],un,stk[mxn],sn,fb[mxn],sg[mxn],co[mxn];
void gadd(int x,int y){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn;}
void dfs0(int x,int f){fa[x]=f,dep[x]=dep[f]+1,siz[x]=1;forg(i,x){dfs0(to[i],x);siz[x]+=siz[to[i]];if(siz[to[i]]>siz[zs[x]])zs[x]=to[i];}}
void dfs1(int x,int f){dfn[x]=++dn,dfa[dn]=x;top[x]=x==zs[f]?top[f]:x;if(zs[x])dfs1(zs[x],x);forg(i,x)if(to[i]!=zs[x])dfs1(to[i],x);}
int lca(int x,int y){while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])swap(x,y);x=fa[top[x]];}return dep[x]<dep[y]?x:y;}
bool cmp1(int x,int y){return dfn[x]<dfn[y];}
typedef vector<pii>vp;typedef vp::iterator VP;
vp lb[mxn];VP zp[mxn],sf[mxn];
void px(int a[],int x){
    if(x<=10000)return sort(a+1,a+x+1);
    static int c[mxn*2];memset(c,0,sizeof(c));
    for(int i=1;i<=x;++i)++c[a[i]+n];
    int p=x;
    for(int i=2*n;~i;--i)while(c[i]--)a[p--]=i-n;
}
int main(){
    scanf("%d%d",&n,&m);for(int i=2,x;i<=n;++i)scanf("%d",&x),gadd(x,i);
    dfs0(1,0),dfs1(1,0);for(int i=1,x;i<=n;++i)scanf("%d",&x),va[i]=-x;for(int i=1;i<=m;++i)scanf("%d",xw+i);
    assert(dn==n);
    for(int L=1,R;R!=m;L=R+1){
        R=min(m,L+sq-1);for(int i=L;i<=R;++i)ux[++un]=abs(xw[i]);sort(ux+1,ux+un+1,cmp1);for(int i=un-1;i;--i)ux[++un]=lca(ux[i],ux[i+1]);sort(ux+1,ux+un+1,cmp1);un=unique(ux+1,ux+un+1)-ux-1;
        stk[sn=1]=ux[1];
        for(int i=2;i<=un;++i){
            int x=ux[i],y;while(y=stk[sn],dfn[x]>dfn[y]+siz[y]-1)--sn;fb[x]=y,stk[++sn]=x;
        }
        for(int i=1;i<=sn;++i)fb[stk[i]]=stk[i-1];
        for(int T=1;T<=un;++T){int x=ux[T],tn=0;static int xl[mxn]; xl[++tn]=va[x];for(int y=fa[x];y!=fb[x];y=fa[y])if(!co[y])xl[++tn]=va[y]; px(xl,tn);
            for(int l=1,r;l<=tn;l=r+1){r=l;while(r<tn&&xl[r]==xl[r+1])++r; int k=r-l+1;if(xl[r]==va[x]&&co[x])--k; lb[x].push_back(pii(xl[r],k));}
            zp[x]=upper_bound(vb(x),ve(x),pii(0,1e9)),sf[x]=lower_bound(vb(x),ve(x),pii(va[x],-1e9));}
        for(int T=L;T<=R;++T){
            int x=xw[T];if(x>0)assert(!co[x]);else assert(co[-x]);
            if(x>0){co[x]^=1;
                for(int y=x;y;y=fb[y]){++sg[y];VP&p=zp[y]; if(p!=vb(y)&&(p-1)->first+sg[y]>0)--p,ans+=p->second;}
                --sf[x]->second; if(va[x]+sg[x]>0)--ans;
            }
            else{x=-x;co[x]^=1;
                for(int y=x;y;y=fb[y]){--sg[y];VP&p=zp[y]; if(p!=ve(y)&&p->first+sg[y]<=0)ans-=p->second,++p;}
                ++sf[x]->second; if(va[x]+sg[x]>0)++ans;
            }
            printf("%d ",ans);
        }
        for(int i=1,x;i<=un;++i){x=ux[i];for(int j=x;j!=fb[x];j=fa[j])va[j]+=sg[x]; vp().swap(lb[x]);sg[x]=0;}
        un=0;
    }
    puts("");
    return 0;
}