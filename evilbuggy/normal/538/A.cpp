#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = (int)s.size();
	for(int i = 0; i < n; i++){
		for(int j = i; j <= n; j++){
			if(s.substr(0, i) + s.substr(j) == "CODEFORCES"){
				cout << "YES" << '\n';
				exit(0);
			}
		}
	}
	cout << "NO" << '\n';

	return 0;
}