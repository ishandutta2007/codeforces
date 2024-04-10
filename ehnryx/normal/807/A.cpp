#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

int main() {
	bool sorted = true;
	int n, a, b, ra, rb;
	cin >> n;
	cin >> ra >> rb;
	if (ra != rb)
		cout << "rated" << endl;
	else {
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			if (a != b) {
				break;
			}
			if (a > ra) {
				sorted = false;
			}
			ra = a;
			rb = b;
		}
		if (a != b) {
			cout << "rated" << endl;
		}
		else if (sorted) {
			cout << "maybe" << endl;
		}
		else
			cout << "unrated" << endl;
	}
	return 0;
}