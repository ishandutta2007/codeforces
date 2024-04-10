#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	string t;
	cin >> t;
	vector<int> freq(26);
	for(int i = 0; i < (int)s.size(); i++){
		freq[s[i] - 'a']++;
	}
	if(freq[0] == 0 || freq[1] == 0 || freq[2] == 0 || t != "abc"){
		for(int i = 0; i < 26; i++){
			while(freq[i]--)cout << char('a' + i);
		}
		cout << '\n';
	}else{
		for(int i = 0; i < 26; i++){
			int j = i;
			if(i == 1)j = 2;
			if(i == 2)j = 1;
			while(freq[j]--)cout << char('a' + j);
		}
		cout << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}