#include <bits/stdc++.h>
using namespace std;

int paint[2][2];
int board[2];

int main() {
	for(int i = 0; i < 2; i++) cin >> board[i];
	for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) cin >> paint[i][j];
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < 2; k++) {
				//cout << i << ' ' << j << ' ' << !i << ' ' << !j << endl;
				if(paint[0][i] + paint[1][j] <= board[k] && max(paint[0][!i], paint[1][!j]) <= board[!k]) {
					cout << "YES\n";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
	return 0;
}