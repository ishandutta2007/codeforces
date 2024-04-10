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
int kase=0;
int n,a[maxn];
void solve(){  
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans=a[n]-a[1];
    for (int i=1;i<n;i++) ans=max(ans,a[n]-a[i]);
    for (int i=n;i>1;i--) ans=max(ans,a[i]-a[1]);
    for (int i=1;i<n;i++) ans=max(ans,a[i]-a[i+1]);
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}