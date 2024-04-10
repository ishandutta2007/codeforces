#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ll k, n, w;
	cin >> k >> n >> w;
	ll answer = max((ll) 0, w * (w + 1) / 2 * k - n);
	cout << answer;
		return 0;
}