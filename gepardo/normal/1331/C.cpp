#include <iostream>

using namespace std;

int main() {
	int x; cin >> x;
	
	auto g = [&](int w) { return (x >> w) & 1; };
	
	int ans = 0;
	for (int t : {5, 0, 2, 3, 1, 4}) {
		ans <<= 1;
		ans |= g(t);
	}
	cout << ans << endl;
}