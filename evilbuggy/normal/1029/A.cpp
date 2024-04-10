#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	string t;
	cin >> n >> k >> t;
	
	int len = 0;
	for(int i = 1; i < n; i++){
		if(t.substr(0, i) == t.substr(n - i)){
			len = i;
		}
	}
	cout << t;
	for(int i = 1; i < k; i++){
		cout << t.substr(len);
	}
	cout << '\n';

	return 0;
}