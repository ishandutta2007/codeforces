#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	ll x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll ans=abs(x2-x1)+abs(y2-y1);
	if(x1!=x2 && y1!=y2) ans+=2;
	//if(y1!=y2) ans++;
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}