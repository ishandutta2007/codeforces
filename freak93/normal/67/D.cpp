#include <iostream>

using namespace std;

const int maxn = 1000005;

int deq[maxn], x[maxn], y[maxn], v, step, i, j, n, p;

int main() {
	cin >> n;
	for (i = 1; i <= n; ++i)
		cin >> v, x[v] = i;
	for (i = 1; i <= n; ++i)
		cin >> v, y[i] = x[v];
	p = 0;
	for (i = 1; i <= n; ++i) {
		for (step = 1; step < p; step <<= 1);
		for (j = 0; step; step >>= 1)
			if (j + step <= p && y[deq[j + step]] > y[i])
				j += step;
		if (j == p)
			++p;
		deq[j + 1] = i;
	}
	cout << p << "\n";
}