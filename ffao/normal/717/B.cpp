#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
struct CompressedVector {
	int size = 0;
	int tam = 0;
	pair<int,int> v[1000];
	inline int at(int idx, int &hint) const {
		while (hint+1 < tam && v[hint+1].first == idx) hint++;
		return v[hint].second;
	}
	inline void push_back(int x) {
		++size;
		if (!tam || v[tam-1].second != x) v[tam++] = {size, x};
	}
};

CompressedVector dp;
int n, c0, c1;

void solve() {
	scanf("%d %d %d", &n, &c0, &c1);	

	dp.push_back(0);
	dp.push_back(c0+c1);

	int zero = 1;
	int zero_hint = 1;
	int one = 1;
	int one_hint = 1;
	long long zero_diff = c0+c1;
	long long one_diff = c0+c1;
	long long last_diff = c0+c1;

	for (int i = 3; i <= n; i++) {
		long long inc_one = one_diff + c1;
		long long inc_zero = zero_diff + c0;
		
		if (inc_zero < inc_one) {
			dp.push_back( inc_zero - last_diff );
			last_diff = inc_zero;
			zero++;
			zero_diff += dp.at( zero+1, zero_hint );
		}
		else {
			dp.push_back( inc_one - last_diff );
			last_diff = inc_one;
			one++;
			one_diff += dp.at( one+1, one_hint );
		}
	}

	long long ans = 0;
	long long diff = 0;
	int diff_hint = 1;
	for (int idx = 2; idx <= n; idx++) {
		diff += dp.at(idx, diff_hint);
		ans += diff;
	}

	printf("%lld\n", ans);
}

int main() {
    solve();
}