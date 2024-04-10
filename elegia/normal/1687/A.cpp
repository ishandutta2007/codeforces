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



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<ull> A(N);
		for (int i = 0; i != N; ++i) cin >> A[i];
		ull ans = 0;
		if (K > N) {
			ans += (K - N) * (ull)N;
			K = N;
		}
		ans += K * (K - 1ULL) / 2;
		ull sum = 0, mx = 0;
		for (int i = 0; i != N; ++i) {
			sum += A[i];
			if (i >= K) sum -= A[i - K];
			mx = max(mx, sum);
		}
		ans += mx;
		cout << ans << '\n';
	}
	
	return 0;
}