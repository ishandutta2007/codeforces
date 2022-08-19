#include<iostream>

using namespace std;

int main() {
	int n, c;
	cin >>  n >> c;
	int x, y;
	cin >> y;
	int res = 0;
	for(int i = 1; i < n; i++ ) {
		x = y;
		cin >> y;
		int cnd = x - y - c;
		if(cnd > res) res = cnd;
	}
	cout << res << '\n';
	return 0;
}