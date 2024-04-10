#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 505
#define mod 998244353
typedef long long ll;
int n,K;
ll f[2][N][N],g[2][N][N],F[N],ans;
void upd(ll &x,ll y) {x=x+y; if(x>=mod) x-=mod;}
int main() {
    scanf("%d%d",&n,&K);
    int i,j,k;
    int lim=min(n,K-1);
    f[0][0][0]=2;
    for(i=0;i<n;i++) {
        int i0=i&1,i1=(i+1)&1;
        for(j=0;j<=lim;j++) {
            for(k=0;k<=j;k++) {
                if(k+1<=lim) upd(f[i1][max(j,k+1)][k+1],f[i0][j][k]);
                if(k) upd(f[i1][j][1],f[i0][j][k]);
            }
        }
        memset(f[i0],0,sizeof(f[i0]));
    }
    for(i=1;i<=lim;i++) for(j=1;j<=i;j++) upd(F[i],f[n&1][i][j]);
    for(i=1;i<=lim;i++) g[0][i][0]=F[i];
    for(i=0;i<n;i++) {
        int i0=i&1,i1=(i+1)&1;
        for(j=1;j<=lim;j++) {
            for(k=0;k<=i;k++) {
                if(j*k>=K) continue;
                if(j*(k+1)<K) upd(g[i1][j][k+1],g[i0][j][k]);
                if(k) upd(g[i1][j][1],g[i0][j][k]);
            }
        }
        memset(g[i0],0,sizeof(g[i0]));
    }
    for(i=0;i<=lim;i++) {
        for(j=1;j<=lim;j++) {
            if(i*j<K) upd(ans,g[n&1][i][j]);
        }
    }
    printf("%lld\n",ans);
    // int x,y,z;
    // while(1) {
    // 	scanf("%d%d%d",&x,&y,&z);
    // 	printf("g[%d][%d][%d]=%lld\n",x,y,z,g[x][y][z]);
    // }
}