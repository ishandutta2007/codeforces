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
int k;
ll n,m,a[maxn],b[maxn];
bool check(ll n,ll m){
    ll tot=0;
    for (int i=0;i<k;i++){
        if (a[i]>=m*2) b[i]=a[i]/m; else b[i]=0;
        tot+=b[i];
    }
    sort(b,b+k);
    if (b[k-1]==2&&n%2==1) return 0;
    return tot>=n;
}
void solve(){
    cin >> n >> m >> k;
    for (int i=0;i<k;i++) cin >> a[i];
    if (check(n,m)||check(m,n)) puts("Yes"); else puts("No");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}