#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define uu unsigned
int abc;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mod=1e9+7,mxn=3003;
ll por(ll x,int y=mod-2){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
VI g1[mxn],g2[13];int n,m,U,xl[mxn],tn,f0[mxn],zz[13],fa[13];
ull dp[mxn][13],ff[2][1<<12];
void dfs(int x,int f){fa[x]=f;zz[x]=1<<(x-1);for(int y:g2[x])if(y!=f)dfs(y,x),zz[x]|=zz[y];}
void dfs0(int x,int f){
    if(!f)tn=0;f0[x]=f,xl[++tn]=x;
    for(int y:g1[x])if(y!=f)dfs0(y,x);
}
void dfs1(int x,int f){
    if(!f)tn=0;f0[x]=f,xl[++tn]=x;
    for(int y:g2[x])if(y!=f)dfs1(y,x);
}
ll calc(VI g1[],VI g2[],int n,int m){
    ll ans=0;
    for(int r=1;r<=m;++r){
        dfs(r,0);
        for(int T=n;T;--T){
            int x=xl[T];
            for(int y=1;y<=m;++y){
                memset(ff,0,sizeof(ff));
                int o=0;ff[0][0]=1;
                for(int k:g1[x])if(k!=f0[x]){
                    for(int z=0;z<(1<<m);++z)ff[o^1][z]=ff[o][z];
                    for(int k2:g2[y])if(k2!=fa[y]&&dp[k][k2]){
                        for(int z=0;z<(1<<m);++z)if(ff[o][z]&&!(z&zz[k2]))(ff[o^1][z|zz[k2]]+=ff[o][z]*dp[k][k2])%=mod;
                    }
                    o^=1;
                }
                dp[x][y]=ff[o][zz[y]^(1<<(y-1))];
            }
            ans+=dp[x][r];
        }
    }
    return ans%mod;
}

int main(){
    cin>>n;for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),g1[x].push_back(y),g1[y].push_back(x);
    cin>>m;U=1<<m,--U;for(int i=1,x,y;i<m;++i)scanf("%d%d",&x,&y),g2[x].push_back(y),g2[y].push_back(x);
    dfs0(1,0);ll ans=calc(g1,g2,n,m);dfs1(1,0);ll ans2=calc(g2,g2,m,m);
    ans=ans*por(ans2)%mod;printf("%lld\n",ans);
    return 0;
}