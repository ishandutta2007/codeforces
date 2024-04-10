#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
int n;
ll a[N];
ll b[N];
ll p1[N];
ll p2[N];
ll ans=0;
void solve2(int m,ll t){//count CC...CPCPCPCPP..P for sumP-sumC>t
	ll sum=0;
	for(int i=1; i<=m ;i++){
		p1[i]=p1[i-1]+b[i];
		if(i==1) p2[i]=b[i];
		else p2[i]=p2[i-2]+b[i];
	}
	sum=p1[m];
	for(int i=1; i<m ;i++){//position of last C
		int d=i%2;
		int r=(i+2+d)/2;
		int l=1;
		while(l!=r){
			int mid=(l+r)/2;
			int pos=2*mid-d;
			ll sumC=p1[pos]+p2[i]-p2[pos];
			ll sumP=sum-sumC;
			if(sumP-sumC<=t) r=mid;
			else l=mid+1;
		}
		//cout << i << ' ' << l << endl;
		ans+=l-1;
	}
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	if(n==1){
		cout << "1\n";
		return;
	}
	if(n==2){
		if(a[1]==a[2]) cout << "1\n";
		else cout << "2\n";
		return;
	}
	ans=0;
	for(int i=1; i<=n ;i++) b[i]=a[i];
	solve2(n,0);
	//cout << "w1 " << ans << endl;
	for(int i=1; i<=n-1 ;i++) b[i]=a[i];
	solve2(n-1,a[n]);
	//cout << "w2 " << ans << endl;
	for(int i=2; i<=n ;i++) b[i-1]=a[i];
	solve2(n-1,-a[1]);
	//cout << "w3 " << ans << endl;
	for(int i=2; i<=n-1 ;i++) b[i-1]=a[i];
	solve2(n-2,a[n]-a[1]);
	//cout << "w4 " << ans << endl;
	ll sum=0;
	for(int i=1; i<=n ;i++) sum+=a[i];
	if(sum>0) ans++;
	for(int i=n; i>=1 ;i--){
		sum-=2*a[i];
		if(sum>0) ans++;
	}
	ans%=998244353;
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}