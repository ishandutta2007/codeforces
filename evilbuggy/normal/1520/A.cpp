#include <bits/stdc++.h>
using namespace std;

bool check(string s){
	int n = s.size();
	for(int i = 0; i < n; i++){
		for(int j = i + 2; j < n; j++){
			if(s[i] == s[j]){
				for(int k = i + 1; k < j; k++){
					if(s[i] != s[k])return false;
				}
			}
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		if(check(s))cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}