#include <bits/stdc++.h>
using namespace std;

bool test_case() {
	string s;
	cin >> s;
	int n = s.length();
	int L = -1, R = -1;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'a') {
			L = R = i;
			break;
		}
	}
	if(L == -1) {
		return false;
	}
	for(int i = 1; i < n; i++) {
		char nxt = 'a' + i;
		if(L != 0 && s[L-1] == nxt) {
			L--;
		}
		else if(R != n-1 && s[R+1] == nxt) {
			R++;
		}
		else {
			return false;
		}
	}
	return true;
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		cout << (test_case() ? "YES\n" : "NO\n");
	}
}