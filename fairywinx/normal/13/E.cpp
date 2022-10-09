#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
// #include <algorithm>
#include <queue>

using namespace std;

// #define int long long

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

const int N = 1e5 + 228;
const int K = 318;

int n;
pair<int, int> bad = {-1, -1};

int a[N];
pair<int, int> b[K][K];

void rebuild(int k) {
	for(int j = 0; j < K; ++j)
		b[k][j] = bad;
	int r = min(K * (k + 1), n), l = K * k; 
	for(int j = r - 1; j >= l; --j) {
		if (j + a[j] >= r) {
			b[k][j % K] = {1, j};
			continue;
		}
		b[k][j % K] = {b[k][(j + a[j]) % K].first + 1, b[k][(j + a[j]) % K].second};
	}
}

pair<int, int> get(int k) {
	int ans = 0;
	int x = k;
	while(x < n) {
		ans += b[x / K][x % K].first;
		int z = b[x / K][x % K].second;
		if (z + a[z] >= n)
			return {z, ans};
		x = z + a[z];
	}
}

signed main() {
	setup();

	int m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int k = 0; k < K; ++k) 
		rebuild(k);

	for(int i = 0; i < m; ++i) {
		int c;
		cin >> c;
		if (c == 1) {
			int z;
			cin >> z;
			auto o = get(z - 1);
			cout << o.first + 1 << ' ' << o.second << '\n';
		}
		else {
			int u, v;
			cin >> u >> v;
			a[u - 1] = v;
			rebuild((u - 1) / K);
		}
	}

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}