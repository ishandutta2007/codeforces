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
int n,inv[maxn],a[maxn],b[maxn];
void add(int &x,int y){
    x+=y; if (x>=M) x-=M;
}
void solve(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) b[i]=a[i];
    sort(a+1,a+n+1);
    int cnt=0;
    for (int i=1;i<=n;i++) if (a[i]<b[i]) ++cnt;
    int ans=0;
    int res=1ll*n*(n-1)/2%M;
    for (int i=1;i<=cnt;i++) add(ans,1ll*res*inv[i]%M*inv[i]%M);
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    int _; cin >> _;
    while (_--) solve();
}