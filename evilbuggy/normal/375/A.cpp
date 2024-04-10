#include <bits/stdc++.h>
using namespace std;

vector<int> frequency(string s){
	vector<int> ret(10);
	for(int i = 0; i < (int)s.size(); i++){
		ret[s[i] - '0']++;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	vector<int> f = frequency(s);

	string tail = "";
	for(int d = 0; d < 10; d++){
		int s = (d == 1 || d == 6 || d == 8 || d == 9);
		for(int i = s; i < f[d]; i++){
			tail += char('0' + d);
		}
	}

	for(auto head : {"1689", "1698", "1869", "1896", "1968", "1986", "6198"}){
		string ans = head + tail;
		
		int rem = 0;
		for(auto ch : ans){
			rem = (rem*10 + ch - '0')%7;
		}
		if(rem == 0){
			cout << ans << '\n';
			exit(0);
		}
	}
	assert(false);

	return 0;
}