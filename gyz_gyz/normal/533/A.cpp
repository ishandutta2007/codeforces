#include<cstdio>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 500001
#define inf 2000000000
using namespace std;
vector<int>e[mx];
struct pr{int a,b,t;}a[mx];
int n,m,h[mx],w[mx],f[mx],r[mx],fl,j,tt,ans,x,y;
inline bool cmp1(pr x,pr y){
    if(x.a!=y.a)return x.a>y.a;
    if(x.t!=y.t)return x.t<y.t;
    return x.b>y.b;
}
inline bool cmp2(int x,int y){return x>y;}
void dfs(int x){
    if(f[x]){
        if(a[f[x]].b>h[x])a[x].b=h[x];else a[x].b=a[f[x]].b;
        if(a[f[x]].a>h[x]){
            a[x].a=h[x];a[x].t=x;a[x].b=a[f[x]].a;
        }else{
            a[x].a=a[f[x]].a;a[x].t=a[f[x]].t;
        }
    }
    int sz=e[x].size()-1;
    rep(i,0,sz)if(e[x][i]!=f[x]){
        f[e[x][i]]=x;dfs(e[x][i]);
    }
}
int main(){
    scanf("%d",&n);ans=inf;
    rep(i,1,n)scanf("%d",&h[i]);
    rep(i,1,n-1){
        scanf("%d%d",&x,&y);
        e[x].push_back(y);e[y].push_back(x);
    }
    a[1].a=h[1];a[1].b=inf;a[1].t=1;dfs(1);sort(a+1,a+n+1,cmp1);
    scanf("%d",&m);rep(i,1,m)scanf("%d",&w[i]);sort(w+1,w+m+1,cmp2);
    rep(i,1,n)if(a[i].a<w[i])fl=a[i].t;j=1;
    rep(i,1,n)if(a[i].t==fl){fl=i;break;}if(!fl)fl=1;
    rep(i,1,fl-1){
        for(;a[i].a<w[j];j++)r[++tt]=w[j];j++;
    }
    rep(i,fl,n){
        if(a[i].t!=a[i-1].t){
            int u=0,ss=0;
            rep(k,i,n){
                if(a[k].t!=a[i].t)break;
                if(k-i+1<=tt){
                    if(a[k].b<r[k-i+1])u=1;
                }else{
                    if(a[k].b<w[k])u=1;
                }
            }
            if(tt&&a[i+tt-1].t!=a[i].t)u=1;
            if(tt)ss=r[1];else ss=w[i];
            if(ss>a[i].a)ss-=a[i].a;else ss=0;
            if(!u&&ss<ans)ans=ss;
        }
        for(;a[i].a<w[j];j++)r[++tt]=w[j];j++;
    }
    if(ans==inf)printf("-1\n");else printf("%d\n",ans);
}