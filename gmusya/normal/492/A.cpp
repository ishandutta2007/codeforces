#include <iostream>
#include <vector>

using namespace std;

int main() {
	int cnt = 0;
	int x = 0;
	int r = 0;
	int n;
	cin >> n;
	while (r <= n) {
		cnt++;
		x += cnt;
		r += x;
	}
	cout << cnt - 1;
	return 0;
}