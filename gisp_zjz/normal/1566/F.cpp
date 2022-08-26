#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll inf=1e16;
typedef pair<ll,ll>pi;
int _,n,m,k;
ll l[maxn],r[maxn],p[maxn],L[maxn],R[maxn],dp[maxn][4];
pi a[maxn],b[maxn];
bool ct(pi u,pi v){//u contain v
    return u.F<=v.F&&u.S>=v.S;
}
void Min(ll &x,ll y){if (y<x)x=y;}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%lld",&p[i]);
        sort(p+1,p+n+1);
        for (int i=1;i<=k;i++) scanf("%lld%lld",&a[i].F,&a[i].S);
        sort(a+1,a+k+1);
        p[0]=-inf; p[n+1]=inf;
        m=0;
        for (int i=1;i<=k;i++){
            auto gt=lower_bound(p+1,p+n+2,a[i].F);
            if ((*gt)<=a[i].S) continue;
            while (m>0&&ct(b[m],a[i])) m--;
            b[++m]=a[i];
        }
        if (!m){puts("0");continue;}
        int po=0;
        for (int i=1;i<=m;i++){
            while (po+1<=n&&p[po+1]<=b[i].F) ++po;
            L[i]=po; l[i]=b[i].F-p[po];
        }
        po=n+1;
        for (int i=m;i>=1;i--){
            while (po-1>=1&&p[po-1]>=b[i].S) --po;
            R[i]=po; r[i]=p[po]-b[i].S;
        }
        for (int i=1;i<=m;i++) assert(L[i]+1==R[i]);
        //for (int i=1;i<=m;i++)cout<<b[i].F<<' '<<b[i].S<<' '<<l[i]<<' '<<r[i]<<endl;
        dp[1][0]=r[1]*2;
        dp[1][1]=r[1];
        dp[1][2]=l[1]*2;
        dp[1][3]=l[1];
        for (int i=2;i<=m;i++){
            if (L[i]!=L[i-1]){
                ll tmp=min(dp[i-1][2],dp[i-1][3]);
                dp[i][2]=tmp+l[i]*2;
                dp[i][3]=tmp+l[i];
            } else {
                dp[i][2]=dp[i-1][2]+(b[i].F-b[i-1].F)*2;
                dp[i][3]=dp[i-1][3]+(b[i].F-b[i-1].F);
            }
            if (R[i]!=R[i-1]){
                ll tmp=min(dp[i-1][0],dp[i-1][1]);
                dp[i][0]=tmp+r[i]*2;
                dp[i][1]=tmp+r[i];
            } else {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
            }
            if (L[i]==R[i-1]){
                Min(dp[i][2],dp[i-1][1]+l[i]*2);
                Min(dp[i][3],dp[i-1][0]+l[i]);
            } else if (L[i]>R[i-1]){
                Min(dp[i][3],dp[i-1][1]+l[i]);
            }
            ll tmp=min(dp[i-1][2],dp[i-1][3]);
            Min(dp[i][0],tmp+r[i]*2);
            Min(dp[i][1],tmp+r[i]);
        }
        ll ans=inf;
        for (int i=0;i<4;i++) Min(ans,dp[m][i]);
        printf("%lld\n",ans);
    }
    return 0;
}