#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 262144
#define mo 1000000007
#define ll long long
using namespace std;
int n,m,nw,ff,tot,ty[N],w[N],F[N],Q[N],rk[N],si[N],s[N];
vector<int>e[N];int L[N*2],R[N*2];ll ls,a[N*2],b[N*2];
ll ny(int x){if(x==1)return 1;ll y=mo/x+1;return ny(x*y-mo)*y%mo;}
inline void dw(int x){
    a[x*2+1]=a[x*2+1]*b[x]%mo;b[x*2+1]=b[x*2+1]*b[x]%mo;
    a[x*2]=a[x*2]*b[x]%mo;b[x*2]=b[x*2]*b[x]%mo;b[x]=1;
}
inline void up(int x){a[x]=(a[x*2]+a[x*2+1])%mo;}
void f(int x,int y,int l,int r){
    if(L[x]==l&&R[x]==r){
        a[x]=a[x]*y%mo;b[x]=b[x]*y%mo;return;
    }dw(x);
    if(r<=R[x*2]){f(x*2,y,l,r);up(x);return;}
    if(l>=L[x*2+1]){f(x*2+1,y,l,r);up(x);return;}
    f(x*2,y,l,R[x*2]);f(x*2+1,y,L[x*2+1],r);up(x);
}
void g(int x,int y,int z){
    if(L[x]==y&&R[x]==y){a[x]=b[x]*z%mo;return;}dw(x);
    if(y<=R[x*2])g(x*2,y,z);else g(x*2+1,y,z);up(x);
}
ll q(int x,int l,int r){
    if(L[x]==l&&R[x]==r)return a[x];dw(x);
    if(r<=R[x*2])return q(x*2,l,r);
    if(l>=L[x*2+1])return q(x*2+1,l,r);
    return (q(x*2,l,R[x*2])+q(x*2+1,L[x*2+1],r))%mo;
}
void dfs(int x){int sz=e[x].size()-1;
    rk[x]=++tot;si[x]=1;
    rep(i,0,sz){int tt=e[x][i];
        dfs(tt);si[x]+=si[tt];
    }
}
int main(){
    scanf("%d%d",&w[1],&m);n=1;
    rep(i,1,m){
        scanf("%d",&ty[i]);
        if(ty[i]==1){n++;scanf("%d%d",&F[n],&w[n]);}
        else scanf("%d",&Q[i]);
    }
    rep(i,2,n)e[F[i]].push_back(i);
    rep(i,1,N*2-1)b[i]=1;L[1]=1;R[1]=N;
    rep(i,1,N-1){
        L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
        L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];
    }
    rep(i,1,n)s[i]=1;dfs(1);g(1,1,w[1]);nw=1;
    rep(i,1,m)
        if(ty[i]==1){nw++;ff=F[nw];s[nw]=1;
            ls=ny(s[ff]);s[ff]++;g(1,rk[nw],w[nw]);
            f(1,ls*s[ff]%mo,rk[ff],rk[ff]+si[ff]-1);
        }else{ff=F[Q[i]];
            if(ff)ls=ny(q(1,rk[ff],rk[ff]))*w[ff]%mo;else ls=1;
            printf("%I64d\n",q(1,rk[Q[i]],rk[Q[i]]+si[Q[i]]-1)*ls%mo);
        }
}