#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	long long s = 0;
	long long m = 0;
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		s += a;
		if(a > m) m = a;
	}
	s += (n-1) - 1;
	s /= (n-1);
	if(m > s) s = m;
	cout << s << '\n';
	return 0;
}