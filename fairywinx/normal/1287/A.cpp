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

void solve() {
	int n;
	cin >> n;
	string s;
	bool z = false;
	cin >> s;
	int len = 0;
	int ans = 0;
	for(auto i: s) {
		if (i == 'A') {
			z = true;
		}
		if (z == true && i == 'P')
			++len;
		else
			len = 0;
		ans = max(len, ans);
	}
	cout << ans << '\n';
}


signed main() {
	setup();
	
	SOLVE;
}