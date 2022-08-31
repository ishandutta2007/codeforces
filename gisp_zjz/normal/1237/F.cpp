#include<bits/stdc++.h>
using namespace std;
const int maxn=4005;
const int M=998244353;
int ans,f[maxn],C[maxn][maxn],n,m,q,dx[maxn],dy[maxn],w,tmp[maxn],sx,sy;
bool x[maxn],y[maxn];
void init(){
    for (int i=0;i<maxn;i++){
        C[i][0]=C[i][i]=1;
        for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
    }
    f[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M;
    /*
    f[0][0]=1;
    for (int i=1;i<maxn;i++){
        f[i][0]=1;
        for (int j=1;j<=i/2;j++) f[i][j]=(f[i-2][j-1]+f[i-1][j])%M;
    }
    */
}
void add(int &x,int y){x+=y; if (x>=M) x-=M;}
int main(){
    init();
    scanf("%d%d%d",&n,&m,&q); q*=2;
    while (q--){
        int a,b;
        scanf("%d%d",&a,&b);
        x[a]=1; y[b]=1;
    }
    x[n+1]=y[m+1]=1;
    dx[0]=1; w=0;
    for (int i=1;i<=n+1;i++) {
        if (!x[i]) sx++,w++;
        else if (w) {
            for (int j=0;j<=n/2;j++) tmp[j]=dx[j],dx[j]=0;
            for (int j=0;j<=n/2;j++) if (tmp[j])
                for (int k=0;k<=w/2;k++) {
                    add(dx[j+k],1ll*tmp[j]*C[w-k][k]%M);
                }
            w=0;
        }
    }
    dy[0]=1; w=0;
    for (int i=1;i<=m+1;i++) {
        if (!y[i]) sy++,w++;
        else if (w) {
            for (int j=0;j<=m/2;j++) tmp[j]=dy[j],dy[j]=0;
            for (int j=0;j<=m/2;j++) if (tmp[j])
                for (int k=0;k<=w/2;k++) {
                    add(dy[j+k],1ll*tmp[j]*C[w-k][k]%M);
                }
            w=0;
        }
    }
    for (int i=0;i<=n/2;i++) dx[i]=1ll*dx[i]*f[i]%M;
    for (int i=0;i<=m/2;i++) dy[i]=1ll*dy[i]*f[i]%M;
    for (int i=0;i<=n/2;i++) if (dx[i])
    for (int j=0;j<=m/2;j++) if (dy[j]){
        add(ans,1ll*dx[i]*dy[j]%M*C[sx-i*2][j]%M*C[sy-j*2][i]%M);
    }
    printf("%d\n",ans);
    return 0;
}