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
		int c0 = s[0] - 'a';
		int c1 = s[1] - 'a';
		if(c0 > c1){
			cout << 25*c0 + c1 + 1 << '\n';
		}else{
			cout << 25*c0 + c1 + 0 << '\n';
		}
	}

	return 0;
}