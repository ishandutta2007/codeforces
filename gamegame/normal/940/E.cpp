#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c;
multiset<int>s;
int a[100001];
ll dp[100001];
ll pf[100001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> c;
	for(int i=1; i<=n ;i++){
		int x;
		cin >> x;
		a[i]=x;
		dp[i]=dp[i-1]+x;
		pf[i]=pf[i-1]+x;
		if(i>c){
			s.erase(s.find(a[i-c]));
		}
		s.insert(a[i]);
		if(i>=c){
			dp[i]=min(dp[i],dp[i-c]+pf[i]-pf[i-c]-*s.begin());
		}
	}
	cout << dp[n] << endl;
}