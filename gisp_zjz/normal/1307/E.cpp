#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=5e3+3;
const int M=1000000007;
int cnt[maxn][maxn],a[maxn],n,m,tot[maxn],lf[maxn],mx,ans;
int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        cnt[u][v]++;
    }
    for (int i=1;i<=n;i++) tot[a[i]]++;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cnt[i][j]+=cnt[i][j-1];
    // lf=0
    {
        int res=0,sum=1;
        for (int i=1;i<=n;i++){
            int u=cnt[i][tot[i]];
            if (u) res++,sum=1ll*sum*u%M;
        }
        mx=res; ans=sum;
    }
    for (int i=1;i<=n;i++){
        int x=a[i];
        lf[x]++;
        if (cnt[x][lf[x]]==cnt[x][lf[x]-1]) continue;
        int res=1,sum=1;
        int u=cnt[x][tot[x]-lf[x]];
        if (tot[x]-lf[x]>=lf[x]) u--;
        if (u) res++,sum=1ll*sum*u%M;
        for (int j=1;j<=n;j++){
            if (j==x) continue;
            int p=lf[j],q=tot[j]-lf[j];
            int u=cnt[j][p]*cnt[j][q]-cnt[j][min(p,q)];
            if (u) res+=2,sum=1ll*sum*u%M;
            else {
                u=cnt[j][p]+cnt[j][q];
                if (u) res++,sum=1ll*sum*u%M;
            }
        }
        if (res>mx) mx=res,ans=sum;
        else if (res==mx) ans=(ans+sum)%M;
    }
    cout << mx << ' ' << ans << endl;
    return 0;
}