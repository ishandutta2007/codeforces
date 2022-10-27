#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int sum = 0;
		for(int i = 0; i < 3; i++){
			sum += s[i] - '0';
			sum -= s[i + 3] - '0';
		}
		if(sum == 0){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}

	return 0;
}