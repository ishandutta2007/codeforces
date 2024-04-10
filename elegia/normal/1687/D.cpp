#include <cmath>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;

const int _ = 1000005;

ull a[_], b[_], ta[_], tb[_];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> a[i];
		// a[i] = i;
		b[i] = a[i];
	}
	int n = 1;
	ull ans = 0;
	while (true) {
		{
			int tmp = 0;
			while (n * (ull)n <= a[1]) ++n; --n;
			int tn = n;
			for (int i = 1; i <= N; ++i) {
				if (i == 1 || a[i] - b[i - 1] > tn) {
					ta[++tmp] = a[i]; tb[tmp] = b[i];
				} else tb[tmp] = b[i];
				while (tn * (ull)tn <= b[i]) ++tn; --tn;
			}
			copy(ta + 1, ta + tmp + 1, a + 1);
			copy(tb + 1, tb + tmp + 1, b + 1);
			N = tmp;
		}
		ull up = 0;
		int tn = n;
		// cerr << N << '\n';
		for (int i = 1; i <= N; ++i) {
			// cerr << a[i] << ", " << b[i] << ": " << flush;
			while (tn * (ull)tn <= a[i]) ++tn; --tn;
			// cerr << tn * (ull)tn << " " << tn * (1ULL + tn) << '\n';
			if (b[i] > tn * (tn + 1ULL)) {
				int gn = max(int(b[i] - a[i]), tn + 1);
				up = max(up, gn * (ull)gn - a[i]);
			}
		}
		if (up == 0) break;
		ans += up;
		for (int i = 1; i <= N; ++i) { a[i] += up; b[i] += up; }
	}
	cout << ans << '\n';
	
	return 0;
}