#include<bits/stdc++.h>
#define maxn 90
#define eps 1e-7

using namespace std;
typedef long long ll;
const double inf=1e16;
struct node{
    ll x,y;
}a[maxn];
bool cmp(node u,node v){
    return u.x>v.x;
}
ll n,m,k;
bool f[maxn];
double l,r,mid,dp[maxn][maxn],b[maxn],c[maxn],sum[maxn];

bool check(double x){
    for (ll i=1;i<=n;i++) c[i]=x*a[i].y-(double)a[i].x;
    for (ll i=0;i<=n;i++) for (ll j=0;j<=n;j++) dp[i][j]=-inf;
    dp[0][0]=0; ll p,q; p=1;
    while (p<=n){
        q=p+1; while (q<=n&&a[q].x==a[p].x) q++;
        sort(c+p,c+q); k=q-p;
        for (ll i=1;i<=k;i++) sum[i]=sum[i-1]+c[q-i];
        for (ll i=0;i<=n;i++)
            for (ll j=0;j<=min(i,k);j++)
                dp[q-1][i-j+(k-j)]=max(dp[q-1][i-j+(k-j)],dp[p-1][i]+sum[k-j]);
        //cout << q<<' '<<dp[q-1][2] << endl;
        p=q;
    }
    for (ll i=0;i<=n;i++) if (dp[n][i]>0.0) return true;
    return false;
}

int main(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i].x;
    for (ll i=1;i<=n;i++) cin >> a[i].y;
    sort(a+1,a+n+1,cmp);
    l=0.0; r=2e8;
    //cout << check(8.0) << endl;

    while (r-l>eps){
        mid=(l+r)/2;
        if (check(mid)) r=mid; else l=mid;
    }
    //cout << mid << endl;
    printf("%lld\n",(long long)(mid*1000+0.9999));
    return 0;
}