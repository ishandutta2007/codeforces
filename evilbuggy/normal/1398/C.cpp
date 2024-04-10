#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
	int n; cin>>n;
	string s; cin>>s;
	map<int, int> mp;
	int sum = 0;
	ll ans = 0;
	mp[0] = 1;
	for(int i = 1; i <= n; i++){
		int x = s[i - 1] - '0';
		sum += x;
		if(mp.count(sum - i))ans += mp[sum - i];
		mp[sum - i]++;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int t; cin>>t;
	while(t--)solve();

	return 0;
}