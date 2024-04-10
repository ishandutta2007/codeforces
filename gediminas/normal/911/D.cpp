#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

using namespace std;
//sum
struct Node {
	Node *left = NULL, *right = NULL;
	int from, to;
	long long sum = 0;
	Node(int from, int to): from(from), to(to) {
		if (from == to) {
			return;
		}

		left = new Node(from, (from + to) / 2);
		right = new Node((from + to) / 2 + 1, to);
	}
	long long get(int p) {
		if (from == to) {
			return sum;
		}
		else {
			if (p <= left->to) {
				return sum + left->get(p);
			}
			else {
				return sum + right->get(p);
			}
		}
	}
	void update(int fr, int t, long long delta) {
		if (t < from or to < fr) {
			return;
		}

		if (fr <= from and to <= t) {
			sum += delta;
		}
		else {
			left->update(fr, t, delta);
			right->update(fr, t, delta);
		}
	}
};

/*input
3
1 2 3
2
1 2
2 3
*/
/*input
4
1 2 4 3
4
1 1
1 4
1 4
2 3
*/
int main () {
	int n;
	cin >> n;
	int prad = 0;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	Node med(0, n + 2);

	for (int i = 0; i < n; i++) {
		prad ^= med.get(a[i]) % 2;
		med.update(0, a[i], +1);
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int d = b - a + 1;

		if (d * (d - 1) / 2 % 2 == 1) {
			prad ^= 1;
		}

		cout << (prad == 0 ? "even" : "odd") << "\n";
	}


	return 0;
}