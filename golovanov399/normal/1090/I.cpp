#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline long long nxt() {
	long long x;
	scanf("%lld", &x);
	return x;
}

const long long inf = 5000002734827349827ll;

long long getAnswer(const vector<int>& a) {
	int n = a.size();
	long long ans = inf;
	long long cur_min = inf;
	for (int i = 0; i < n; ++i) {
		if (cur_min < a[i]) {
			ans = min(ans, cur_min * a[i]);
		}
		cur_min = min<long long>(cur_min, a[i]);
	}
	return ans;
}

void solve() {
	vector<unsigned int> b(2);
	long long n = nxt(), l = nxt(), r = nxt(); unsigned int x = nxt(), y = nxt(), z = nxt(); b[0] = nxt(); b[1] = nxt();
	b.resize(n);
	for (int i = 2; i < n; ++i) {
		b[i] = (b[i - 2] * x + b[i - 1] * y + z);
	}
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (long long)(b[i]) % (r - l + 1) + l;
	}

	long long ans = inf;
	long long cur_min = inf;
	vector<int> positive, negative;
	for (int i = 0; i < n; ++i) {
		if (cur_min < a[i]) {
			ans = min(ans, cur_min * a[i]);
		}
		cur_min = min<long long>(cur_min, a[i]);
		if (a[i] >= 0) {
			positive.push_back(a[i]);
		} else {
			negative.push_back(a[i]);
		}
	}
	reverse(all(negative));
	for (int& x : negative) {
		x *= -1;
	}
	ans = min({ans, getAnswer(positive), getAnswer(negative)});
	if (ans == inf) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}