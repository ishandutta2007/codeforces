#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2003;
int n,m,g1[mxn],g2[mxn],px[mxn],zx[mxn],zy[mxn],b[mxn];double ja[mxn];
int fa[mxn];inline int FF(int x){while(x!=fa[x])x=fa[x]=fa[fa[x]];return x;}
void mer(int x,int y){x=FF(x),y=FF(y),fa[x]=y;}
bool cmp1(int x,int y){return ja[x]<ja[y];}
int an;pii as[mxn*2];
void wk(int x,int y){as[++an]=pii(g1[x],g1[y]),swap(b[x],b[y]);}
void W(double x,double y){cout<<atan2(y,x)<<endl;}
int main(){
//W(1,1),W(1,2),W(1,3),W(-1,3),W(-1,2),W(-1,1),W(-1,-1),W(-1,-2),W(-1,-3),W(1,-3),W(1,-2),W(1,-1);
    scanf("%d",&n);for(int i=1,x,y,z;i<=n;++i){scanf("%d%d%d",&x,&y,&z);if(i!=z)++m,zx[m]=x,zy[m]=y,g1[m]=i,g2[i]=m,b[m]=z;}
    if(!m)return puts("0"),0;
    int mn=1;for(int i=2;i<=m;++i)if(zx[i]<zx[mn])mn=i;swap(zx[1],zx[mn]),swap(zy[1],zy[mn]),swap(b[1],b[mn]),swap(g1[1],g1[mn]),swap(g2[g1[1]],g2[g1[mn]]);
    for(int i=1;i<=m;++i)ja[i]=atan2(zy[i]-zy[1],zx[i]-zx[1]),px[i]=i,fa[i]=i,b[i]=g2[b[i]];
    for(int i=1;i<=m;++i)mer(i,b[i]);
    sort(px+2,px+m+1,cmp1);
    for(int i=2;i<m;++i)if(FF(px[i])!=FF(px[i+1]))mer(px[i],px[i+1]),wk(px[i],px[i+1]);
    for(int i=1;i<m;++i)wk(1,b[1]);
    printf("%d\n",an);for(int i=1;i<=an;++i)printf("%d %d\n",as[i].first,as[i].second);
    return 0;
}