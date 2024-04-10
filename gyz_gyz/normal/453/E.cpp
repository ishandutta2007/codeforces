#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 131072
#define ll long long
using namespace std;
int p[18][N+1],P[18][N+1];
ll q[18][N+1],Q[18][N+1],w[18][N+1],W[18][N+1],e[18][N+1];
int a[N*2],L[N*2],R[N*2],h[N*2],s[N],t[N],g[N],n,m,x,l,r;
inline bool cmp1(const int &x,const int &y){
    if(!g[x])return 0;if(!g[y])return 1;
    return t[x]/g[x]<t[y]/g[y];
}
inline bool cmp2(const int &x,const int &y){
    if(!g[x])return 0;if(!g[y])return 1;
    return (t[x]-s[x])/g[x]<(t[y]-s[y])/g[y];
}
inline void dw(int x){if(a[x]>=-1)a[x*2]=a[x*2+1]=a[x];}
inline void up(int x){
    if(a[x*2]==a[x*2+1])a[x]=a[x*2];else a[x]=-2;
}
ll f(int x,int y,int l,int r){
    if(l==L[x]&&r==R[x]&&a[x]>=-1){
        int ls=y-a[x],T=x,M;
        if(a[x]==-1){ls=a[x]=y;
            while(L[T]!=R[T]){T*=2;
                M=P[h[x]][R[T]];
                if(g[M]&&(t[M]-s[M])/g[M]<ls)T++;
            }M=P[h[x]][R[T]];
            if(g[M]&&(t[M]-s[M])/g[M]<ls)return Q[h[x]][R[x]];
            if(L[T]==L[x])return W[h[x]][L[x]]*ls+e[h[x]][L[x]];
            return Q[h[x]][R[T]-1]+W[h[x]][R[T]]*ls+e[h[x]][R[T]];
        }a[x]=y;
        while(L[T]!=R[T]){T*=2;
            M=p[h[x]][R[T]];
            if(g[M]&&t[M]/g[M]<ls)T++;
        }M=p[h[x]][R[T]];
        if(g[M]&&t[M]/g[M]<ls)return q[h[x]][R[x]];
        if(L[T]==L[x])return w[h[x]][L[x]]*ls;
        return q[h[x]][R[T]-1]+w[h[x]][R[T]]*ls;
    }
    dw(x);ll X;
    if(r<=R[x*2])X=f(x*2,y,l,r);
    else if(l>=L[x*2+1])X=f(x*2+1,y,l,r);
    else X=f(x*2,y,l,R[x*2])+f(x*2+1,y,L[x*2+1],r);
    up(x);return(X);
}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d%d",&s[i],&t[i],&g[i]);
    L[1]=1;R[1]=N;h[1]=0;
    rep(i,1,N-1){
        h[i*2]=h[i*2+1]=h[i]+1;
        L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
        L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];
    }
    rep(i,1,N*2-1){a[i]=-1;
        rep(j,L[i],R[i])p[h[i]][j]=P[h[i]][j]=j;
        sort(p[h[i]]+L[i],p[h[i]]+R[i]+1,cmp1);
        sort(P[h[i]]+L[i],P[h[i]]+R[i]+1,cmp2);     
    }
    rep(i,1,N*2-1){
        q[h[i]][L[i]]=t[p[h[i]][L[i]]];
        w[h[i]][R[i]]=g[p[h[i]][R[i]]];
        rep(j,L[i]+1,R[i])q[h[i]][j]=q[h[i]][j-1]+t[p[h[i]][j]];
        dep(j,R[i]-1,L[i])w[h[i]][j]=w[h[i]][j+1]+g[p[h[i]][j]];
        Q[h[i]][L[i]]=t[P[h[i]][L[i]]];W[h[i]][R[i]]=g[P[h[i]][R[i]]];
        e[h[i]][R[i]]=s[P[h[i]][R[i]]];
        rep(j,L[i]+1,R[i])Q[h[i]][j]=Q[h[i]][j-1]+t[P[h[i]][j]];
        dep(j,R[i]-1,L[i])W[h[i]][j]=W[h[i]][j+1]+g[P[h[i]][j]];
        dep(j,R[i]-1,L[i])e[h[i]][j]=e[h[i]][j+1]+s[P[h[i]][j]];        
    }
    scanf("%d",&m);
    rep(i,1,m){
        scanf("%d%d%d",&x,&l,&r);
        printf("%I64d\n",f(1,x,l,r));
    }
}