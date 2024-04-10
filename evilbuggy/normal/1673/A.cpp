#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		int sum = 0;
		for(auto ch : s){
			sum += ch - 'a' + 1;
		}
		if(s.size()&1){
			int val = sum - 2*min(s.front() - 'a' + 1, s.back() - 'a' + 1);
			if(val > 0){
				cout << "Alice " << val << '\n';
			}else{
				cout << "Bob " << -val << '\n';
			}
		}else{
			cout << "Alice " << sum << '\n';
		}
	}

	return 0;
}