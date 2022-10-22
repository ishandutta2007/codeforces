#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int n = s.length();
	int l, r;
	for (l = 0; l < n; l++){
		if (s[l] == '[') break;
	}
	for (r = n - 1; r >= 0; r--){
		if (s[r] == ']') break;
	}
	if (l == n || r == -1 || l > r){
		cout << -1 << endl;
		return 0;
	}
	int l1, r1;
	for (l1 = l + 1; l1 < r; l1++){
		if (s[l1] == ':') break;
	}
	for (r1 = r - 1; r1 > l; r1--){
		if (s[r1] == ':') break;
	}
	if (l1 == r || r1 == r || l1 >= r1){
		cout << -1 << endl;
		return 0;
	}
	int ans = 4;
	for (int i = l1; i <= r1; i++){
		ans += s[i] == '|';
	}
	cout << ans << endl;
	return 0;
}