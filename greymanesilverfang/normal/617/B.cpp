#include <iostream>
using namespace std;
int main() {
	int last = 0; long long ans = 1;
	int n; cin >> n; ++n;
	while (--n) {
		int x; cin >> x;
		ans *= x && last ? last - n : 1;
		last = x ? n : last;
	}
	cout << (last ? ans : last);
}