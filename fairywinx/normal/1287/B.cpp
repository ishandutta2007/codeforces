#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <ctime>
#include <map>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define SOLVE int t; cin >> t; for(int i = 0; i < t; ++i) solve()
#define pb emplace_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

void ct(vector<int> &a) {
    for (auto &i: a) cout << i << ' ';
    cout << '\n';
}
 
void ci(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		cout << i.first << ':' << i.second << ' ';
	cout << '\n';
}

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif
	srand(time(NULL));
}


signed main() {
	setup();
	
	unordered_map<string, int> a;
	int n, k;
	cin >> n >> k;
	vector<string> c(n);
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		c[i] = s;
		if (!a.count(s))
			a[s] = 0;
		++a[s];
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			string s = "";
			for(int u = 0; u < k; ++u) {
				if (c[i][u] == c[j][u])
					s += c[j][u];
				else 
					s += 'S' + 'E' + 'T' - c[j][u] - c[i][u];
			}
			if (a.count(s))
				ans += a[s];
		}
	}
	cout << ans / 3;
}