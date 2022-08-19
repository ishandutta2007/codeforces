#include<bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	int a, b; cin >> a >> b;
	int d = b-a;
	int p = b;
	for (int i = 2; i < N; i++) {
		int c; cin >> c;
		if (c - p != d) d = 0;
		p = c;
	}
	cout << p + d << '\n';

	return 0;
}