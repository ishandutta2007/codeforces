#include<iostream>

using namespace std;

int n;
char c[400][400];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> c[i];
	bool good = c[0][0] != c[0][1];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j || i + j == n - 1) {
				if(c[i][j] != c[0][0]) good = false;
			} else {
				if(c[i][j] != c[0][1]) good = false;
			}
		}
	}
	cout << (good ? "YES" : "NO") << '\n';
}