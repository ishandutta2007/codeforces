#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
// #include <algorithm>
#include <queue>

#define int long long
#define all(x) x.begin(), x.end()

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

void ct(vector<int> &a) {
	for(auto i: a)
		cout << i << ' ';
	cout << '\n';
}

void ct(pair<int, int> &a) {
	cout << a.first << ':' << a.second << ' ';
}

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		ct(i);
}

void ci(vector<int> &a) {
	for(auto &i: a)
		cin >> i;
}

void ci(vector<pair<int, int>> &a) {
	for(auto &i: a)
		cin >> i.first >> i.second;
}

int log2(long long a) {
	for(int i = 0; i < 31; ++i) {
		if (a <= (1 << i)) {
			return i;
		}
	}
}

void solve() {
	long long k, n;
	cin >> k >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		a[i] = log2(a[i]);
	}
	// ct(a);
	vector<int> kol(70);
	for(int i = 0; i < n; ++i) {
		kol[a[i]]++;
	}
	vector<int> used(70);
	int o = 0;
	for(int i = 0; i < 63; ++i) {
		if (((long long) ((long long) 1 << i)) & k) {
			// cout << i << ' ';
			++o;
			used[i]++;
		}
	}
	int ans = 0;
	for(int i = 0; i < 63; ++i) {
		if (used[i]) {
			for(int j = i; j < 63; ++j) {
				if (kol[j] != 0) {
					// cout << i << ' ' << j << ' ' << kol[j] << '\n';
					used[i]--;
					--o;
					// cout << o;
					kol[j]--;
					for(int u = j - 1; u >= i; --u) {
						kol[u]++;
					}
					ans += (j - i);
					break;
				}
			}
		}
		kol[i + 1] += kol[i] / 2;
		kol[i] = 0;
	}
	// cout << o << '\n';
	if (o == 0) 
		cout << ans << '\n';
	else 
		cout << -1 << '\n';
}

signed main() {
	setup();
	int t; cin >> t; for(int i = 0; i < t; ++i) solve();
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}