#include <bits/stdc++.h>
using namespace std;
#define MAX 303030
#define MOD 1000000007
#define pb push_back
#define ln '\n'
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T-- > 0) {
		char str[MAX];
		int N;
		cin >> N;
		cin >> str;
		int i;
		int prev = -1;
		int a;
		for (i = 0; i < N; i++) {
			if (str[i] == '0') a = 0;
			else a = 1;
			if (prev == -1) {
				cout << 1;
				prev = a + 1;
			}
			else if (prev == 0) {
				cout << 1;
				if (a == 0) {
					prev = 1;
				}
				else {
					prev = 2;
				}
			}
			else if (prev == 1) {
				if (a == 0) {
					cout << 0;
					prev = 0;
				}
				else {
					cout << 1;
					prev = 2;
				}
			}
			else {
				if (a == 0) {
					cout << 1;
					prev = 1;
				}
				else {
					cout << 0;
					prev = 1;
				}
			}
		}
		cout << ln;
	}
	return 0;
}