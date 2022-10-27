#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
	string s; cin>>s;
	vector<pair<int, char> > vec;
	vector<int> a;
	for(auto ch : s){
		if(vec.empty() || vec.back().second != ch)vec.emplace_back(1, ch);
		else vec.back().first++;
	}
	for(auto x : vec){
		if(x.second == '1')a.push_back(x.first);
	}
	sort(a.rbegin(), a.rend());
	int ans = 0;
	for(int i = 0; i < a.size(); i += 2){
		ans += a[i];
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