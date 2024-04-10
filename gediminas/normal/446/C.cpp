#include <bits/stdc++.h>

using namespace std;
/*input
4 4
1 2 3 4
1 1 4
2 1 4
1 2 4
2 1 3
*/
using namespace std;
const long long mod = 1000000009;
#define MOD(x) ((x)%mod)
const long long maxn = 300100;
long long fib[maxn];
//sum
struct Node {
	Node *left = NULL, *right = NULL;
	int from, to;
	long long sum = 0, lazya = 0, lazyb = 0;
	Node(int from, int to, long long mas[]): from(from), to(to) {
		if (from == to) {
			sum = mas[from];
			return;
		}

		left = new Node(from, (from + to) / 2, mas);
		right = new Node((from + to) / 2 + 1, to, mas);
		sum = MOD(left->sum + right->sum);
	}
	void fix() {
		long long k = to - from + 1;
		sum = MOD(sum + lazya * fib[k + 1] + lazyb * (fib[k + 2] - 1));

		if (from != to) {
			left->lazya = MOD(left->lazya + lazya);
			left->lazyb = MOD(left->lazyb + lazyb);
			long long lk = left->to - from + 1;
			right->lazya = MOD(right->lazya + lazya * fib[lk] + lazyb * fib[lk + 1]);
			right->lazyb = MOD(right->lazyb + lazya * fib[lk + 1] + lazyb * fib[lk + 2]);
		}

		lazya = lazyb = 0;
	}
	long long get(int fr, int t) {
		fix();

		if (fr <= from and to <= t) {
			return sum;
		}

		if (t < from or to < fr) {
			return 0;
		}

		return MOD(left->get(fr, t) + right->get(fr, t));
	}
	void update(int fr, int t) {
		fix();

		if (t < from or to < fr) {
			return;
		}

		if (fr <= from and to <= t) {
			lazya = MOD(lazya + fib[from - fr + 2]);
			lazyb = MOD(lazyb + fib[from - fr + 3]);
			fix();
		}
		else {
			left->update(fr, t);
			right->update(fr, t);
			sum = MOD(left->sum + right->sum);
		}
	}
	~Node() {
		if (left) {
			delete left;
			delete right;
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	fib[0] = 1;
	fib[1] = 0;

	for (int i = 2; i < maxn; ++i) {
		fib[i] = MOD(fib[i - 1] + fib[i - 2]);
	}

	int n, m;
	cin >> n >> m;
	long long prad[n];

	for (int i = 0; i < n; ++i) {
		cin >> prad[i];
	}

	Node med(0, n - 1, prad);

	for (int i = 0; i < m; ++i) {
		int t, l, r;
		cin >> t >> l >> r;
		l--, r--;

		if (t == 1) {
			med.update(l, r);
		}
		else {
			cout << med.get(l, r) << "\n";
		}
	}
}