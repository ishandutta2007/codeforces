#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t;
	cin >> s >> t;
	int n = (int)s.size();
	int m = (int)t.size();
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	for(int i = 0; i < n && i < m; i++){
		if(s[i] != t[i]){
			cout << n + m - 2*i << '\n';
			exit(0);
		}
	}
	cout << max(n, m) - min(n, m) << '\n';

	return 0;
}