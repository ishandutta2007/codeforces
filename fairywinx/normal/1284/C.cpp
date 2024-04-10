#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

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

#define int long long

void ct(vector<int> &a) {
    for (auto &i: a) cout << i << ' ';
    cout << '\n';
}

void ci(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
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
	//srand(time(NULL));
}

const int N = 25e4 + 228;

int fact[N];

signed main() {
	setup();
	//SOLVE;
	
	int n, m;
	cin >> n >> m;
	fact[0] = 1;
	for(int i = 1; i < N; ++i) {
		fact[i] = (fact[i - 1] * i) % m;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		//cout << fact[i] * fact[n - i] << ' ' << i << ' ' << (n - i + 1) << '\n';
		ans += ((fact[i] * fact[n - i]) % m) * (((n - i + 1) * (n - i + 1)) % m);
		ans = ans % m;
	}
	cout << ans;
}