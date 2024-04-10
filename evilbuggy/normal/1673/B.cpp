#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		set<char> t;
		for(auto ch : s){
			t.insert(ch);
		}
		bool flg = true;
		int n = (int)s.size();
		int m = (int)t.size();
		for(int i = m; i < n; i++){
			if(s[i] != s[i - m]){
				flg = false;
				break;
			}
		}
		if(flg){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}

	return 0;
}