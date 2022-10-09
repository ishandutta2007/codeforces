#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <iomanip>
#include <string>
#include <ctime>

// #include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

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

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	if (abs(x1 - x2) == 0 && !(a == 0 && b == 0))
		cout << "No\n";
	else if (abs(y1 - y2) == 0 && !(c == 0 && d == 0))
		cout << "No\n";
	else if (x - x2 > (a - b))
		cout << "No\n";
	else if (x1 - x > (b - a))
		cout << "No\n";
	else if (y - y2 > (c - d))
		cout << "No\n";
	else if (y1 - y > (d - c))
		cout << "No\n";
	else
		cout << "Yes\n";
	// int n;
	// cin >> n;
	// vector<int> a(n);
	// for(int i = 0; i < n; ++i) 
	// 	cin >> a[i];


	// for(auto i: a)
	// 	cout << i << ' ';
}

signed main() {
	setup();
	SOLVE;


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}