#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct StackMax {
	vector<int> vals;
	vector<int> maxs;

	void push_back(int x) {
		int last = maxs.empty() ? INT_MIN : maxs.back();
		vals.push_back(x);
		maxs.push_back(max(x, last));
	}

	int get() const {
		return maxs.empty() ? INT_MIN : maxs.back();
	}

	int back() const {
		return vals.back();
	}

	void pop_back() {
		vals.pop_back();
		maxs.pop_back();
	}

	bool empty() const {
		return vals.empty();
	}
};

struct QueueMax {
	StackMax left, right;

	void refill() {
		while (!right.empty()) {
			int x = right.back();
			right.pop_back();
			left.push_back(x);
		}
	}

	void push(int x) {
		right.push_back(x);
	}

	void pop() {
		if (left.empty()) {
			refill();
		}
		left.pop_back();
	}

	int get() const {
		return max(left.get(), right.get());
	}
};

const int N = 1111111;
long long answer[N];

void add(int pos, long long x) {
	answer[pos] += x;
	answer[pos + 1] -= x;
}

void add(int l, int r, long long x) {
	answer[l] += x;
	answer[r] -= x;
}

void handle(int w) {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	if (2 * n <= w) {
		int x = 0;
		for (int i = 0; i < n; ++i) {
			x = max(x, a[i]);
			add(i, x);
		}
		x = 0;
		for (int i = 0; i < n; ++i) {
			x = max(x, a[n - 1 - i]);
			add(w - 1 - i, x);
		}
		add(n, w - n, x);
		return;
	}

	QueueMax q;
	int l = -1 - w + n;
	int r = -1;
	for (int i = 0; i < w; ++i) {
		while (r < i) {
			++r;
			if (r < n) {
				q.push(a[r]);
			}
		}
		while (l < i - w + n) {
			if (l >= 0) {
				q.pop();
			}
			++l;
		}
		int x = q.get();
		if (l < 0 || r >= n) {
			x = max(x, 0);
		}
		add(i, x);
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), w = nxt();
	for (int i = 0; i < n; ++i) {
		handle(w);
	}

	for (int i = 1; i < w; ++i) {
		answer[i] += answer[i - 1];
	}
	for (int i = 0; i < w; ++i) {
		printf("%lld ", answer[i]);
	}
	printf("\n");

	return 0;
}