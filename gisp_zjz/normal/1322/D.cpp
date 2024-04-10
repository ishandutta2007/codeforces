#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=4005;
const ll inf=1e18;
ll dp[maxn][maxn],s[maxn],c[maxn],tmp[maxn],ans;
int n,m,a[maxn];
void Max(ll &x,ll y){
    if (y>x) x=y;
}
int main(){
    cin >> n >> m; ans=0;
    for (int i=n;i;i--) cin >> a[i];
    for (int i=n;i;i--) cin >> c[i];
    for (int i=1;i<=n+m;i++) cin >> s[i];
    for (int i=1;i<=n+m;i++)
        for (int j=1;j<=n+m;j++)
            dp[i][j]=-inf;
    for (int i=1;i<=n;i++){
        int x=a[i]; ll val=s[x]-c[i];
        for (int j=i;j;j--) Max(dp[x][j],dp[x][j-1]+val);
        for (int j=x;j<=n+m;j++)
        for (int k=0;k<=i>>(j-x);k++)
            Max(dp[j+1][k/2],dp[j][k]+(k/2)*s[j+1]);
    }
    for (int i=1;i<=n+m+1;i++) Max(ans,dp[i][0]);
    cout << ans << endl;
    return 0;
}