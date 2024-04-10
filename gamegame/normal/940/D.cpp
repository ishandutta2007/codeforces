#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;

int n,m;
ll a[N];
char b[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	ll l=-1e9;
	ll r=1e9;
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		if(i<5) continue;
		int s=0;
		ll mn=1e9;
		ll mx=-1e9;
		for(int j=i-4; j<=i ;j++){
			mn=min(mn,a[j]);
			mx=max(mx,a[j]);
			s+=b[j]-48;
		}
		s-=b[i]-48;
		if(s==0 && b[i]=='1'){
			l=max(l,mx+1);
		}
		if(s==4 && b[i]=='0'){
			r=min(r,mn-1);
		}
	}
	if(l>r) l=r;
	cout << l << ' ' << r << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) solve();
	solve();
}