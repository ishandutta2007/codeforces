#include<bits/stdc++.h>
using namespace std;

const string K[3]  = { 
"qwertyuiop",
"asdfghjkl;",
"zxcvbnm,./" };

int main() {
	char d; string s;
	cin >> d >> s;
	int v = (d == 'R') ? -1 : 1;
	for(char c : s) {
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 10; j++) {
				if(K[i][j] == c) {
					cout << K[i][j + v];
				}
			}
		}
	}
	cout << '\n';
	return 0;
}