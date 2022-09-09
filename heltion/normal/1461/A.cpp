#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	for(cin >> T; T; T -= 1){
		string s;
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < n; i += 1) s += 'a' + i % 3;
		cout << s << "\n";
	}
	return 0;
}