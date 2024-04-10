#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
ll s;
ll a[100001];
void solve(){
	cin >> n >> s;
	ll sum=0;
	ll mx=0;
	int mid=0;
	int ans=0;
	int best=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(mx<a[i]) mx=a[i],mid=i;
		sum+=a[i];
		if(sum<=s && best<i) ans=0,best=i;
		if(sum-mx<=s && best<i-1) ans=mid,best=i-1;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		solve();
	}
}