#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	vector<int> f(26);
	
	cin >> s;
	for(auto c : s){
		f[c - 'A']++;
	}
	cin >> s;
	for(auto c : s){
		f[c - 'A']++;
	}
	cin >> s;
	for(auto c : s){
		f[c - 'A']--;
	}
	for(int i = 0; i < 26; i++){
		if(f[i] != 0){
			cout << "NO" << '\n';
			exit(0);
		}
	}
	cout << "YES" << '\n';

	return 0;
}