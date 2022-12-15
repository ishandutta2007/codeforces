#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int a[ms];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int big = s.size();
	for(char c = 'a'; c <= 'z'; c++) {
		for(int i = big; i > 0; i--) {
			if(s[i-1] == c) {
				//cout << i << ' ' << big << ' ' << char(c) << endl;
				a[i] = !a[i];
				a[i-1] = !a[i-1];
				big = i - 1;
			}
		}
	}
	for(int i = 1; i <= s.size(); i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}