#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int l = 0, r = n - 1;
	vector<int> pref, suff;
	while(l < r){
		if(s[l] == '0'){
			l++;
		}else if(s[r] == '1'){
			r--;
		}else{
			pref.emplace_back(l + 1);
			suff.emplace_back(r + 1);
			l++; r--;
		}
	}
	if(pref.empty()){
		cout << 0 << '\n';
		return;
	}
	cout << 1 << '\n';
	cout << 2*pref.size() << ' ';
	reverse(suff.begin(), suff.end());
	for(auto x : pref){
		cout << x << " ";
	}
	for(auto x : suff){
		cout << x << " ";
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}