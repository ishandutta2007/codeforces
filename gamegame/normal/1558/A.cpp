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
	ll x,y;cin >> x >> y;
	if(x<y) swap(x,y);
	if((x+y)%2==0){
		ll mn=(x-y)/2;
		ll mx=(x+y)-mn;
		cout << (mx-mn)/2+1 << '\n';
		for(int i=mn; i<=mx ;i+=2) cout << i << ' ';
		cout << '\n';
	}
	else{
		ll mn=x-(x+y+1)/2;
		ll mx=(x+y)-mn;
		cout << (mx-mn)+1 << '\n';
		for(int i=mn; i<=mx ;i++) cout << i << ' ';
		cout << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}