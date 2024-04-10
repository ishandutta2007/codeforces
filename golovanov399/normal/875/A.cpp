#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int getSum(int n) {
	int x = 0;
	while (n) {
		x += n % 10;
		n /= 10;
	}
	return x;
}

int main() {
	int n = nxt();
	vector<int> ans;
	for (int sum = 1; sum <= 81; ++sum) {
		if (n <= sum) {
			break;
		}

		if (getSum(n - sum) == sum) {
			ans.push_back(n - sum);
		}
	}

	printf("%d\n", (int)ans.size());
	reverse(all(ans));
	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}