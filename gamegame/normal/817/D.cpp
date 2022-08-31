#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
ll a[1000001];
int l1[1000001],l2[1000001];
int r1[1000001],r2[1000001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) solve();
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		l1[i]=l2[i]=0;
		r1[i]=r2[i]=n+1;
	}
	stack<int>s;
	for(int i=1; i<=n ;i++){
		while(!s.empty() && a[s.top()]<a[i]){
			r1[s.top()]=i;s.pop();
		}
		if(!s.empty()) l1[i]=s.top();
		s.push(i);
	}
	while(!s.empty()) s.pop();
	for(int i=1; i<=n ;i++){
		while(!s.empty() && a[s.top()]>a[i]){
			r2[s.top()]=i;s.pop();
		}
		if(!s.empty()) l2[i]=s.top();
		s.push(i);
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		ans+=1LL*(r1[i]-i)*(i-l1[i])*a[i];
		ans-=1LL*(r2[i]-i)*(i-l2[i])*a[i];
	}
	cout << ans << '\n';
	
}