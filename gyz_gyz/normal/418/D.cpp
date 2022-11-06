#include<cstdio>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 131072
#define M 8000000
using namespace std;
int a[M],b[M],c[M],L[M],R[M],l[M],r[M];
int rk[N],id[N],top[N],s[N],h[N],f[N][17],n,m,x,y,z,X,Y,rr,tot;
vector<int>e[N];
inline void up(int x){
    if(a[l[x]]+b[l[x]]>a[r[x]]+b[r[x]])a[x]=a[l[x]]+b[l[x]];
    else a[x]=a[r[x]]+b[r[x]];
}
inline void nw(int x,int y){
    c[++tot]=y;a[tot]=a[x];b[tot]=b[x];
    L[tot]=L[x];R[tot]=R[x];l[tot]=l[x];r[tot]=r[x];
}
void ins(int x,int y,int l1,int r1){
    if(l1==L[x]&&r1==R[x]){b[x]+=y;return;}
    if(r1<=R[l[x]]){
        if(c[l[x]]!=c[x]){nw(l[x],c[x]);l[x]=tot;}
        ins(l[x],y,l1,r1);up(x);return;
    }
    if(l1>=L[r[x]]){
        if(c[r[x]]!=c[x]){nw(r[x],c[x]);r[x]=tot;}
        ins(r[x],y,l1,r1);up(x);return;
    }
    if(c[l[x]]!=c[x]){nw(l[x],c[x]);l[x]=tot;}
    if(c[r[x]]!=c[x]){nw(r[x],c[x]);r[x]=tot;}
    ins(l[x],y,l1,R[l[x]]);ins(r[x],y,L[r[x]],r1);up(x);
}
int q(int x,int l1,int r1){
    if(l1==L[x]&&r1==R[x])return a[x]+b[x];
    if(r1<=R[l[x]])return q(l[x],l1,r1)+b[x];
    if(l1>=L[r[x]])return q(r[x],l1,r1)+b[x];
    int f1=q(l[x],l1,R[l[x]]),f2=q(r[x],L[r[x]],r1);
    if(f1>f2)return f1+b[x];else return f2+b[x];
}
void dfs(int x){
    int sz=e[x].size()-1;rk[x]=++y;id[y]=x;s[x]=1;
    rep(i,1,16)f[x][i]=f[f[x][i-1]][i-1];
    rep(i,0,sz){int tt=e[x][i];
        if(f[x][0]!=tt){
            f[tt][0]=x;h[tt]=h[x]+1;dfs(tt);s[x]+=s[tt];
        }
    }
}
int main(){
    scanf("%d",&n);
    rep(i,1,n-1){
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    y=0;f[1][0]=1;dfs(1);top[1]=1;tot=N*2-1;L[1]=1;R[1]=N;
    rep(i,1,N-1){
        L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
        L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];l[i]=i*2;r[i]=i*2+1;
    }
    rep(i,1,n)b[i+N-1]=h[id[i]];
    dep(i,N-1,1)up(i);
    rep(i,2,n){
        rr=i+s[id[i]];nw(top[rk[f[id[i]][0]]],i);top[i]=tot;
        ins(top[i],1,1,i-1);ins(top[i],-1,i,rr-1);
        if(rr<=n)ins(top[i],1,rr,n);
    }
    scanf("%d",&m);
    rep(i,1,m){
        scanf("%d%d",&x,&y);
        if(h[x]<h[y])swap(x,y);X=x,Y=y;
        dep(i,16,0)if(h[x]-(1<<i)>=h[y])x=f[x][i];
        dep(i,16,0)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
        if(x!=y)x=f[x][0],y=f[y][0];z=h[x]+(h[X]-h[Y])/2+1;x=X;y=Y;
        dep(i,16,0)if(h[x]-(1<<i)>=z)x=f[x][i];
        z=x;x=X;rr=rk[z]+s[z];X=q(top[rk[x]],rk[z],rr-1);
        Y=q(top[rk[y]],1,rk[z]-1);if(Y>X)X=Y;
        if(rr<=n){Y=q(top[rk[y]],rr,n);if(Y>X)X=Y;}
        printf("%d\n",X);
    }
}