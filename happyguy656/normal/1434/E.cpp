#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int abc;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3,sq=449;
int n,v[mxn],vl[sq][mxn],wz[mxn],vs[mxn],xl[mxn];
struct bcc{
    int fa[sq][mxn];void ii(){for(int i=0;i<sq;++i)for(int j=1;j<=n;++j)fa[i][j]=j;}
    int ff(int k,int x){while(x!=fa[k][x])x=fa[k][x]=fa[k][fa[k][x]];return x;}
    void wk(int k,int l,int r,int v){
        for(int x=ff(k,r);x>=l;--x,x=ff(k,x))fa[k][x]=x-1,vl[k][x]=v;
    }
}u;
int main(){
    int C;scanf("%d",&C);int XR=0;while(C--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",v+i);u.ii();for(int i=0;i<sq;++i)for(int j=1;j<=n;++j)vl[i][j]=0;
        for(int i=0;i<n;++i)for(int j=v[i];j<v[i+1];++j)wz[j]=i+1;
        for(int t=n;t;--t){
            int po=n,ls=1;
            for(int i=0;i<sq;++i){
                if(!vl[i][t]){u.wk(i,ls,t-1,t),vs[i]=1,xl[t]=i;break;}
                po=min(vl[i][t],po);
                int x=2*v[t]-v[po],y=x<=0?1:wz[x];
                u.wk(i,ls,y-1,t),ls=y;
            }
        }
        for(int i=0;i<mxn;++i)if(!vs[i]){XR^=i;break;}
        for(int i=1;i<=n;++i)vs[xl[i]]=0;
    }
    puts(XR?"YES":"NO");
    return 0;
}