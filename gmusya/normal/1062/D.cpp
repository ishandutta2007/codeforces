#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9;

int main() {
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 2 * i; j <= n; j += i) {
			int w = j / i;
			ans += 4 * w;
		}
	cout << ans;
	return 0;
}