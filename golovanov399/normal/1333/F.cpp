#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 555555;
int erat[N];
vector<int> primes;

vector<int> divs[N];
char used[N];

int getMaxUsed(int n) {
	int res = 0;
	for (int d : divs[n]) {
		if (used[d]) {
			res = d;
		}
	}
	return res;
}

int main() {
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (p > erat[i] || p * i >= N) {
				break;
			}
			erat[i * p] = p;
		}
	}

	int n = nxt();
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			divs[j].push_back(i);
		}
	}

	used[1] = 1;
	int cur = 1;
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int p : primes) {
			if (i * p > n) {
				break;
			}
			if (getMaxUsed(i * p) > i) {
				continue;
			}
			ans[++cur] = i;
			for (int d : divs[i * p]) {
				used[d] = 1;
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}