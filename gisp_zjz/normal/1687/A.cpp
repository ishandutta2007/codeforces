#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
ll a[maxn],ans,sum[maxn];
int _,n,k,m;
void solve(){
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    if (k>=n) ans=sum[n];
    else {
        ans=0;
        for (int i=k;i<=n;i++) ans=max(ans,sum[i]-sum[i-k]);
    }
    m=min(n,k);
    ans+=1ll*(k-1)*m-1ll*m*(m-1)/2;
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--) solve();
}