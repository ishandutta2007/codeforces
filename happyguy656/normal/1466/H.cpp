#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef pair<int,int>pii;
typedef long long ll;
typedef uu long long ull;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mod=1e9+7;
int n,a[41],cc[41],vs[41];
ll dp[1440][41][41][42];
ll por(ll x,int y){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
int zy[1440][41][41];
int zp[44];
vector<int>ys[41];
ll vv[41][41][41],C[41][41],jc[41],iv[41];
bool zp1(int x){for(int i=1;i<=n;++i)zp[i]=x%cc[i],x/=cc[i];return x==0;}
int zp2(int a[]=zp){
for(int i=1;i<=n;++i)assert(a[i]<cc[i]);
    int re=0;for(int i=n;i;--i)re*=cc[i],re+=a[i];return re;
}
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=0;i<=n;++i){C[i][0]=1;for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;}
    jc[0]=1;for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod,iv[i]=por(i,mod-2);
    for(int i=1;i<=n;++i)cc[i]=1;
    for(int i=1;i<=n;++i)if(!vs[i]){int c=0;for(int j=i;!vs[j];j=a[j])vs[j]=1,++c;++cc[c];}
    memset(zy,-1,sizeof(zy));
    int U=0;
    for(int i=0;i<1440&&zp1(i);++i)for(int j=1;j<=n;++j)for(int k=0;k+zp[j]<cc[j];++k){
        U=i;
        zp[j]+=k;zy[i][j][k]=zp2();zp[j]-=k;
    }
    for(int i=0;i<=U;++i){
        assert(zp1(i));
        int c=0;for(int j=1;j<=n;++j)c+=zp[j]*j;
        ys[c].push_back(i);
    }
    dp[0][0][0][1]=1;
    for(int k=1;k<=n;++k)for(int x=0;x<n;++x)for(int y=0;y+x<n;++y){
        if(y==0)vv[k][x][y]=por(jc[n-1],k);
        else{
            int z=n-x-y;
            ll v=por(C[y+z][y],k)-por(C[y+z-1][y],k);
            v=v*por(C[n][x]*jc[x]%mod*jc[z-1]%mod*jc[y]%mod,k)%mod;
            vv[k][x][y]=v;
        }
    }
    for(int t=0;t<n;++t){
        for(int x:ys[t]){
            for(int i=0;i<=t;++i)for(int j=0;j<=t;++j)for(int k=1;k<=n;++k)if(dp[x][i][j][k]){
                dp[x][i][j][k]%=mod;
                dp[x][i][j][k+1]+=dp[x][i][j][k];
                ll v=dp[x][i][j][k];
                for(int h=1;h<cc[k]&&~zy[x][k][h];++h){
                    int y=zy[x][k][h];
                    v*=vv[k][t-i-j][i]*iv[h]%mod,v%=mod;
                    dp[y][i][j+h*k][k+1]+=v;
                    dp[y][j+h*k][0][1]+=v;
                }
            }
        }
    }
    ll re=0;for(int i=0;i<=n;++i)re+=dp[U][i][0][1];
    re%=mod;for(int i=1;i<=n;++i)re=re*jc[cc[i]-1]%mod;
    re=(re%mod+mod)%mod;
    printf("%lld\n",re);
    return 0;
}