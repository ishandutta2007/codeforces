#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	int cnt = 1;
	cin >> n >> k;
	int t = 240 - k;
	while (t >= cnt * 5) {
		t -= cnt * 5;
		cnt++;
	}
	cout << min(n,cnt - 1);
	return 0;
}