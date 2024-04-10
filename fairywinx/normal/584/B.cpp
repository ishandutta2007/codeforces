#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
// #include <algorithm>

#define int long long
#define pb emplace_back

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif
}

const int MOD = 1e9 + 7;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	int z = pow(a, b / 2);
	if (b % 2 == 0)
		return (z * z) % MOD;
	else 
		return (z * z * a) % MOD;
}

signed main() {
	setup();

	int n;
	cin >> n;
	cout << (pow(3, 3 * n) - pow(7, n) + MOD) % MOD;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif	
}