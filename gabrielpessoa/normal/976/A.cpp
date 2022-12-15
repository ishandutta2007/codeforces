#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n; string s;
	cin >> n >> s;
	cout << s[0];
	for(int i = 1; i < n; i++) {
		if(s[i] == '0') cout << s[i];
	}
	cout << '\n';
}