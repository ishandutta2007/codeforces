#include <bits/stdc++.h>
using namespace std;

bool order(int a, int b, int c) {
	return (a < b && b < c) || (a > b && b > c);
}

void test_case() {
	int xa, ya, xb, yb, xf, yf;
	cin >> xa >> ya >> xb >> yb >> xf >> yf;
	int answer = abs(xa - xb) + abs(ya - yb);
	for(int i = 0; i < 2; ++i) {
		if(xa == xb && xb == xf) {
			if(order(ya, yf, yb)) {
				answer += 2;
			}
		}
		swap(xa, ya);
		swap(xb, yb);
		swap(xf, yf);
	}
	cout << answer << "\n";
}

int main() {
	int T;
	cin >> T;
	for(int i = 0; i < T; i++) {
		test_case();
	}
}