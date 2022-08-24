#include<iostream>
using namespace std;
typedef long long ll;
int n,k;
ll sum=0;
ll a[100001];
ll pref[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		int t;
		cin >> t;
		if(t==1) sum+=a[i],a[i]=0;
		pref[i]=pref[i-1]+a[i];
	}
	ll ans=0;
	for(int i=k; i<=n ;i++){
		ans=max(ans,sum+pref[i]-pref[i-k]);
	}
	cout << ans << endl;
}