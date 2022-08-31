#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3005;
const int M=998244353;
int n,c,a[maxn],dp[maxn][maxn],f[2][maxn][maxn],cnt[maxn],w[maxn][maxn],ans[maxn];
int invp[maxn],p[maxn];
int pow_(int x,int y){
    ll ret=1;
    while (y){
        if (y&1) ret=ret*x%M;
        x=1ll*x*x%M; y>>=1;
    }
    return (int)ret;
}
void add(int &x,int y){
    x+=y; if (x>=M) x-=M;
}
void sub(int &x,int y){
    x-=y; if (x<0) x+=M;
}
int mul(int x,int y){
    return (ll)x*y%M;
}

int main(){
    p[0]=0;for (int i=1;i<maxn;i++) p[i]=(p[i-1]*2+1)%M,invp[i]=pow_(p[i],M-2);
    cin >> n >> c;
    for (int i=1;i<=n;i++) {cin >> a[i];--a[i];}
    if (c>=12){
        for (int l=0;l<n;l++){
            ll res=1;
            int tot=0;
            memset(cnt,0,sizeof(cnt));
            for (int r=l+1;r<=n;r++){
                if (cnt[a[r]]) res=res*invp[cnt[a[r]]]%M; else ++tot;
                cnt[a[r]]++;
                if (tot==c) w[l][r]=res;
                res=res*p[cnt[a[r]]]%M;
            }
        }
        dp[0][0]=1;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<=n;j++) if (w[i][j]){
                int res=w[i][j];
                for (int k=0;k<=i/c;k++)
                    add(dp[j][k+1],mul(dp[i][k],res));
            }
        for (int i=0;i<=n;i++)
            for (int k=0;k<=i/c;k++)
                add(ans[k],mul(dp[i][k],(p[n-i]+1)));
        for (int i=0;i<n;i++) sub(ans[i],ans[i+1]);
    } else {
        int r=1<<c; f[0][0][0]=1;
        for (int i=1;i<=n;i++){
            int o=i&1;
            for (int k=0;k<=i/c;k++)
                for (int j=0;j<r;j++) if (f[o^1][k][j]){
                    add(f[o][k][j],f[o^1][k][j]);
                    add(f[o][k][j|(1<<a[i])],f[o^1][k][j]);
                    f[o^1][k][j]=0;
                }
            for (int k=0;k<=i/c;k++) {
                add(f[o][k+1][0],f[o][k][r-1]);
                f[o][k][r-1]=0;
            }
        }
        for (int k=0;k<=n/c;k++)
            for (int j=0;j<r;j++)
                add(ans[k],f[n&1][k][j]);
    }
    sub(ans[0],1);
    for (int i=0;i<=n;i++) cout << ans[i] << ' '; cout << endl;
    return 0;
}