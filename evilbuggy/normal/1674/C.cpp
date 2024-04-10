#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		string t;
		cin >> t;
		if(t == "a"){
			cout << 1 << '\n';
			continue;
		}
		bool flg = false;
		for(auto ch : t){
			if(ch == 'a')flg = true;
		}
		if(flg){
			cout << -1 << '\n';
		}else{
			cout << (1LL << s.size()) << '\n';
		}
	}

	return 0;
}