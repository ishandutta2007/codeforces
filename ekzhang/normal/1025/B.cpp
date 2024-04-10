#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 150013
int N;
set<int> s;

void factor(int n) {
	for (int d = 2; d * d <= n; d++) {
		if (n % d == 0) {
			s.insert(d);
			while (n % d == 0)
				n /= d;
		}
	}
	if (n != 1)
		s.insert(n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	int a, b;
	cin >> a >> b;
	factor(a);
	factor(b);
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		set<int> s2;
		for (int x : s) {
			if (a % x == 0 || b % x == 0)
				s2.insert(x);
		}
		s = s2;
	}

	cout << (s.empty() ? -1 : *s.begin()) << endl;
	return 0;
}