#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <iomanip>

using namespace std;

// #pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

// #include <algorithm>
#define int long long
// #define _GLIBCXX_DEBUG

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif

	srand(time(0));
}

const int N = 1e5 + 228;

vector<int> g[N];

double dfs(int v, int p, int k) {
	int kol = 0;
	double sum = 0;
	for(auto i: g[v]) {
		if (i != p)  
			sum += dfs(i, v, k + 1), ++kol;
	}
	if (kol == 0)
		return k;
	else
		return (double) sum / kol;
}

signed main() {
	setup();

	int n;
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	cout << setprecision(10) << dfs(0, -1, 0);
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}